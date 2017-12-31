using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BitmapConverter
{
    public enum SizeMode
    {
        Stretch,
        Truncate
    }

    public static class Converter
    {
        public static UInt16 To656Color(byte red, byte green, byte blue)
        {
            return (UInt16)((((31 * (red + 4)) / 255) << 11) | (((63 * (green + 2)) / 255) << 5) | ((31 * (blue + 4)) / 255));

        }

        public static string Name { get; set; }
        public static int W { get; set; }
        public static int H { get; set; }
        public static SizeMode SizeMode { get; set; }


        public static void Convert(string name)
        {

        }
    }

    class Program
    {
        static void Main(string[] args)
        {

        }
    }
}
