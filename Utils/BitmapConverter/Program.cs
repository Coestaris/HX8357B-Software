using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;

namespace BitmapConverter
{
    public enum SizeMode
    {
        Stretch,
        Truncate
    }
    
    public static class Converter
    {
        public static string Name { get; set; }
        public static int W { get; set; }
        public static int H { get; set; }
        public static SizeMode SizeMode { get; set; }
        public static ColorMode ColorMode { get; set; }
        public static int Format_MaxBytes { get; set; }
        public static string BitmapName { get; set; }
        public static bool HFile { get; set; }

        public static void Convert()
        {
            if(!File.Exists(BitmapName))
            {
                Console.WriteLine("Unable to find file \"{0}\"\nPress any key to continue. . .", BitmapName);
                Console.ReadKey();
                Environment.Exit(1);
            }
            Console.Write("1. Loading data");

            BitmapColor[,] colors = new BitmapColor[W, H];

            using (ProgressBar pr = new ProgressBar())
            {
                int i = 1;

                Bitmap bmp;

                if(SizeMode == SizeMode.Stretch)
                    bmp = new Bitmap(new Bitmap(BitmapName), new Size(W, H));
                else
                {
                    bmp = new Bitmap(W, H);
                    using (Graphics gr = Graphics.FromImage(bmp))
                        gr.DrawImageUnscaled(new Bitmap(BitmapName), new Point(0, 0));
                }

                colors[0, 0] = BitmapColor.CreateColor(ColorMode, Color.Empty);

                if (colors[0, 0].ImagePreProcessingRequired)
                    colors[0, 0].PreProceed(ref bmp);

                for (int x = 0; x < W; x++)
                    for (int y = 0; y < H; y++)
                    {
                        colors[x, y] = BitmapColor.CreateColor(ColorMode, bmp.GetPixel(x, y));

                        float f = (i++) / (float)(W * H);
                        pr.Report(f > 1 ? 1 : f);
                    }
            }
            Console.WriteLine();

            Console.Write("2. Saving data");

            List<byte> result = new List<byte>();

            for (int x = 0; x < W; x++)
                for (int y = 0; y < H; y++)
                    result.AddRange(colors[x, y].ToBytes());

            //Я бы перегрузил статический метод, если это можно было бы делать.
            //Ждем, надеемся...
            if (colors[0, 0].BytesPostProcessingRequired)
                colors[0, 0].PostProceed(ref result);

            if (HFile)
            {
                StringBuilder sb = new StringBuilder();
                sb.Append(Writer.WriteHeader(Name, ColorMode, W, H));
                sb.Append(Writer.WriteData(result, Format_MaxBytes));
				sb.Append(Writer.WriteFooter(Name, W, H, ColorMode));
                File.WriteAllText(string.Format("bitmap_{0}.h", Name), sb.ToString());
            } else
            {
                result.InsertRange(0, BitConverter.GetBytes((short)H));
                result.InsertRange(0, BitConverter.GetBytes((short)W));
                result.Insert(0, (byte)ColorMode);
                File.WriteAllBytes(string.Format("bitmap_{0}.raw", Name), result.ToArray());
            }

            Bitmap bmp1 = new Bitmap(W, H);
            for (int x = 0; x < W; x++)
                for (int y = 0; y < H; y++)
                    bmp1.SetPixel(x, y, colors[x, y].ToRGB());
            bmp1.Save("result_in3.png");
        }
    }

    class Program
    {
        public static IEnumerable<T> CreateSequence<T>(Func<int, T> elementCreator, int count)
        {
            if (elementCreator == null)
                throw new ArgumentNullException("elementCreator");

            for (int i = 0; i < count; ++i)
                yield return (elementCreator(i));
        }

        public static Dictionary<string, object> arguments;

        public static string Find(string name, object defValue)
        {
            if (arguments.ContainsKey(name.ToLower()))
                return arguments[name.ToLower()].ToString();
            else return defValue.ToString();
        }

