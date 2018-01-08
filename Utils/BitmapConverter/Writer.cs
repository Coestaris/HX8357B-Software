using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BitmapConverter
{
    public static class Writer
    {
        private static string Normalize(string str, int a)
        {
            while (str.Length != a + 1)
                str += ' ';
            return str;
        }


        public static string WriteBytes(List<byte> bytes, int maxInRow)
        {
            string result = "";
            int i = 0;
            foreach (var item in bytes)
            {
                if (i++ % maxInRow == 0)
                    result += "\n    ";
                result += Normalize("0x" + item.ToString("x").ToUpper() + ", ", 5);
            }
            result += "\n\n";
            return result;
        }

        public static string WriteFooter(string name)
        {
            string result = "";
            result += "};\n\n";
            result += $"BITMAP_IFNO bitmap_{name}(void)\n";
            result += "{\n";
            result += "}\n\n";
            result += "#endif\n";
            return result;
        }

        public static string WriteData(List<byte> bytes, int maxInRow)
        {
            string result = "";
            result += $"    //Total size: {bytes.Count}";
            result += WriteBytes(bytes, maxInRow);
            return result;
        }

        public static string WriteHeader(string name, ColorMode mode, int W, int H)
        {
            string result = "";
            result += $"#ifndef _bitmap_{name}_h_\n";
            result += $"#define _bitmap_{name}_h_\n\n";
            result += "#include \"../bitmapinfo.h\"\n\n";
            result += $"const PROGMEM uint8_t bitmap_{name}_data[] = \n{{\n";
            result += $"    //Color model: {mode.ToString()}";
            if (mode == ColorMode.Default)
                result += $" ({ColorMode.Color_565})";
            result += $"\n    //Bitmap size {W} x {H}\n";
            result += $"    {"0x" + ((byte)mode).ToString("x").ToUpper()}, ";

            var bytes = BitConverter.GetBytes((short)W);
            result += $"{"0x" + (bytes[0]).ToString("x").ToUpper()}, ";
            result += $"{"0x" + (bytes[1]).ToString("x").ToUpper()}, ";

            bytes = BitConverter.GetBytes((short)H);
            result += $"{"0x" + (bytes[0]).ToString("x").ToUpper()}, ";
            result += $"{"0x" + (bytes[1]).ToString("x").ToUpper()},\n\n";

            return result;
        }
    }
}
