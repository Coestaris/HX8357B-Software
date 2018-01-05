using System;
using System.Collections.Generic;
using System.Linq;

namespace FontRasterer
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
                result += Normalize("0x" + item.ToString("x").ToUpper(), 3) + ", ";
            }
            result += "\n\n";
            return result;
        }

        public static string WriteHeader(string name)
        {
            string result = "";
            result += $"#ifndef _font_{name}_h_\n";
            result += $"#define _font_{name}_h_\n\n";
            result += "#include \"../fontinfo.h\"\n\n";
            result += $"const PROGMEM  uint8_t font_{name}_data[] = \n{{\n";
            return result;
        }

        public static string WriteDataHeader(byte maxXSize, byte maxYSize, byte minChar, byte maxChar, 
            bool useEncoding, float AverageCompressionRatio, int len, FontData data)
        {
            string result = "";
            result += $"    //Font Info. Symbol X size: {maxXSize}, Symbol Y size: {maxYSize}";
            result += $"\n    //Stars from: {minChar} {(!char.IsControl((char)minChar) ? "or '" + (char)minChar + "' " : "")},";
            result += $" Ends with: {maxChar} {(!char.IsControl((char)maxChar) ? "or '" + (char)maxChar + "' " : "")}\n";

            var totalSize = 0;

            if (useEncoding)
            {
                totalSize += data.HeaderElems.Last().Offset + data.HeaderElems.Last().Length;
            } else
                totalSize = (int)Math.Ceiling(maxXSize * maxYSize / 8.0) * len + 4;

            result += $"    //Total size: {totalSize} bytes";
            if(useEncoding)
                result += $"\n    //Using RLE compression:" +
                    $"\n    //    Data Compression Ratio:  {AverageCompressionRatio}" +
                    $"\n    //    Total Compression Ratio: {1 - totalSize / ((float)Math.Ceiling(maxXSize * maxYSize / 8.0) * len + 4)}";
            result += $"    ";
            result += WriteBytes(new List<byte> { maxXSize, maxYSize, minChar, maxChar }, 10);
            return result;
        }

        public static string WriteFooter(string name, int Width, int Height, byte minChar, byte maxChar, bool useEncoding)
        {
            string result = "";
            result += "};\n\n";
            result += $"FONT_INFO font_{name}(void)\n";
            result += "{\n";
            result += "    FONT_INFO header;\n";
            result += $"    header.data = (uint16_t)font_{name}_data;\n";
            result += $"    header.encoded = {(useEncoding? '1' : '0')};\n";
            result += $"    header.maxXSize = {Width};\n";
            result += $"    header.maxYSize = {Height};\n";
            result += $"    header.startChar = {maxChar};\n";
            result += $"    header.endChar = {minChar};\n";
            result += "    header.bytesPerSymbol = (uint16_t)ceil(header.maxXSize * header.maxYSize / 8.0);\n";
            result += "    header.color = cl_WHITE;\n";
            result += "    header.bgColor = cl_BLACK;\n";
            result += "    return header;\n";
            result += "}\n\n";
            result += "#endif\n";
            return result;
        }

        public static string WriteCAT(FontData data, int maxInRow)
        {
            string result = "";
            var bytes = data.HeaderToBytes();
            result += $"    //CAT Header. Length: {bytes.Count}";
            result += WriteBytes(bytes, maxInRow);
            result += "\n";
            return result;
        }

        public static string WriteSymbolData(CATEl elem, int maxInRow)
        {
            string result = "";
            result += elem.ToString();
            result += WriteBytes(elem.Bytes, maxInRow);
            return result;
        }
    }
}