        static void Main(string[] args)
        {
            arguments = new Dictionary<string, object>();

            foreach (var item in args)
                arguments.Add(item.Split(':')[0].TrimStart('-').ToLower(), item.Split(':')[1]);

            Converter.Name = Find("name", "sheep");
            Converter.W = int.Parse(Find("W", 128));
            Converter.H = int.Parse(Find("H", 128));
            Converter.HFile = bool.Parse(Find("HFile", false));
            Converter.SizeMode = (SizeMode)Enum.Parse(typeof(SizeMode), Find("SizeMode", "Stretch"));
            Converter.ColorMode = (ColorMode)Enum.Parse(typeof(ColorMode), Find("ColorMode", "Binary"));
            Converter.BitmapName = Find("BitmapName", "image.png");
            Converter.Format_MaxBytes = int.Parse(Find("Format_MaxBytes", 10));

            Converter.Convert();

            //ToBitmap(File.ReadAllBytes("bitmap_sheep.raw").ToList());
        }

        static public void ToBitmap(List<byte> bytes)
        {
            ColorMode colorMode = (ColorMode)bytes[0];
            ushort W = BitConverter.ToUInt16(bytes.ToArray(), 1);
            ushort H = BitConverter.ToUInt16(bytes.ToArray(), 3);
            BitmapColor[,] colors = new BitmapColor[W, H];
            BitmapColor baseColor = BitmapColor.CreateColor(colorMode, Color.Empty);
            int counter = 0;


            if (colorMode == ColorMode.GrayScale_encoded)
            {
                List<bool> bits = new List<bool>();
                Encoder.Decode(bytes, 5, bytes.Count - 5, p => bits.Add(p));
                var decodeResult = CreateSequence(p =>
                {
                    byte b = 0;
                    for (int i = 0; i < 8; i++)
                        if (p * 8 + i < bits.Count)
                            BitWise.SSetBit(ref b, i, bits[p * 8 + i] ? 1 : 0);
                    return b;
                }, (int)Math.Ceiling(bits.Count / 8f)).ToList();

                bytes = new List<byte>();
                bytes.AddRange(new byte[5] { 0, 0, 0, 0, 0 });
                bytes.AddRange(decodeResult);
            }
            else if(colorMode == ColorMode.Binary_encoded)
            {
                List<bool> controlBits = new List<bool>();
                Encoder.Decode(bytes, 5, bytes.Count - 5, p => controlBits.Add(p));
                bytes = new List<byte>();
                bytes.AddRange(new byte[5] { 0, 0, 0, 0, 0 });
                bytes.AddRange(controlBits.Select(p => (byte)(p ? 1 : 0)));
            }
            else if (colorMode == ColorMode.Binary)
            {
                List<bool> controlBits = new List<bool>();

                for (int i = 5; i < bytes.Count; i++)
                    for (int b = 0; b < 8; b++)
                        controlBits.Add(BitWise.Bit(bytes[i], b) == 1);

                bytes = new List<byte>();
                bytes.AddRange(new byte[5] { 0, 0, 0, 0, 0 });
                bytes.AddRange(controlBits.Select(p => (byte)(p ? 1 : 0)));
            }

            for (int x = 0; x < W; x++)
                for (int y = 0; y < H; y++)
                {
                    colors[x, y] = BitmapColor.CreateColor(colorMode, Color.Empty);
                    colors[x, y].FromBytes(bytes.Skip(baseColor.BytesPerColor * counter + 5).Take(baseColor.BytesPerColor).ToArray());
                    counter++;
                }

            Bitmap bmp = new Bitmap(W, H);
                for (int x = 0; x < W; x++)
                   for (int y = 0; y < H; y++)
                    bmp.SetPixel(x, y, colors[x, y].ToRGB());

            bmp.Save("result_out3.png");
        }
    }
}
