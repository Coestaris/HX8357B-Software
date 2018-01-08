using System;
using System.Drawing;

namespace BitmapConverter
{
    public class Color565 : BitmapColor
    {
        public override ColorMode Mode => ColorMode.Color_565;
        public override int BytesPerColor => 2;

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
            return Color.FromArgb(
                (byte)Math.Ceiling(R * 255 / 31f),
                (byte)Math.Ceiling(G * 255 / 63f),
                (byte)Math.Ceiling(B * 255 / 31f));
        }

        public override void FromRGB(byte r, byte g, byte b)
        {
            R = (byte)Math.Ceiling((31 * r) / 255f);
            G = (byte)Math.Ceiling((63 * g) / 255f);
            B = (byte)Math.Ceiling((31 * b) / 255f);
        }

        public override void FromBytes(byte[] bytes)
        {
            UInt16 color = BitConverter.ToUInt16(bytes, 0);
            R = (byte)((color & 0xF800) >> 11);
            G = (byte)((color & 0x7E0) >> 5);
            B = (byte) (color & 0x1F);
        }
    }
}
