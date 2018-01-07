using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BitmapConverter
{
    /// <summary>
    /// RGB color mode
    /// </summary>
    public enum ColorMode
    {
        Color_565 = 0x1,  //16bit 
        Color_555 = 0x2,  //16bit, last bit empty
        Color_332 = 0x4,  //8bit 
        GrayScale = 0x8,  //8bit, grayscale
        Binary    = 0x10, //1bit
        Default   = 0x20  // = Color_565
    }

    public abstract class BitmapColor
    {
        public virtual byte R { get; set; }
        public virtual byte G { get; set; }
        public virtual byte B { get; set; }

        public static BitmapColor CreateColor(ColorMode mode, byte r, byte g,  byte b)
        {
            return CreateColor(mode, Color.FromArgb(r, g, b));
        }

        public static BitmapColor CreateColor(ColorMode mode, Color color)
        {
            switch (mode)
            {
                case ColorMode.Color_565:
                    return new Color565(color);
                case ColorMode.Color_555:
                    return null;
                case ColorMode.Color_332:
                    return null;
                case ColorMode.GrayScale:
                    return null;
                case ColorMode.Binary:
                    return null;
                case ColorMode.Default:
                default:
                    return new Color565(color);
            }
        }

        public static T Convert<T>(BitmapColor color) where T : BitmapColor, new()
        {
            var newColor = new T();
            newColor.FromRGB(color.ToRGB());
            return newColor;
        }

        public void FromRGB(Color color) { FromRGB(color.R, color.G, color.B); }
        public virtual void FromRGB(byte r, byte g, byte b) { }
        public virtual Color ToRGB() { return Color.Empty; }

        public virtual ColorMode Mode() { return ColorMode.Default; }

        public BitmapColor(Color color)
        {
            FromRGB(color.R, color.G, color.B);
        }

        public BitmapColor(byte r, byte g, byte b)
        {
            FromRGB(r, g, b);
        }

        public virtual byte ToByte() { return 0; }
        public virtual byte[] ToBytes() { return null; }

        public override string ToString()
        {
            return string.Format("Color[Mode: {3}, (R: {0}, G: {1}, B: {2})]", R, G, B, Mode());
        }
    }

    public class Color565 : BitmapColor
    {
        public override ColorMode Mode()
        {
            return ColorMode.Color_565;
        }

        public Color565(Color color) : base(color) { }
        public Color565(byte r, byte g, byte b) : base(r, g, b) { }

        public override byte ToByte()
        {
            throw new NotSupportedException("Невозможно преобразовать данный цвет в один байт");
        }

        public override byte[] ToBytes()
        {
            UInt16 color = (UInt16)((R << 11) | (G << 5) | B);
            return BitConverter.GetBytes(color);
        }

        public override Color ToRGB()
        {
            return Color.FromArgb(R * 255 / 31, G * 255 / 63, B * 255 / 31);
        }

        public override void FromRGB(byte r, byte g, byte b)
        {
            R = (byte)Math.Ceiling((31 * r) / 255f);
            G = (byte)Math.Ceiling((63 * g) / 255f);
            B = (byte)Math.Ceiling((31 * b) / 255f);
        }
    }
}
