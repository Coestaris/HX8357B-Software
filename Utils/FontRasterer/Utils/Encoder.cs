using System;
using System.Collections.Generic;
using System.Linq;

namespace FontRasterer
{
    static class Encoder
    {
        public static void Decode(List<byte> bytes, int offset, int count,
          Action<bool> bitProceed)
        {
            for (int i = 0; i < count;)
            {
                byte leadB = bytes[offset + i];

                if (BitWise.Bit(leadB, 7) == 1)
                {
                    for (int b = 0; b < 7; b++)
                        bitProceed(BitWise.Bit(leadB, b) == 1);
                    i++;
                }
                else
                {
                    byte indexLB = bytes[offset + i + 1];
                    if (BitWise.Bit(indexLB, 7) == 0)
                    {
                        for (int cnt = 0; cnt < indexLB; cnt++)
                            for (int b = 0; b < 7; b++)
                                bitProceed(BitWise.Bit(leadB, b) == 1);
                        i += 2;
                    }
                    else
                    {
                        byte indexHB = bytes[offset + i + 2];
                        BitWise.ClearBit(ref indexLB, 7);
                        var l = BitConverter.ToUInt16(new byte[] { indexLB, indexHB }, 0);

                        for (int cnt = 0; cnt < l; cnt++)
                            for (int b = 0; b < 7; b++)
                                bitProceed(BitWise.Bit(leadB, b) == 1);

                        i += 3;
                    }
                }
            }
        }

        private static byte CreateByte(List<bool> controlBits, int index)
        {
            byte b = 0;
            for (int i = 0; i < 7; i++)
                if (index * 7 + i < controlBits.Count)
                    BitWise.SSetBit(ref b, i, controlBits[index * 7 + i] ? 1 : 0);
            return b;
        }

        public static List<byte> Encode(List<byte> bytes, int offset, int count)
        {
            List<byte> result = new List<byte>();

            List<bool> controlBits = new List<bool>();

            for (int i = 0; i < count; i++)
                for (int b = 0; b < 8; b++)
                    controlBits.Add(BitWise.Bit(bytes[i + offset], b) == 1);

            var newByteCount = (int)Math.Ceiling(controlBits.Count / 7f);

            List<byte> controlBytes = Program.CreateSequence(p => CreateByte(controlBits, p),
                newByteCount).ToList();

            byte last = controlBytes[0];
            int cnt = 0;

            for (int i = 0; i < newByteCount; i++)
            {
                if (last == controlBytes[i])
                    cnt++;
                else
                {
                    AddBytes(ref result, cnt, last);
                    last = controlBytes[i];
                    cnt = 1;
                }
            }
            AddBytes(ref result, cnt, last);
            return result;
        }

        private static void AddBytes(ref List<byte> result, int count, byte val)
        {
            if (count == 1)
            {
                BitWise.SetBit(ref val, 7);
                result.Add(val);
            }
            else
            {
                result.Add(val);
                if (count <= 0x7F)
                    //Always keep first bit as 0
                    result.Add((byte)count);
                else
                {
                    if (count > 0x7FFF)
                        throw new ArithmeticException("Длина не может превышать 32767");

                    byte[] _bytes = BitConverter.GetBytes((UInt16)count);
                    BitWise.SetBit(ref _bytes[1], 7);
                    result.Add(_bytes[1]);
                    result.Add(_bytes[0]);
                }
            }
        }
    }
}
