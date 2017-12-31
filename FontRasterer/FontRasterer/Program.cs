using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.IO;
using System.Linq;

namespace FontRasterer
{
    public static class Rasterizer
    {
        public static string name = "std";

        public static int W { get; set; } = 100;
        public static int H { get; set; } = 100;
        public static float FSize { get; set; } = 16;
        public static int Format_MaxBytes { get; set; } = 10;
        public static int MinChar { get; set; } = 0x21;
        public static int MaxChar { get; set; } = 161;
        public static int EmptyCharIndex { get; set; } = 0x3F;
        //public static string Font { get; set; } = "DisposableDroid BB";
        public static string Font { get; set; } = "Courier";
        //public static string OutputName { get; set; } = "output1.h";
        public static bool SaveImages { get; set; } = true;
        public static string OutputImagesFormat { get; set; } = "rbmp{0}.png";
        public static bool SaveTotalImage { get; set; } = true;
        public static bool TotalImageBorders { get; set; } = true;
        public static string OutputTotalImageFormat { get; set; } = "img/_img_.png";
        public static int TotalImagePerRow { get; set; } = 20;

        public static IEnumerable<T> CreateSequence<T>(Func<int, T> elementCreator, int count)
        {
            if (elementCreator == null)
                throw new ArgumentNullException("elementCreator");

            for (int i = 0; i < count; ++i)
                yield return (elementCreator(i));
        }

        public static void Save()
        {
            string OutputName = string.Format("font_{0}.h", name);
            var files =
                CreateSequence(p => "rbmp" + (p++).ToString() + ".png", Directory.GetFiles(Environment.CurrentDirectory, OutputImagesFormat.Replace("{0}", "*")).Length)
                .ToArray();


            var bmps = new Bitmap[files.Length];
            for (int i = 0; i < files.Length; i++)
            {
                bmps[i] = new Bitmap(files[i]);
            };
            var maxXSize = bmps[0].Width;
            var maxYSize = bmps[0].Height;

            List<byte> list = new List<byte>
            {
                (byte)maxXSize,
                (byte)maxYSize,
                (byte)MinChar,
                (byte)MaxChar
            };
            Console.WriteLine("Done");
            Console.Write("3. Writing...   ");
            //Console.WriteLine("...Creating output file...");
            string result = "";
            result += $"#ifndef _font_{name}_h_\n";
            result += $"#define _font_{name}_h_\n\n";
            result += "#include \"../fontinfo.h\"\n\n";
            result += $"const PROGMEM  uint8_t font_{name}_data[] = \n{{\n";
            result += $"    //Font Info. Symbol X size: {maxXSize}, Symbol Y size: {maxYSize}\n    //Stars from: {MinChar}, Ends with: {MaxChar}\n    //Total size: {Math.Ceiling(maxXSize * maxYSize / 8.0) * bmps.Length} bytes\n    ";
            foreach (var item in list)
                result += "0x" + item.ToString("x").ToUpper() + ", ";
            result += "\n\n";

            using (var progress = new ProgressBar())
            {
                {
                    result += $"    //Symbol for unrecognised chars. ";
                    byte[] bytes = new byte[(int)Math.Ceiling(maxXSize * maxYSize / 8.0)];
                    int currBit = 0;

                    for (int y = 0; y < bmps[MinChar + EmptyCharIndex].Height; y++)
                        for (int x = 0; x < bmps[MinChar + EmptyCharIndex].Width; x++)
                        {
                            var col = bmps[MinChar + EmptyCharIndex].GetPixel(x, y);
                            if (col.G == 0)
                                bytes[currBit / 8] |= (byte)(1UL << (byte)(currBit % 8));
                            currBit++;
                        }
                    currBit = 0;
                    foreach (var item in bytes)
                    {
                        if (currBit++ % Format_MaxBytes == 0)
                            result += "\n    ";
                        result += "0x" + item.ToString("x").ToUpper() + ", ";
                    }
                    result += "\n\n";
                    list.AddRange(bytes);
                }

                for (int i = 0; i <= bmps.Length - 1; i++)
                {
                    result += $"    //Symbol: {i + MinChar} {(!char.IsControl((char)(i + MinChar)) ? $" or '{(char)(i + MinChar)}'" : "")}. Symbol Index: {i}";

                    byte[] bytes = new byte[(int)Math.Ceiling(maxXSize * maxYSize / 8.0)];
                    int currBit = 0;

                    for (int y = 0; y < bmps[i].Height; y++)
                        for (int x = 0; x < bmps[i].Width; x++)
                        {
                            var col = bmps[i].GetPixel(x, y);
                            if (col.G == 0)
                                bytes[currBit / 8] |= (byte)(1UL << (byte)(currBit % 8));
                            currBit++;
                        }
                    currBit = 0;
                    //Console.WriteLine($"[{i}/{bmps.Length}]");
                    progress.Report(i / (double)bmps.Length);
                    //char.IsSymbol(i + minChar);
                    foreach (var item in bytes)
                    {
                        if (currBit++ % Format_MaxBytes == 0)
                            result += "\n    ";
                        result += "0x" + item.ToString("x").ToUpper() + ", ";
                    }
                    result += "\n\n";


                    list.AddRange(bytes);
                }
                result += "};\n\n";

                result += $"FONT_INFO font_{name}(void)\n";
                result += "{\n";
                result += "    FONT_INFO header;\n";
                result +=$"    header.data = (uint16_t)font_{name}_data;\n";
                result += "    header.maxXSize = pgm_read_byte_near(header.data);\n";
                result += "    header.maxYSize = pgm_read_byte_near(header.data + 1);\n";
                result += "    header.startChar = pgm_read_byte_near(header.data + 2);\n";
                result += "    header.endChar = pgm_read_byte_near(header.data + 3);\n";
                result += "    header.bytesPerSymbol = (uint16_t)ceil(header.maxXSize * header.maxYSize / 8.0);\n";
                result += "    header.color = TFT_BLUE;\n";
                result += "    return header;\n";
                result += "}\n\n";


                result += "#endif";
                if (SaveTotalImage)
                {
                    Bitmap total = new Bitmap(maxXSize * TotalImagePerRow, maxYSize * (int)Math.Ceiling(bmps.Length / (float)TotalImagePerRow));
                    using (Graphics gr = Graphics.FromImage(total))
                    {
                        for (int i = 0; i <= bmps.Length - 1; i++)
                            gr.DrawImage(bmps[i], new Point(maxXSize * (i % TotalImagePerRow), maxYSize * (i / TotalImagePerRow)));
                        if (TotalImageBorders)
                        {
                            for (int i = 0; i < TotalImagePerRow; i++)
                                gr.DrawLine(Pens.Gray, i * maxXSize, 0, i * maxXSize, total.Height);

                            for (int i = 0; i < (int)Math.Ceiling(bmps.Length / (float)TotalImagePerRow); i++)
                                gr.DrawLine(Pens.Gray, 0, i * maxYSize, total.Width, i * maxYSize);
                        }
                    }

					if(Directory.Exists(OutputTotalImageFormat.Split('/')[0]))
						Directory.CreateDirectory(OutputTotalImageFormat.Split('/')[0]);

                    total.Save(OutputTotalImageFormat);
                }
                File.WriteAllText(OutputName, result);
            }
        }

