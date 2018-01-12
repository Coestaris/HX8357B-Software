using System;
using System.Drawing;

namespace BitmapConverter
{
    class Color332 : BitmapColor
    {
        public Color332(Color color) : base(color) { }
        public Color332(byte r, byte g, byte b) : base(r, g, b) { }

        public override ColorMode Mode => ColorMode.Color_332;
        public override int BytesPerColor => 1;

        public override void FromBytes(byte[] bytes)
        {
            byte color = bytes[0];
			R = (byte)((color & 0xE0) >> 5);
			G = (byte)((color & 0x1C) >> 2);
            B = (byte)(color &  0x3);
        }

        public override void FromRGB(byte r, byte g, byte b)
        {
            R = (byte)Math.Ceiling((7 * r) / 255f);
            G = (byte)Math.Ceiling((7 * g) / 255f);
            B = (byte)Math.Ceiling((3 * b) / 255f);
        }

        public override byte ToByte()
        {
            return (byte)((R << 5) | (G << 2) | B);
        }

        public override byte[] ToBytes()
        {
            return new byte[] { ToByte() };
        }

        public override Color ToRGB()
        {
            return Color.FromArgb(
                (byte)Math.Ceiling(R * 255 / 7f),
                (byte)Math.Ceiling(G * 255 / 7f),
                (byte)Math.Ceiling(B * 255 / 3f));
        }
    }
}
