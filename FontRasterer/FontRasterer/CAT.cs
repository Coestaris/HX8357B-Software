using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FontRasterer
{
    public class CATEl
    {
        public char Char;
        public bool IsUnrec;
        public int Index;

        public List<byte> Bytes;

        public float EncodingCompressionRatio;

        public CATEl(char @char, bool isUnrec, List<byte> bytes, int index)
        {
            Char = @char;
            IsUnrec = isUnrec;
            Index = index;
            Bytes = bytes;
            EncodingCompressionRatio = float.NegativeInfinity;
        }

        public void Encode()
        {
            int before = Bytes.Count;
            var newBytes = Encoder.Encode(Bytes, 0, Bytes.Count);
			      EncodingCompressionRatio = 1 - newBytes.Count / (float)before;

            if(EncodingCompressionRatio > 0)
              Bytes = newBytes;
            else EncodingCompressionRatio = float.NegativeInfinity;
        }

        public override string ToString()
        {
            if (IsUnrec)
				return $"    //Symbol for unrecognised chars.{(!float.IsInfinity(EncodingCompressionRatio) ? " CR: " + (EncodingCompressionRatio * 100).ToString("0.00") + '%': ". Skipping compression")}";
			else return $"    //Symbol: {(int)Char} {(!char.IsControl(Char) ? $" or '{Char}'" : "")}. Symbol Index: {Index}{(!float.IsInfinity(EncodingCompressionRatio) ? ". CR: " + (EncodingCompressionRatio * 100).ToString("0.00") + '%' : ". Skipping compression")}";
        }
    }

    public class CATHeaderEl
    {
        public UInt16 Offset;
        public UInt16 Length;
        public bool EncodeSymbol;

        public CATHeaderEl(ushort offset, ushort length, bool encodeSymbol)
        {
            EncodeSymbol = encodeSymbol;
            Offset = offset;
            Length = length;
        }

        public List<byte> ToBytes()
        {
            List<byte> result = new List<byte>();
            result.AddRange(BitConverter.GetBytes(Offset));

            var len = Length;
            if(EncodeSymbol)
                BitWise.SetBit(ref len, 15);
            else BitWise.ClearBit(ref len, 15);

			result.AddRange(BitConverter.GetBytes(len));
            return result;
        }
    }

    public class FontData
    {
        public List<CATEl> Elems { get; set; }
        public float AverageCompressionRatio { get; private set; }

        public List<CATHeaderEl> HeaderElems { get; set; }
        public byte MaxXSize { get; set; }
        public byte MaxYSize { get; set; }
        public byte MinChar { get; set; }
        public byte MaxChar { get; set; }

        public void CreateHeader()
        {
            int offset = Elems.Count * 4 + 4;
            for(int i = 0; i < Elems.Count; i++)
            {
                HeaderElems.Add(new CATHeaderEl((UInt16)offset, (UInt16)Elems[i].Bytes.Count,
								!float.IsInfinity(Elems[i].EncodingCompressionRatio)));
                offset += Elems[i].Bytes.Count;
            }
        }

        public void Encode()
        {
            for(int i = 0; i < Elems.Count; i++)
                Elems[i].Encode();
			AverageCompressionRatio = Program.CreateSequence(p => (float.IsInfinity(Elems[p].EncodingCompressionRatio) ? 0 : Elems[p].EncodingCompressionRatio),
                Elems.Count).Average();
        }

        public FontData()
        {
            HeaderElems = new List<CATHeaderEl>();
            Elems = new List<CATEl>();
        }

        public List<byte> HeaderToBytes()
        {
            List<byte> result = new List<byte>();
            foreach (var item in HeaderElems)
                result.AddRange(item.ToBytes());
            return result;
        }
    }
}