        public static void Rasterize()
        {
            string OutputName = string.Format("font_{0}.h", name);
            Bitmap[] bmps = new Bitmap[MaxChar - MinChar];
            Console.Write("1. Rendering... ");
            using (var progress = new ProgressBar()) for (int m = MinChar; m < MaxChar; m++)
            {
                progress.Report(m / (double)(MaxChar - MinChar));
                var bitmap = new Bitmap(W, H);
                var path = new GraphicsPath();
                bool[,] colors = new bool[W, H];
                System.Drawing.Font ff = new System.Drawing.Font(new FontFamily(Font), FSize, FontStyle.Regular);
                using (Graphics gr = Graphics.FromImage(bitmap))
                {
                    gr.TextRenderingHint = System.Drawing.Text.TextRenderingHint.AntiAlias;
                    gr.InterpolationMode = InterpolationMode.HighQualityBicubic;
                    gr.PixelOffsetMode = PixelOffsetMode.HighQuality;
                    gr.DrawString(((char)m).ToString(), ff, Brushes.Black, new RectangleF(0, 0, W, H));
                }

                int minx = int.MaxValue;
                int miny = int.MaxValue;
                int maxx = 0;
                int maxy = 0;
                bool founded = false;

                for (int i = 1; i < bitmap.Width; i++)
                    for (int j = 1; j < bitmap.Height; j++)
                    {
                        var col = bitmap.GetPixel(i, j);
                        if (col.R != 0 ||
                           col.B != 0 ||
                           col.A != 0 ||
                           col.G != 0)
                        {
                            minx = Math.Min(minx, i);
                            miny = Math.Min(miny, j);
                            maxx = Math.Max(maxx, i);
                            maxy = Math.Max(maxy, j);
                            colors[i, j] = true;
                            founded = true;
                        }
                    }
                if (!founded)
                    continue;

                var rBmp = new Bitmap(maxx - minx + 1, maxy - miny + 1);
                for (int i = minx; i < maxx + 1; i++)
                    for (int j = miny; j < maxy + 1; j++)
                        rBmp.SetPixel(i - minx, j - miny, colors[i, j] ? Color.Black : Color.FromArgb(0, 0, 0, 0));

                bmps[m - MinChar] = rBmp;
            }

            int maxXSize = 0;
            int maxYSize = 0;
            Console.WriteLine("Done");
            Console.Write("2. Preparing... ");
            using (var progress = new ProgressBar())
            {
                for (int i = 0; i <= bmps.Length - 1; i++)
                {
                    if (bmps[i] == null)
                        continue;
                    maxXSize = Math.Max(maxXSize, bmps[i].Width);
                    maxYSize = Math.Max(maxYSize, bmps[i].Height);
                    progress.Report(i / (bmps.Length / 2.0));
                }

                for (int i = 0; i <= bmps.Length - 1; i++)
                {
                    if (bmps[i] == null)
                    {
                        Bitmap bmp_ = new Bitmap(maxXSize, maxYSize);
                        using (Graphics gr = Graphics.FromImage(bmp_))
                            gr.FillRectangle(Brushes.White, 0, 0, maxXSize, maxYSize);
                        bmps[i] = bmp_;
                        bmp_.Save($"rbmp{i}.png");
                        continue;
                    }

                    Bitmap bmp = new Bitmap(maxXSize, maxYSize);
                    using (Graphics gr = Graphics.FromImage(bmp))
                    {
                        gr.FillRectangle(Brushes.White, 0, 0, maxXSize, maxYSize);
                        gr.DrawImage(bmps[i], new PointF((maxXSize - bmps[i].Width) / 2,
                                                         (maxYSize - bmps[i].Height) / 2));
                    }
                    progress.Report(0.5 + i / (bmps.Length / 2.0));
                    if (SaveImages)
                        bmps[i].Save(string.Format(OutputImagesFormat, i));
                    bmps[i] = bmp;

                }
            }
        }

