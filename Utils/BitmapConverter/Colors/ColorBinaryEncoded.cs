using System.Collections.Generic;
using System.Drawing;

namespace BitmapConverter
{
    public class ColorBinaryEncoded : ColorBinary
    {
        public ColorBinaryEncoded(Color color) : base(color) { }
        public ColorBinaryEncoded(byte r, byte g, byte b) : base(r, g, b) { }

        public override void PostProceed(ref List<byte> result)
        {
            base.PostProceed(ref result);
            result = Encoder.Encode(result, 0, result.Count);
        }
    }
}
