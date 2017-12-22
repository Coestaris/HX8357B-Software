#ifndef _font_std_h_
#define _font_std_h_

#include "../fontinfo.h"

const PROGMEM  uint8_t font_std_data[] =
{
    //Font Info. Symbol X size: 14, Symbol Y size: 18
    //Stars from: 33, Ends with: 161
    //Total size: 4096 bytes
    0xE, 0x12, 0x21, 0xA1,

    //Symbol for unrecognised chars.
    0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1, 0x70,
    0x0, 0x1C, 0x0, 0x7, 0xC0, 0x3F, 0xF0, 0xF, 0xFC, 0x3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 33  or '!'. Symbol Index: 0
    0x0, 0x0, 0x0, 0x0, 0xE, 0x80, 0x3, 0xE0, 0x0, 0x38,
    0x0, 0xE, 0x80, 0x3, 0xE0, 0x0, 0x38, 0x0, 0xE, 0x80,
    0x3, 0x0, 0x0, 0x38, 0x0, 0xE, 0x80, 0x3, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 34  or '"'. Symbol Index: 1
    0x10, 0x1, 0xEE, 0x80, 0x3B, 0xE0, 0xE, 0xB8, 0x3, 0xEE,
    0x0, 0x11, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 35  or '#'. Symbol Index: 2
    0x0, 0x0, 0x6C, 0x0, 0x1B, 0xC0, 0x6, 0xB0, 0x1, 0x6C,
    0xC0, 0x7F, 0xF0, 0x1F, 0xB0, 0x1, 0x6C, 0xC0, 0x7F, 0xF0,
    0x1F, 0xB0, 0x1, 0x6C, 0x0, 0x1B, 0xC0, 0x6, 0xB0, 0x1,
    0x0, 0x0,

    //Symbol: 36  or '$'. Symbol Index: 3
    0x0, 0x0, 0x30, 0x0, 0xC, 0xC0, 0x1F, 0xF8, 0x7, 0xB6,
    0x83, 0xCD, 0xE0, 0x3, 0xF0, 0x3, 0xF0, 0x1, 0xCC, 0x60,
    0x33, 0xD8, 0xE, 0xFE, 0x1, 0x3F, 0x0, 0x3, 0xC0, 0x0,
    0x0, 0x0,

    //Symbol: 37  or '%'. Symbol Index: 4
    0x0, 0x0, 0x0, 0xC0, 0x3, 0xF8, 0x1, 0x66, 0x8C, 0x99,
    0xE3, 0x77, 0xF0, 0xE, 0xC0, 0x1, 0x38, 0x0, 0xF7, 0xE0,
    0x7E, 0x9C, 0x19, 0x63, 0x6, 0xF8, 0x1, 0x3C, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 38  or '&'. Symbol Index: 5
    0x0, 0x0, 0x0, 0x0, 0x1F, 0xC0, 0x7, 0x18, 0x3, 0xC6,
    0x80, 0x31, 0xC0, 0x6, 0xF8, 0xC, 0xB6, 0xC3, 0x78, 0x30,
    0xC, 0x1C, 0x7, 0x7E, 0x3, 0xCF, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 39  or '''. Symbol Index: 6
    0x40, 0x0, 0x38, 0x0, 0xE, 0x80, 0x3, 0xE0, 0x0, 0x10,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 40  or '('. Symbol Index: 7
    0x80, 0x1, 0x60, 0x0, 0x1C, 0x0, 0x3, 0xE0, 0x0, 0x38,
    0x0, 0x6, 0x80, 0x1, 0x60, 0x0, 0x18, 0x0, 0x6, 0x80,
    0x3, 0xE0, 0x0, 0x30, 0x0, 0x1C, 0x0, 0x6, 0x80, 0x1,
    0x0, 0x0,

    //Symbol: 41  or ')'. Symbol Index: 8
    0x60, 0x0, 0x18, 0x0, 0xE, 0x0, 0x3, 0xC0, 0x1, 0x70,
    0x0, 0x18, 0x0, 0x6, 0x80, 0x1, 0x60, 0x0, 0x18, 0x0,
    0x7, 0xC0, 0x1, 0x30, 0x0, 0xE, 0x80, 0x1, 0x60, 0x0,
    0x0, 0x0,

    //Symbol: 42  or '*'. Symbol Index: 9
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30,
    0x0, 0x2D, 0x80, 0x7, 0xF8, 0x7, 0x78, 0x0, 0x2D, 0x0,
    0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 43  or '+'. Symbol Index: 10
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC0, 0x0, 0x30,
    0x0, 0xC, 0x0, 0x3, 0xFC, 0xF, 0xFF, 0x3, 0xC, 0x0,
    0x3, 0xC0, 0x0, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 44  or ','. Symbol Index: 11
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x78, 0x0, 0x1E, 0xC0, 0x3, 0x70, 0x0,
    0xC, 0x0,

    //Symbol: 45  or '-'. Symbol Index: 12
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xFC, 0xF, 0xFF, 0x3, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 46  or '.'. Symbol Index: 13
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xE0, 0x0, 0x7C, 0x0, 0x1F, 0x80, 0x3, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 47  or '/'. Symbol Index: 14
    0x0, 0x6, 0xC0, 0x1, 0x30, 0x0, 0xC, 0x80, 0x1, 0x60,
    0x0, 0xC, 0x0, 0x3, 0xE0, 0x0, 0x18, 0x0, 0x7, 0xC0,
    0x0, 0x38, 0x0, 0x6, 0xC0, 0x1, 0x30, 0x0, 0xC, 0x0,
    0x0, 0x0,

    //Symbol: 48  or '0'. Symbol Index: 15
    0x0, 0x0, 0x0, 0x0, 0x1E, 0xE0, 0xF, 0x18, 0x3, 0x83,
    0xC1, 0x60, 0x30, 0x18, 0xC, 0x6, 0x83, 0xC1, 0x60, 0x30,
    0x18, 0xC, 0x6, 0xC6, 0x80, 0x3F, 0xC0, 0x7, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 49  or '1'. Symbol Index: 16
    0x0, 0x0, 0x0, 0x0, 0xE, 0xF0, 0x3, 0xCC, 0x0, 0x30,
    0x0, 0xC, 0x0, 0x3, 0xC0, 0x0, 0x30, 0x0, 0xC, 0x0,
    0x3, 0xC0, 0x0, 0x30, 0xC0, 0x7F, 0xF0, 0x1F, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 50  or '2'. Symbol Index: 17
    0x0, 0x0, 0x0, 0x0, 0x1E, 0xC0, 0x1F, 0x38, 0x6, 0x6,
    0x83, 0xC1, 0x0, 0x18, 0x0, 0x3, 0x60, 0x0, 0xC, 0x80,
    0x1, 0x30, 0x0, 0x6, 0xC3, 0xFF, 0xF0, 0x3F, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 51  or '3'. Symbol Index: 18
    0x0, 0x0, 0x0, 0x0, 0x1F, 0xF0, 0xF, 0xC, 0x7, 0x80,
    0x1, 0x70, 0x80, 0xF, 0xE0, 0x3, 0xC0, 0x1, 0x60, 0x0,
    0x18, 0x0, 0x6, 0xC3, 0xC1, 0x3F, 0xC0, 0x7, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 52  or '4'. Symbol Index: 19
    0x0, 0x0, 0x0, 0x0, 0x38, 0x0, 0xF, 0xE0, 0x3, 0xD8,
    0x0, 0x37, 0xE0, 0xC, 0x18, 0x3, 0xC7, 0xC0, 0x7F, 0xF0,
    0x1F, 0x0, 0x3, 0xC0, 0x0, 0x7C, 0x0, 0x1F, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 53  or '5'. Symbol Index: 20
    0x0, 0x0, 0x0, 0x80, 0x3F, 0xE0, 0xF, 0x18, 0x0, 0x6,
    0x80, 0x1F, 0xE0, 0xF, 0x18, 0x7, 0x80, 0x1, 0x60, 0x0,
    0x18, 0xC, 0x6, 0xC7, 0xC1, 0x3F, 0xC0, 0x7, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 54  or '6'. Symbol Index: 21
    0x0, 0x0, 0x0, 0x0, 0x78, 0x80, 0x1F, 0x70, 0x0, 0xE,
    0x80, 0x1, 0xA0, 0x7, 0xFC, 0x7, 0x8F, 0xC1, 0xC1, 0x70,
    0x30, 0x18, 0xC, 0x8E, 0x1, 0x7F, 0x80, 0xF, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 55  or '7'. Symbol Index: 22
    0x0, 0x0, 0x0, 0xC0, 0x7F, 0xF0, 0x1F, 0x4, 0x7, 0xC0,
    0x0, 0x30, 0x0, 0xE, 0x80, 0x1, 0x60, 0x0, 0x18, 0x0,
    0x3, 0xC0, 0x0, 0x30, 0x0, 0xE, 0x80, 0x1, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 56  or '8'. Symbol Index: 23
    0x0, 0x0, 0x0, 0x0, 0x1F, 0xE0, 0xF, 0x1C, 0x3, 0x83,
    0xC1, 0x60, 0x70, 0xC, 0xF8, 0x3, 0xFE, 0xC0, 0x30, 0x30,
    0x18, 0xC, 0x6, 0xC3, 0x80, 0x3F, 0xC0, 0x7, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 57  or '9'. Symbol Index: 24
    0x0, 0x0, 0x0, 0x0, 0x1F, 0xE0, 0xF, 0x18, 0x7, 0x83,
    0xC1, 0x60, 0x30, 0x18, 0x18, 0x7, 0xFE, 0x1, 0x7F, 0x0,
    0x18, 0x0, 0x7, 0xE0, 0xC0, 0x1F, 0xE0, 0x1, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 58  or ':'. Symbol Index: 25
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC0, 0x0, 0x78,
    0x0, 0x1E, 0x0, 0x3, 0x0, 0x0, 0x0, 0x0, 0xC, 0x80,
    0x7, 0xE0, 0x1, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 59  or ';'. Symbol Index: 26
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xE0, 0x1, 0x78,
    0x0, 0xC, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1C, 0x80,
    0x7, 0xE0, 0x0, 0x18, 0x0, 0x7, 0xC0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 60  or '<'. Symbol Index: 27
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x38, 0x0, 0xF, 0xF0,
    0x0, 0xF, 0xE0, 0x1, 0x1E, 0x80, 0x7, 0x80, 0x7, 0xC0,
    0x3, 0xC0, 0x3, 0xC0, 0x3, 0xE0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 61  or '='. Symbol Index: 28
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xE0, 0xFF, 0xF8, 0x3F, 0x0, 0x80, 0xFF, 0xE3, 0xFF, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 62  or '>'. Symbol Index: 29
    0x0, 0x0, 0x0, 0x0, 0x0, 0x38, 0x0, 0x1E, 0x0, 0x1E,
    0x0, 0x1E, 0x0, 0xF, 0x0, 0xF, 0xC0, 0x3, 0x3C, 0x80,
    0x7, 0x78, 0x80, 0x7, 0xE0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 63  or '?'. Symbol Index: 30
    0x0, 0x0, 0x0, 0x0, 0x1F, 0xF0, 0xF, 0xC, 0x7, 0x83,
    0x1, 0x60, 0x0, 0x1E, 0xC0, 0x3, 0x38, 0x0, 0x6, 0x80,
    0x1, 0x0, 0x0, 0x0, 0x0, 0x6, 0x80, 0x1, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 64  or '@'. Symbol Index: 31
    0x0, 0x0, 0xF8, 0x80, 0x7F, 0x60, 0x18, 0x1C, 0xC, 0x73,
    0xC3, 0xDE, 0xB0, 0x31, 0x6C, 0xC, 0x9B, 0xC3, 0xFE, 0x30,
    0x1F, 0xC, 0x0, 0x6, 0x83, 0xFF, 0xC0, 0x1F, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 65  or 'A'. Symbol Index: 32
    0x0, 0x0, 0x0, 0xC0, 0xF, 0xF0, 0x3, 0xB0, 0x1, 0x6C,
    0x80, 0x3B, 0x60, 0xC, 0x18, 0x3, 0xFF, 0xC1, 0x7F, 0x38,
    0x18, 0x6, 0xCE, 0xC7, 0xF7, 0xF1, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 66  or 'B'. Symbol Index: 33
    0x0, 0x0, 0x0, 0xE0, 0x1F, 0xF8, 0x1F, 0xC, 0x6, 0x83,
    0xC1, 0x70, 0xF0, 0xF, 0xFC, 0x7, 0x83, 0xC3, 0xC0, 0x30,
    0x30, 0xC, 0x8E, 0xFF, 0xE1, 0x3F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 67  or 'C'. Symbol Index: 34
    0x0, 0x0, 0x0, 0x0, 0xDF, 0xE0, 0x3F, 0xC, 0x8E, 0x1,
    0x63, 0xC0, 0x18, 0x0, 0x6, 0x80, 0x1, 0x60, 0x0, 0x38,
    0x30, 0x1C, 0xE, 0xFE, 0x1, 0x1E, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 68  or 'D'. Symbol Index: 35
    0x0, 0x0, 0x0, 0xE0, 0x1F, 0xF8, 0x1F, 0xC, 0x6, 0x3,
    0xC3, 0xC0, 0x30, 0x30, 0xC, 0xC, 0x3, 0xC3, 0xC0, 0x30,
    0x30, 0xC, 0x8E, 0xFF, 0xE1, 0x1F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 69  or 'E'. Symbol Index: 36
    0x0, 0x0, 0x0, 0xE0, 0x7F, 0xF8, 0x1F, 0xC, 0x6, 0xB3,
    0xC1, 0xC, 0xF0, 0x3, 0xFC, 0x0, 0x33, 0xC0, 0xCC, 0x30,
    0x30, 0xC, 0x8C, 0xFF, 0xE3, 0xFF, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 70  or 'F'. Symbol Index: 37
    0x0, 0x0, 0x0, 0xE0, 0xFF, 0xF8, 0x3F, 0xC, 0xC, 0x33,
    0xC3, 0xC, 0xF0, 0x3, 0xFC, 0x0, 0x33, 0xC0, 0xC, 0x30,
    0x0, 0xC, 0x80, 0x3F, 0xE0, 0xF, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 71  or 'G'. Symbol Index: 38
    0x0, 0x0, 0x0, 0x0, 0x7F, 0xE0, 0x3F, 0x1C, 0x8E, 0x3,
    0x63, 0x0, 0x18, 0x0, 0xC6, 0x87, 0xF1, 0x63, 0xC0, 0x18,
    0x30, 0xE, 0xC, 0xFF, 0x83, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 72  or 'H'. Symbol Index: 39
    0x0, 0x0, 0x0, 0xE0, 0xFB, 0xF8, 0x3E, 0xC, 0x6, 0x83,
    0xC1, 0x60, 0xF0, 0x1F, 0xFC, 0x7, 0x83, 0xC1, 0x60, 0x30,
    0x18, 0xC, 0x86, 0xEF, 0xE3, 0xFB, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 73  or 'I'. Symbol Index: 40
    0x0, 0x0, 0x0, 0xC0, 0x7F, 0xF0, 0x1F, 0x60, 0x0, 0x18,
    0x0, 0x6, 0x80, 0x1, 0x60, 0x0, 0x18, 0x0, 0x6, 0x80,
    0x1, 0x60, 0x0, 0xFF, 0xC1, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 74  or 'J'. Symbol Index: 41
    0x0, 0x0, 0x0, 0x0, 0xFF, 0xC1, 0x7F, 0x0, 0x3, 0xC0,
    0x0, 0x30, 0x0, 0xC, 0x4, 0x83, 0xC1, 0x60, 0x30, 0x18,
    0xC, 0x8E, 0x3, 0x7F, 0x0, 0xF, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 75  or 'K'. Symbol Index: 42
    0x0, 0x0, 0x0, 0xE0, 0xF3, 0xF8, 0x3C, 0xC, 0x7, 0x73,
    0xC0, 0xE, 0xF0, 0x1, 0xFC, 0x0, 0x77, 0xC0, 0x38, 0x30,
    0xC, 0xC, 0x86, 0x8F, 0xE7, 0xE3, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 76  or 'L'. Symbol Index: 43
    0x0, 0x0, 0x0, 0xE0, 0xF, 0xF8, 0x3, 0x18, 0x0, 0x6,
    0x80, 0x1, 0x60, 0x0, 0x18, 0x0, 0x6, 0x83, 0xC1, 0x60,
    0x30, 0x18, 0x8C, 0xFF, 0xE3, 0xFF, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 77  or 'M'. Symbol Index: 44
    0x0, 0x0, 0x0, 0xF0, 0xE0, 0x3D, 0x7C, 0x1E, 0x8F, 0xC7,
    0xE3, 0xDB, 0xD8, 0x36, 0xF6, 0x8D, 0x39, 0x63, 0xCE, 0x18,
    0x30, 0x6, 0xCC, 0xC7, 0xF7, 0xF1, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 78  or 'N'. Symbol Index: 45
    0x0, 0x0, 0x0, 0xF0, 0xF8, 0x7D, 0x7E, 0x1C, 0x6, 0x8F,
    0xC1, 0x67, 0xB0, 0x19, 0xEC, 0x6, 0xB3, 0xC1, 0x7C, 0x30,
    0x1E, 0xC, 0x87, 0xCF, 0xE1, 0x63, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 79  or 'O'. Symbol Index: 46
    0x0, 0x0, 0x0, 0x0, 0x1F, 0xE0, 0xF, 0x1C, 0x87, 0x83,
    0x63, 0xC0, 0x18, 0x30, 0x6, 0x8C, 0x1, 0x63, 0xC0, 0x38,
    0x38, 0x1C, 0x7, 0xFE, 0x0, 0x1F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 80  or 'P'. Symbol Index: 47
    0x0, 0x0, 0x0, 0xC0, 0x3F, 0xF0, 0x1F, 0x18, 0xE, 0x6,
    0x83, 0xC1, 0x60, 0x38, 0xF8, 0x7, 0xFE, 0x80, 0x1, 0x60,
    0x0, 0x18, 0x0, 0x7F, 0xC0, 0x1F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 81  or 'Q'. Symbol Index: 48
    0x0, 0x0, 0x0, 0x0, 0x1F, 0xE0, 0xF, 0x1C, 0x87, 0x83,
    0x63, 0xC0, 0x18, 0x30, 0x6, 0x8C, 0x1, 0x63, 0xC0, 0x18,
    0x38, 0x1C, 0x7, 0xFE, 0x0, 0xF, 0x80, 0x37, 0xF8, 0xF,
    0xC6, 0x1,

    //Symbol: 82  or 'R'. Symbol Index: 49
    0x0, 0x0, 0x0, 0xE0, 0x1F, 0xF8, 0xF, 0xC, 0x7, 0x83,
    0xC1, 0x60, 0x30, 0x1C, 0xFC, 0x3, 0x7F, 0xC0, 0x38, 0x30,
    0x1C, 0xC, 0x86, 0x8F, 0xE7, 0xC3, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 83  or 'S'. Symbol Index: 50
    0x0, 0x0, 0x0, 0x0, 0x7E, 0xC0, 0x3F, 0x38, 0xE, 0x6,
    0x83, 0x3, 0xE0, 0x1F, 0xE0, 0xF, 0x80, 0x83, 0xC1, 0x60,
    0x30, 0x38, 0xC, 0xFE, 0x1, 0x3E, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 84  or 'T'. Symbol Index: 51
    0x0, 0x0, 0x0, 0xE0, 0xFF, 0xF8, 0x3F, 0x66, 0x8C, 0x19,
    0x63, 0xC6, 0x98, 0x31, 0x60, 0x0, 0x18, 0x0, 0x6, 0x80,
    0x1, 0x60, 0x0, 0xFE, 0x80, 0x3F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 85  or 'U'. Symbol Index: 52
    0x0, 0x0, 0x0, 0xE0, 0xF7, 0xF9, 0x7D, 0x18, 0xC, 0x6,
    0x83, 0xC1, 0x60, 0x30, 0x18, 0xC, 0x6, 0x83, 0xC1, 0x60,
    0x30, 0x38, 0xE, 0xFC, 0x1, 0x3E, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 86  or 'V'. Symbol Index: 53
    0x0, 0x0, 0x0, 0xF0, 0xF9, 0x7D, 0x7E, 0xC, 0x6, 0x83,
    0xC1, 0x70, 0x60, 0xC, 0x18, 0x3, 0xEE, 0x0, 0x1B, 0xC0,
    0x6, 0xF0, 0x0, 0x38, 0x0, 0xE, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 87  or 'W'. Symbol Index: 54
    0x0, 0x0, 0x0, 0xF0, 0xF1, 0x7D, 0x7D, 0x46, 0x8C, 0x39,
    0x63, 0xCE, 0x98, 0x33, 0xF6, 0x8D, 0x7D, 0xC3, 0x7B, 0xF0,
    0x1E, 0x1C, 0x7, 0xC7, 0xC1, 0x71, 0x20, 0x8, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 88  or 'X'. Symbol Index: 55
    0x0, 0x0, 0x0, 0xE0, 0xF3, 0xF9, 0x7C, 0x1C, 0xE, 0xCE,
    0x1, 0x3F, 0x80, 0x7, 0xC0, 0x1, 0x78, 0x0, 0x37, 0xE0,
    0x1C, 0x1C, 0x8E, 0xCF, 0xE7, 0xF3, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 89  or 'Y'. Symbol Index: 56
    0x0, 0x0, 0x0, 0xE0, 0xF1, 0x78, 0x3C, 0x1C, 0x7, 0xC6,
    0x80, 0x3B, 0xC0, 0x7, 0xE0, 0x0, 0x38, 0x0, 0xC, 0x0,
    0x3, 0xC0, 0x0, 0xFE, 0x80, 0x3F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 90  or 'Z'. Symbol Index: 57
    0x0, 0x0, 0x0, 0xC0, 0x7F, 0xF0, 0x1F, 0xC, 0x3, 0xE3,
    0xC0, 0x1C, 0x0, 0x3, 0x60, 0x0, 0x9C, 0x1, 0x63, 0x60,
    0x18, 0x1C, 0x6, 0xFF, 0xC1, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 91  or '['. Symbol Index: 58
    0xF0, 0x1, 0x7C, 0x0, 0x3, 0xC0, 0x0, 0x30, 0x0, 0xC,
    0x0, 0x3, 0xC0, 0x0, 0x30, 0x0, 0xC, 0x0, 0x3, 0xC0,
    0x0, 0x30, 0x0, 0xC, 0x0, 0x3, 0xC0, 0x7, 0xF0, 0x1,
    0x0, 0x0,

    //Symbol: 92  or '\'. Symbol Index: 59
    0xC, 0x0, 0x3, 0xC0, 0x1, 0x60, 0x0, 0x38, 0x0, 0xC,
    0x0, 0x7, 0x80, 0x1, 0xE0, 0x0, 0x30, 0x0, 0xC, 0x0,
    0x6, 0x80, 0x1, 0xC0, 0x0, 0x30, 0x0, 0x1C, 0x0, 0x6,
    0x0, 0x0,

    //Symbol: 93  or ']'. Symbol Index: 60
    0xE0, 0x1, 0x78, 0x0, 0x18, 0x0, 0x6, 0x80, 0x1, 0x60,
    0x0, 0x18, 0x0, 0x6, 0x80, 0x1, 0x60, 0x0, 0x18, 0x0,
    0x6, 0x80, 0x1, 0x60, 0x0, 0x18, 0x80, 0x7, 0xE0, 0x1,
    0x0, 0x0,

    //Symbol: 94  or '^'. Symbol Index: 61
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xE, 0xC0, 0x3, 0xB0, 0x1, 0xE6, 0xC0, 0x71, 0x30,
    0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 95  or '_'. Symbol Index: 62
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xFF, 0xDF, 0xFF, 0x7, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 96  or '`'. Symbol Index: 63
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xC0, 0x0, 0x70, 0x0, 0x78, 0x0, 0x18, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 97  or 'a'. Symbol Index: 64
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7F,
    0xE0, 0x3F, 0x18, 0xC, 0xF8, 0x3, 0xFF, 0xE0, 0x30, 0x18,
    0xC, 0x86, 0x3, 0xFF, 0x83, 0xF7, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 98  or 'b'. Symbol Index: 65
    0x0, 0x80, 0x7, 0xE0, 0x1, 0x60, 0x0, 0x18, 0x0, 0xF6,
    0x80, 0xFF, 0xE0, 0x30, 0x18, 0x18, 0x6, 0x86, 0x81, 0x61,
    0x60, 0x38, 0x8C, 0xFF, 0xE3, 0x3D, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 99  or 'c'. Symbol Index: 66
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFC,
    0x80, 0x7F, 0x70, 0x38, 0xC, 0xC, 0x3, 0xC0, 0x0, 0x30,
    0x30, 0x1C, 0xE, 0xFE, 0x1, 0x3F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 100  or 'd'. Symbol Index: 67
    0x0, 0x0, 0xC0, 0x1, 0x70, 0x0, 0x18, 0x0, 0x6, 0xBC,
    0xC1, 0x7F, 0x38, 0x1C, 0x6, 0x86, 0x81, 0x61, 0x60, 0x18,
    0x18, 0xE, 0x7, 0xFF, 0x7, 0xEF, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 101  or 'e'. Symbol Index: 68
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFC,
    0x80, 0x7F, 0x70, 0x38, 0xC, 0xC, 0xFF, 0xC3, 0xFF, 0x30,
    0x0, 0x18, 0xC, 0xFE, 0x3, 0x3E, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 102  or 'f'. Symbol Index: 69
    0x0, 0x0, 0x0, 0x0, 0xF8, 0x0, 0x3F, 0x60, 0x0, 0x18,
    0x80, 0x7F, 0xE0, 0x1F, 0x60, 0x0, 0x18, 0x0, 0x6, 0x80,
    0x1, 0x60, 0x0, 0xFE, 0x81, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 103  or 'g'. Symbol Index: 70
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xB8,
    0x83, 0xFF, 0x70, 0x1E, 0xC, 0x7, 0x83, 0xC1, 0x70, 0x70,
    0x1E, 0xF8, 0x7, 0xB8, 0x1, 0x60, 0x0, 0x1C, 0xF0, 0x3,
    0x7C, 0x0,

    //Symbol: 104  or 'h'. Symbol Index: 71
    0x0, 0x0, 0x0, 0xC0, 0x1, 0x70, 0x0, 0x18, 0x0, 0x76,
    0x80, 0x3F, 0xE0, 0x1C, 0x18, 0x6, 0x86, 0x81, 0x61, 0x60,
    0x18, 0x18, 0x6, 0x8E, 0xC1, 0xF7, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 105  or 'i'. Symbol Index: 72
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC0, 0x0, 0x30,
    0x0, 0x0, 0xC0, 0x3, 0xF0, 0x0, 0x30, 0x0, 0xC, 0x0,
    0x3, 0xC0, 0x0, 0xFC, 0x1, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 106  or 'j'. Symbol Index: 73
    0x0, 0x0, 0x0, 0x0, 0x18, 0x0, 0x6, 0x0, 0x0, 0xFE,
    0x80, 0x3F, 0x0, 0xC, 0x0, 0x3, 0xC0, 0x0, 0x30, 0x0,
    0xC, 0x0, 0x3, 0xC0, 0x0, 0x30, 0x0, 0xC, 0xF8, 0x3,
    0x3E, 0x0,

    //Symbol: 107  or 'k'. Symbol Index: 74
    0x0, 0x0, 0x0, 0xC0, 0x1, 0x70, 0x0, 0x18, 0x0, 0xE6,
    0x83, 0xF9, 0x60, 0x7, 0xF8, 0x0, 0x1E, 0x80, 0xF, 0x60,
    0x7, 0x98, 0x3, 0xC7, 0xC3, 0xF1, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 108  or 'l'. Symbol Index: 75
    0x0, 0x0, 0x0, 0x0, 0xF, 0xC0, 0x3, 0xC0, 0x0, 0x30,
    0x0, 0xC, 0x0, 0x3, 0xC0, 0x0, 0x30, 0x0, 0xC, 0x0,
    0x3, 0xC0, 0x0, 0xFC, 0x1, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 109  or 'm'. Symbol Index: 76
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xEF,
    0xE1, 0xFF, 0xB8, 0x33, 0xC6, 0x8C, 0x31, 0x63, 0xCC, 0x18,
    0x33, 0xC6, 0xCC, 0x7B, 0xF7, 0xDE, 0x1, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 110  or 'n'. Symbol Index: 77
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x7B,
    0xE0, 0x3F, 0xF0, 0x1C, 0x1C, 0x6, 0x83, 0xC1, 0x60, 0x30,
    0x18, 0xC, 0x86, 0xEF, 0xE3, 0xFB, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 111  or 'o'. Symbol Index: 78
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7C,
    0xC0, 0x7F, 0x30, 0x18, 0x6, 0x8C, 0x1, 0x63, 0xC0, 0x18,
    0x30, 0xC, 0x6, 0xFF, 0x1, 0x1F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 112  or 'p'. Symbol Index: 79
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xF7,
    0x80, 0x7F, 0xC0, 0x10, 0x30, 0xC, 0xC, 0x3, 0xC3, 0xC0,
    0x30, 0x30, 0xE, 0xFC, 0x1, 0x3F, 0xC0, 0x0, 0x30, 0x0,
    0x1E, 0x0,

    //Symbol: 113  or 'q'. Symbol Index: 80
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xB8,
    0x3, 0xFF, 0xE0, 0x1E, 0x1C, 0x6, 0x83, 0xC1, 0x60, 0x60,
    0x18, 0x38, 0x6, 0xFC, 0x1, 0x7E, 0x0, 0x18, 0x0, 0x6,
    0xC0, 0x3,

    //Symbol: 114  or 'r'. Symbol Index: 81
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xE7,
    0xC1, 0xFF, 0xC0, 0x33, 0x30, 0x0, 0xC, 0x0, 0x3, 0xC0,
    0x0, 0x30, 0x0, 0x7F, 0xC0, 0x1F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 115  or 's'. Symbol Index: 82
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFE,
    0xC0, 0x7F, 0x30, 0x18, 0xFC, 0x0, 0xFE, 0x0, 0x70, 0x0,
    0x18, 0x4, 0x7, 0xFF, 0x80, 0x1F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 116  or 't'. Symbol Index: 83
    0x0, 0x0, 0x0, 0x80, 0x1, 0x60, 0x0, 0x18, 0x0, 0x6,
    0xE0, 0x3F, 0xF8, 0xF, 0x18, 0x0, 0x6, 0x80, 0x1, 0x60,
    0x30, 0x38, 0xE, 0xFC, 0x1, 0x3E, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 117  or 'u'. Symbol Index: 84
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xE3,
    0xE1, 0x78, 0x30, 0x18, 0xC, 0x6, 0x83, 0xC1, 0x60, 0x30,
    0x18, 0xC, 0x7, 0xFF, 0x83, 0xEF, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 118  or 'v'. Symbol Index: 85
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0xEF,
    0xE3, 0xFB, 0x70, 0x18, 0x18, 0x3, 0xC6, 0x80, 0x3B, 0xC0,
    0x6, 0xF0, 0x1, 0x38, 0x0, 0xE, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 119  or 'w'. Symbol Index: 86
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xC0, 0x83,
    0xF7, 0xE0, 0x19, 0x31, 0xE6, 0x8C, 0x39, 0x63, 0xDF, 0xF0,
    0x1E, 0xBC, 0x7, 0xC6, 0x0, 0x11, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 120  or 'x'. Symbol Index: 87
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x83,
    0xC1, 0x71, 0xE0, 0xE, 0xF0, 0x1, 0x38, 0x0, 0x1F, 0xE0,
    0xE, 0x1C, 0x7, 0x83, 0xC1, 0x60, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 121  or 'y'. Symbol Index: 88
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6,
    0x83, 0xE1, 0x60, 0x18, 0x38, 0x6, 0xCC, 0x0, 0x3F, 0x80,
    0x7, 0xC0, 0x1, 0x30, 0x0, 0xE, 0xC0, 0x1, 0x30, 0x0,
    0x0, 0x0,

    //Symbol: 122  or 'z'. Symbol Index: 89
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xFF,
    0xC1, 0x7F, 0x30, 0xC, 0x8C, 0x1, 0x30, 0x0, 0x6, 0xC0,
    0x18, 0x18, 0x6, 0xFF, 0xC1, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 123  or '{'. Symbol Index: 90
    0x0, 0x0, 0x70, 0x0, 0x1C, 0x80, 0x3, 0x60, 0x0, 0x18,
    0x0, 0x6, 0x80, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x6, 0x80,
    0x1, 0x60, 0x0, 0x18, 0x0, 0xE, 0x0, 0x7, 0xC0, 0x1,
    0x0, 0x0,

    //Symbol: 124  or '|'. Symbol Index: 91
    0x0, 0x0, 0x30, 0x0, 0xC, 0x0, 0x3, 0xC0, 0x0, 0x30,
    0x0, 0xC, 0x0, 0x3, 0xC0, 0x0, 0x30, 0x0, 0xC, 0x0,
    0x3, 0xC0, 0x0, 0x30, 0x0, 0xC, 0x0, 0x3, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 125  or '}'. Symbol Index: 92
    0x0, 0x0, 0xC, 0x0, 0x7, 0x80, 0x1, 0x60, 0x0, 0x18,
    0x0, 0x6, 0x80, 0x1, 0xE0, 0x1, 0x78, 0x0, 0x6, 0x80,
    0x1, 0x60, 0x0, 0x18, 0x0, 0x6, 0xC0, 0x1, 0x30, 0x0,
    0x0, 0x0,

    //Symbol: 126  or '~'. Symbol Index: 93
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xE0, 0x33, 0xDC, 0xD, 0xE3, 0x3, 0x70, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 127 . Symbol Index: 94
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 128 . Symbol Index: 95
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 129 . Symbol Index: 96
    0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1, 0x70,
    0x0, 0x1C, 0x0, 0x7, 0xC0, 0x3F, 0xF0, 0xF, 0xFC, 0x3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 130 . Symbol Index: 97
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xC0, 0x3F, 0xF0, 0xF, 0xFC, 0x3,
    0x7, 0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1,
    0x70, 0x0,

    //Symbol: 131 . Symbol Index: 98
    0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1, 0x70,
    0x0, 0x1C, 0x0, 0x7, 0xFF, 0xC1, 0x7F, 0xF0, 0x1F, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 132 . Symbol Index: 99
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xFF, 0xC1, 0x7F, 0xF0, 0x1F, 0x0,
    0x7, 0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1,
    0x70, 0x0,

    //Symbol: 133 . Symbol Index: 100
    0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1, 0x70,
    0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0,
    0x7, 0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1,
    0x70, 0x0,

    //Symbol: 134 . Symbol Index: 101
    0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1, 0x70,
    0x0, 0x1C, 0x0, 0x7, 0xC0, 0x3F, 0xF0, 0xF, 0xFC, 0x3,
    0x7, 0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1,
    0x70, 0x0,

    //Symbol: 135 . Symbol Index: 102
    0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1, 0x70,
    0x0, 0x1C, 0x0, 0x7, 0xFF, 0xC1, 0x7F, 0xF0, 0x1F, 0x0,
    0x7, 0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1,
    0x70, 0x0,

    //Symbol: 136 . Symbol Index: 103
    0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1, 0x70,
    0x0, 0x1C, 0x0, 0x7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 137 . Symbol Index: 104
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3,
    0x7, 0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1,
    0x70, 0x0,

    //Symbol: 138 . Symbol Index: 105
    0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1, 0x70,
    0x0, 0x1C, 0x0, 0x7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3,
    0x7, 0xC0, 0x1, 0x70, 0x0, 0x1C, 0x0, 0x7, 0xC0, 0x1,
    0x70, 0x0,

    //Symbol: 139 . Symbol Index: 106
    0x0, 0x0, 0x0, 0xE0, 0xFF, 0xF8, 0x3F, 0x2, 0x88, 0x0,
    0x22, 0x80, 0x8, 0x20, 0x2, 0x88, 0x0, 0x22, 0x80, 0x8,
    0x20, 0x2, 0x88, 0x0, 0xE2, 0xFF, 0xF8, 0x3F, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 140 . Symbol Index: 107
    0x0, 0x0, 0x0, 0xE0, 0xFF, 0xF8, 0x3F, 0x2, 0x88, 0x0,
    0x22, 0x80, 0x8, 0x20, 0x2, 0x88, 0x0, 0x22, 0x80, 0x8,
    0x20, 0x2, 0x88, 0x0, 0xE2, 0xFF, 0xF8, 0x3F, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 141 . Symbol Index: 108
    0x0, 0x0, 0x0, 0xE0, 0xFF, 0xF8, 0x3F, 0x2, 0x88, 0x0,
    0x22, 0x80, 0x8, 0x20, 0x2, 0x88, 0x0, 0x22, 0x80, 0x8,
    0x20, 0x2, 0x88, 0x0, 0xE2, 0xFF, 0xF8, 0x3F, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 142 . Symbol Index: 109
    0x0, 0x0, 0x0, 0xE0, 0xFF, 0xF8, 0x3F, 0x2, 0x88, 0x0,
    0x22, 0x80, 0x8, 0x20, 0x2, 0x88, 0x0, 0x22, 0x80, 0x8,
    0x20, 0x2, 0x88, 0x0, 0xE2, 0xFF, 0xF8, 0x3F, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 143 . Symbol Index: 110
    0x0, 0x0, 0x0, 0xE0, 0xFF, 0xF8, 0x3F, 0x2, 0x88, 0x0,
    0x22, 0x80, 0x8, 0x20, 0x2, 0x88, 0x0, 0x22, 0x80, 0x8,
    0x20, 0x2, 0x88, 0x0, 0xE2, 0xFF, 0xF8, 0x3F, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 144 . Symbol Index: 111
    0x0, 0x0, 0x0, 0xE0, 0xFF, 0xF8, 0x3F, 0x2, 0x88, 0x0,
    0x22, 0x80, 0x8, 0x20, 0x2, 0x88, 0x0, 0x22, 0x80, 0x8,
    0x20, 0x2, 0x88, 0x0, 0xE2, 0xFF, 0xF8, 0x3F, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 145 . Symbol Index: 112
    0x0, 0x0, 0x0, 0xE0, 0xFF, 0xF8, 0x3F, 0x2, 0x88, 0x0,
    0x22, 0x80, 0x8, 0x20, 0x2, 0x88, 0x0, 0x22, 0x80, 0x8,
    0x20, 0x2, 0x88, 0x0, 0xE2, 0xFF, 0xF8, 0x3F, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 146 . Symbol Index: 113
    0x0, 0x0, 0x0, 0xE0, 0xFF, 0xF8, 0x3F, 0x2, 0x88, 0x0,
    0x22, 0x80, 0x8, 0x20, 0x2, 0x88, 0x0, 0x22, 0x80, 0x8,
    0x20, 0x2, 0x88, 0x0, 0xE2, 0xFF, 0xF8, 0x3F, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 147 . Symbol Index: 114
    0x0, 0x0, 0x0, 0xF8, 0x3F, 0xFF, 0x27, 0x80, 0x4, 0x90,
    0x0, 0x12, 0x40, 0x2, 0x48, 0x0, 0x9, 0x20, 0x1, 0x24,
    0x80, 0x4, 0x90, 0xFF, 0xF3, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 148 . Symbol Index: 115
    0x0, 0x0, 0x0, 0xF8, 0x3F, 0xFF, 0x27, 0x80, 0x4, 0x90,
    0x0, 0x12, 0x40, 0x2, 0x48, 0x0, 0x9, 0x20, 0x1, 0x24,
    0x80, 0x4, 0x90, 0xFF, 0xF3, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 149 . Symbol Index: 116
    0x0, 0x0, 0x0, 0xF8, 0x3F, 0xFF, 0x27, 0x80, 0x4, 0x90,
    0x0, 0x12, 0x40, 0x2, 0x48, 0x0, 0x9, 0x20, 0x1, 0x24,
    0x80, 0x4, 0x90, 0xFF, 0xF3, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 150 . Symbol Index: 117
    0x0, 0x0, 0x0, 0xF8, 0x3F, 0xFF, 0x27, 0x80, 0x4, 0x90,
    0x0, 0x12, 0x40, 0x2, 0x48, 0x0, 0x9, 0x20, 0x1, 0x24,
    0x80, 0x4, 0x90, 0xFF, 0xF3, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 151 . Symbol Index: 118
    0x0, 0x0, 0x0, 0xF8, 0x3F, 0xFF, 0x27, 0x80, 0x4, 0x90,
    0x0, 0x12, 0x40, 0x2, 0x48, 0x0, 0x9, 0x20, 0x1, 0x24,
    0x80, 0x4, 0x90, 0xFF, 0xF3, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 152 . Symbol Index: 119
    0x0, 0x0, 0x0, 0xF8, 0x3F, 0xFF, 0x27, 0x80, 0x4, 0x90,
    0x0, 0x12, 0x40, 0x2, 0x48, 0x0, 0x9, 0x20, 0x1, 0x24,
    0x80, 0x4, 0x90, 0xFF, 0xF3, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 153 . Symbol Index: 120
    0x0, 0x0, 0x0, 0xF8, 0x3F, 0xFF, 0x27, 0x80, 0x4, 0x90,
    0x0, 0x12, 0x40, 0x2, 0x48, 0x0, 0x9, 0x20, 0x1, 0x24,
    0x80, 0x4, 0x90, 0xFF, 0xF3, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 154 . Symbol Index: 121
    0x0, 0x0, 0x0, 0xF8, 0x3F, 0xFF, 0x27, 0x80, 0x4, 0x90,
    0x0, 0x12, 0x40, 0x2, 0x48, 0x0, 0x9, 0x20, 0x1, 0x24,
    0x80, 0x4, 0x90, 0xFF, 0xF3, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 155 . Symbol Index: 122
    0x0, 0x0, 0x0, 0xF8, 0x3F, 0xFF, 0x27, 0x80, 0x4, 0x90,
    0x0, 0x12, 0x40, 0x2, 0x48, 0x0, 0x9, 0x20, 0x1, 0x24,
    0x80, 0x4, 0x90, 0xFF, 0xF3, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 156 . Symbol Index: 123
    0x0, 0x0, 0x0, 0xF8, 0x3F, 0xFF, 0x27, 0x80, 0x4, 0x90,
    0x0, 0x12, 0x40, 0x2, 0x48, 0x0, 0x9, 0x20, 0x1, 0x24,
    0x80, 0x4, 0x90, 0xFF, 0xF3, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 157 . Symbol Index: 124
    0x0, 0x0, 0x0, 0xF8, 0x3F, 0xFF, 0x27, 0x80, 0x4, 0x90,
    0x0, 0x12, 0x40, 0x2, 0x48, 0x0, 0x9, 0x20, 0x1, 0x24,
    0x80, 0x4, 0x90, 0xFF, 0xF3, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 158 . Symbol Index: 125
    0x0, 0x0, 0x0, 0xF8, 0x3F, 0xFF, 0x27, 0x80, 0x4, 0x90,
    0x0, 0x12, 0x40, 0x2, 0x48, 0x0, 0x9, 0x20, 0x1, 0x24,
    0x80, 0x4, 0x90, 0xFF, 0xF3, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 159 . Symbol Index: 126
    0x0, 0x0, 0x0, 0xF8, 0x3F, 0xFF, 0x27, 0x80, 0x4, 0x90,
    0x0, 0x12, 0x40, 0x2, 0x48, 0x0, 0x9, 0x20, 0x1, 0x24,
    0x80, 0x4, 0x90, 0xFF, 0xF3, 0x7F, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    //Symbol: 160  or ' '. Symbol Index: 127
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

};

FONT_INFO font_std(void)
{
    FONT_INFO header;
    header.data = (uint16_t)font_std_data;
    header.maxXSize = pgm_read_byte_near(header.data);
    header.maxYSize = pgm_read_byte_near(header.data + 1);
    header.startChar = pgm_read_byte_near(header.data + 2);
    header.endChar = pgm_read_byte_near(header.data + 3);
    header.bytesPerSymbol = (uint16_t)ceil(header.maxXSize * header.maxYSize / 8.0);
    header.color = TFT_BLUE;
    return header;
}

#endif
