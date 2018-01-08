using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;

namespace BitmapConverter
{
    public class ColorBinary : BitmapColor
    {
        private const float RCoef = 0.299f; //0.2126f
        private const float GCoef = 0.587f; //0.7152f
        private const float BCoef = 0.114f; //0.0722f

        private float _avValue;

        public bool Value { get; set; }

        public override byte R => (byte)(Value ? 255 : 0); 
        public override byte G => (byte)(Value ? 255 : 0); 
        public override byte B => (byte)(Value ? 255 : 0); 
                
        public override ColorMode Mode => ColorMode.Binary;
        public override bool BytesPostProcessingRequired => true;
        public override bool ImagePreProcessingRequired => true;
        public override int BytesPerColor => 1;

        public ColorBinary(Color color) : base(color) { }
        public ColorBinary(byte r, byte g, byte b) : base(r, g, b) { }

        public override Color ToRGB()
        {
            return Color.FromArgb(R, G, B);
        }

        public override void FromRGB(byte r, byte g, byte b)
        {
            Value = RCoef * r + GCoef * g + BCoef * b > _avValue;
        }

        public override byte ToByte()
        {
            return (byte)(Value ? 1 : 0);
        }

        public override byte[] ToBytes()
        {
            return new byte[] { ToByte() };
        }

        public override void PreProceed(ref Bitmap bitmap)
        {
            Bitmap copy = (Bitmap)bitmap.Clone();
            _avValue = Program.CreateSequence(p =>
            {
                var color = copy.GetPixel(p / copy.Width, p % copy.Width);
                return (RCoef * color.R + GCoef * color.G + BCoef * color.B);
            }
            , bitmap.Width * bitmap.Height).Average();
        }

        public override void PostProceed(ref List<byte> result)
        {
            List<byte> copy = new List<byte>();
            copy.AddRange(result);
            int bitCount = 0;
            result = Program.CreateSequence(p =>
            {
                byte b = 0;
                for (int bit = 0; bit < 8; bit++)
                    if(bitCount < copy.Count)
                        BitWise.SSetBit(ref b, bit, copy[bitCount++]);
                return b;
            }, (int)Math.Ceiling(result.Count / 8f)).ToList();
        }

        public override void FromBytes(byte[] bytes)
        {
            Value = bytes[0] == 1;
        }
    }
}
