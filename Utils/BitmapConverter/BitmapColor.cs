using System;
using System.Collections.Generic;
using System.Drawing;

namespace BitmapConverter
{
    public abstract class BitmapColor
    {
        public virtual byte R { get; set; }

        public virtual byte G { get; set; }

        public virtual byte B { get; set; }


        public abstract ColorMode Mode { get; }

        public abstract int BytesPerColor { get; }

        public abstract void FromRGB(byte r, byte g, byte b);

        public abstract byte ToByte();

        public abstract void FromBytes(byte[] bytes);

        public abstract byte[] ToBytes();

        public abstract Color ToRGB();


        public virtual bool BytesPostProcessingRequired => false;

        public virtual bool ImagePreProcessingRequired => false;

        public virtual void FromRGB(Color color) { FromRGB(color.R, color.G, color.B); }

        public virtual void PostProceed(ref List<byte> result)
        {
            throw new NotImplementedException();
        }
        
        public virtual void PreProceed(ref Bitmap bitmap)
        {
            throw new NotImplementedException();
        }


        public BitmapColor(Color color)
        {
            FromRGB(color.R, color.G, color.B);
        }

        public BitmapColor(byte r, byte g, byte b)
        {
            FromRGB(r, g, b);
        }


        public override string ToString()
        {
            return string.Format("Color[Mode: {3}, (R: {0}, G: {1}, B: {2})]", R, G, B, Mode);
        }

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
                    return new Color555(color);
                case ColorMode.Color_332:
                    return new Color332(color);
                case ColorMode.GrayScale:
                    return new ColorGrayscale(color);
                case ColorMode.GrayScale_encoded:
                    return new ColorGrayscaleEncoded(color);
                case ColorMode.Binary:
                    return new ColorBinary(color);
                case ColorMode.Binary_encoded:
                    return new ColorBinaryEncoded(color);
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
    }
}
