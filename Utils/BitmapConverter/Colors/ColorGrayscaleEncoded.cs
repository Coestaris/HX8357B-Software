using System.Collections.Generic;
using System.Drawing;

namespace BitmapConverter
{
    public class ColorGrayscaleEncoded : ColorGrayscale
    {
        public override bool BytesPostProcessingRequired => true;

        public override void PostProceed(ref List<byte> result)
        {
            result = Encoder.Encode(result, 0, result.Count);
        }

        public ColorGrayscaleEncoded(Color color) : base(color) { }
        public ColorGrayscaleEncoded(byte r, byte g, byte b) : base(r, g, b) { }
    }
}
