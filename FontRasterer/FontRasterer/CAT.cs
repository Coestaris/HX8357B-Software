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
            Bytes = Encoder.Encode(Bytes, 0, Bytes.Count);
            EncodingCompressionRatio = 1 - Bytes.Count / (float)before;
        }

        public override string ToString()
        {
            if (IsUnrec)
                return $"    //Symbol for unrecognised chars.{(!float.IsInfinity(EncodingCompressionRatio) ? ". CR: " + EncodingCompressionRatio.ToString("0.00") : "")}";
            else return $"    //Symbol: {(int)Char} {(!char.IsControl(Char) ? $" or '{Char}'" : "")}. Symbol Index: {Index}{(!float.IsInfinity(EncodingCompressionRatio) ? ". CR: " + EncodingCompressionRatio.ToString("0.00") : "")}";
        }
    }

    public class CATHeaderEl
    {
        public UInt16 Offset;
        public UInt16 Length;

        public CATHeaderEl(ushort offset, ushort length)
        {
            Offset = offset;
            Length = length;
        }

        public List<byte> ToBytes()
        {
            List<byte> result = new List<byte>();
            result.AddRange(BitConverter.GetBytes(Offset));
            result.AddRange(BitConverter.GetBytes(Length));
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
                HeaderElems.Add(new CATHeaderEl((UInt16)offset, (UInt16)Elems[i].Bytes.Count));
                offset += Elems[i].Bytes.Count;
            }
        }

        public void Encode()
        {
            for(int i = 0; i < Elems.Count; i++)
                Elems[i].Encode();
            AverageCompressionRatio = Program.CreateSequence(p => Elems[p].EncodingCompressionRatio,
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
