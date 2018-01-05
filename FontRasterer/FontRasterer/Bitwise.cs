namespace FontRasterer
{
    public static class BitWise
    {
        const int logicalOne = 1;

        public static void SetBit(ref int n, int x)
        {
            n |= logicalOne << x;
        }

        public static void SetBit(ref byte n, int x)
        {
            n |= (byte)(logicalOne << x);
        }

        public static void ClearBit(ref int n, int x)
        {
            n &= ~(logicalOne << x);
        }

        public static void ClearBit(ref byte n, int x)
        {
            n &= (byte)(~(logicalOne << x));
        }

        public static void InverseBit(ref int n, int x)
        {
            n ^= logicalOne << x;
        }

        public static void InverseBit(ref byte n, int x)
        {
            n ^= (byte)(logicalOne << x);
        }

        public static int Bit(int n, int x)
        {
            return (n >> x) & logicalOne;
        }

        public static int Bit(byte n, int x)
        {
            return (n >> x) & logicalOne;
        }

        public static void SSetBit(ref int n, int x, int b)
        {
            n ^= (-b ^ n) & (logicalOne << x);
        }

        public static void SSetBit(ref byte n, int x, int b)
        {
            n ^= (byte)((-b ^ n) & (logicalOne << x));
        }
    }
}
