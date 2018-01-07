using System.Drawing;

namespace BitmapConverter
{
    public class ColorGrayscale : BitmapColor
    {
        private const float RCoef = 0.299f; //0.2126f
        private const float GCoef = 0.587f; //0.7152f
        private const float BCoef = 0.114f; //0.0722f

        public byte Value { get; private set; }

        public override int BytesPerColor => 1;
        public override byte R { get => Value; }
        public override byte G { get => Value; }
        public override byte B { get => Value; }

        public override ColorMode Mode => ColorMode.GrayScale;

        public ColorGrayscale(Color color) : base(color) { }
        public ColorGrayscale(byte r, byte g, byte b) : base(r, g, b) { }

        public override byte[] ToBytes()
        {
            return new byte[] { ToByte() };
        }

        public override Color ToRGB()
        {
            return Color.FromArgb(Value, Value, Value);
        }

        public override void FromRGB(byte r, byte g, byte b)
        {
            Value = (byte)(RCoef * r + GCoef * g + BCoef * b);
        }

        public override byte ToByte()
        {
            return Value;
        }

        public override void FromBytes(byte[] bytes)
        {
            Value = bytes[0];
        }
    }
}
