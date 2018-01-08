namespace FontRasterer
{
    public static class BitWise
    {
        const int logicalOne = 1;
        
#region SetBit
        public static void SetBit(ref byte n, int x)
        {
          n |= (byte)(logicalOne << x);
        }

        public static void SetBit(ref ushort n, int x)
        {
          n |= (ushort)(logicalOne << x);
        }

        public static void SetBit(ref int n, int x)
        {
          n |= logicalOne << x;
        }
#endregion

#region ClearBit
        public static void ClearBit(ref byte n, int x)
        {
          n &= (byte)(~(logicalOne << x));
        }

        public static void ClearBit(ref ushort n, int x)
        {
          n &= (ushort)(~(logicalOne << x));
        }

        public static void ClearBit(ref int n, int x)
        {
          n &= ~(logicalOne << x);
        }
#endregion

#region InverseBit
        public static void InverseBit(ref byte n, int x)
        {
          n ^= (byte)(logicalOne << x);
        }

        public static void InverseBit(ref ushort n, int x)
        {
          n ^= (ushort)(logicalOne << x);
        }

        public static void InverseBit(ref int n, int x)
        {
          n ^= logicalOne << x;
        }
#endregion

#region Bit
        public static int Bit(byte n, int x)
        {
            return (n >> x) & logicalOne;
        }

        public static int Bit(ushort n, int x)
        {
            return (n >> x) & logicalOne;
        }

        public static int Bit(int n, int x)
        {
          return (n >> x) & logicalOne;
        }
#endregion

#region SSetBit
        public static void SSetBit(ref byte n, int x, int b)
        {
            n ^= (byte)((-b ^ n) & (logicalOne << x));
        }

        public static void SSetBit(ref ushort n, int x, int b)
        {
            n ^= (ushort)((-b ^ n) & (logicalOne << x));
        }

        public static void SSetBit(ref int n, int x, int b)
        {
          n ^= (-b ^ n) & (logicalOne << x);
        }
#endregion
    }
}