        static int st(int y, int max)
        {
            y += max / 2 - 1;
            if (y >= max)
                return y - max;
            return y;
        }
    }

	class Program
    {

		public static string Found(string name, object defValue)
		{
			if(arguments.ContainsKey(name.ToLower()))
				return arguments[name].ToString();
			else return defValue.ToString();
		}

		public static Dictionary<string, object> arguments;

        static void Main(string[] args)
        {
			arguments = new Dictionary<string, object>();

			foreach (var item in args)
			{
				arguments.Add(item.Split(':')[0].TrimStart('-').ToLower(), item.Split(':')[1]);
			}

			foreach (var item in arguments)
				Console.WriteLine(item.ToString());

			Rasterizer.name = Found("name", "std");
			Rasterizer.W = int.Parse(Found("W", 100));
			Rasterizer.H = int.Parse(Found("H", 100));
			Rasterizer.FSize = float.Parse(Found("FSize", 16));
			Rasterizer.Format_MaxBytes = int.Parse(Found("Format_MaxBytes", 10));
			Rasterizer.MinChar = int.Parse(Found("MinChar", 33));
			Rasterizer.MaxChar = int.Parse(Found("MaxChar", 161));
			Rasterizer.EmptyCharIndex = int.Parse(Found("EmptyCharIndex", 63));
			Rasterizer.Font = Found("Font", "Courier");
			Rasterizer.SaveImages = bool.Parse(Found("SaveImages", true));
			Rasterizer.OutputImagesFormat = Found("OutputImagesFormat", "rbmp{0}.png");
			Rasterizer.SaveTotalImage = bool.Parse(Found("SaveTotalImage", true));
			Rasterizer.TotalImageBorders = bool.Parse(Found("TotalImageBorders", true));
			Rasterizer.OutputTotalImageFormat = Found("OutputTotalImageFormat", "img/_img_.png");
			Rasterizer.TotalImagePerRow = int.Parse(Found("TotalImagePerRow", 20));

			int mode = int.Parse(Found("mode", 0));

			switch(mode)
			{
				case 0:
					Rasterizer.Save();
					break;
				case 1:
					Rasterizer.Rasterize();
					break;

			}
			Console.WriteLine();
        }
    }
}
