namespace BitmapConverter
{
    /// <summary>
    /// RGB color mode
    /// </summary>
    public enum ColorMode
    {
        /// <summary>
        ///16bit. 65.5k colors.
        /// </summary>
        Color_565 = 0x1,

        /// <summary>
        ///16bit. 65.5k colors.
        /// </summary>
        Color_555 = 0x2,  //15bit. 32.7k colors.
        
        /// <summary>
        ///8bit. 256 colors.
        /// </summary>
        Color_332 = 0x4,

        /// <summary>
        ///8bit. 256 colors, grayscale.
        /// </summary>
        GrayScale = 0x8,

        /// <summary>
        ///7bit. 128 colors, grayscale. RLE encoded.
        /// </summary>
        GrayScale_encoded = 0x10,

        /// <summary>
        ///1bit. 2 colors
        /// </summary>
        Binary = 0x20,

        /// <summary>
        ///1bit. 2 colors. RLE encoded.
        /// </summary>
        Binary_encoded = 0x40, 

        /// <summary>
        ///Same as <see cref="ColorMode.Color_565"/>.
        /// </summary>
        Default = 0x80
    }
}
