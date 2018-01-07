using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
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

            StringBuilder sb = new StringBuilder();
            sb.Append(Writer.WriteHeader(Name, ColorMode, W, H));
            sb.Append(Writer.WriteData(result, Format_MaxBytes));
            sb.Append(Writer.WriteFooter(Name));

            File.WriteAllText(string.Format("bitmap_{0}.h", Name), sb.ToString());
        }
    }

    class Program
    {
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
            Converter.W = int.Parse(Find("W", 32));
            Converter.H = int.Parse(Find("H", 32));
            Converter.SizeMode = (SizeMode)Enum.Parse(typeof(SizeMode), Find("SizeMode", "Stretch"));
            Converter.ColorMode = (ColorMode)Enum.Parse(typeof(ColorMode), Find("ColorMode", "Default"));
            Converter.BitmapName = Find("BitmapName", "image.jpg");
            Converter.Format_MaxBytes = int.Parse(Find("Format_MaxBytes", 10)); 
            Converter.Convert();
        }
    }
}
