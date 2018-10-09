#ifndef _tft_hardware_h_
#define _tft_hardware_h_

#include "bitwise.h"

#define gr_param_voltage_VREG1_halt  0b00000000
#define gr_param_voltage_VREG1_4v    0b00000001
#define gr_param_voltage_VREG1_4125v 0b00000010
#define gr_param_voltage_VREG1_4250v 0b00000011
#define gr_param_voltage_VREG1_4375v 0b00000100
#define gr_param_voltage_VREG1_4500v 0b00000101
#define gr_param_voltage_VREG1_4625v 0b00000110
#define gr_param_voltage_VREG1_4750v 0b00000111
#define gr_param_voltage_VREG1_4875v 0b00001000
#define gr_param_voltage_VREG1_5000v 0b00001001
#define gr_param_voltage_VREG1_5125v 0b00001010
#define gr_param_voltage_VREG1_5250v 0b00001011
#define gr_param_voltage_VREG1_5500v 0b00001100
#define gr_param_voltage_VREG1_5750v 0b00001101
#define gr_param_voltage_VREG1_6000v 0b00001110
#define gr_param_voltage_VREG1_6250v 0b00001111
#define gr_param_voltage_VC1_324V 0b00000111
#define gr_param_voltage_VC1_306V 0b00010111
#define gr_param_voltage_VC1_291V 0b00100111
#define gr_param_voltage_VC1_277V 0b00110111
#define gr_param_voltage_VC1_264V 0b01000111
#define gr_param_voltage_VC1_247V 0b01010111
#define gr_param_voltage_VC1_192V 0b01100111
#define gr_param_voltage_VC1_VCI  0b01110111
#define gr_param_vcom_vcm(x) (x-492)/4
#define gr_param_vcom_vdv(x) (x-70)/2
#define gr_param_pixelformat_notdefined 0b00000000
#define gr_param_pixelformat_3bpp       0b00010001
#define gr_param_pixelformat_16bpp      0b01010101
#define gr_param_pixelformat_18bpp      0b01100110
#define gr_param_frameRate_17981 0b00000000
#define gr_param_frameRate_22366 0b00000001
#define gr_param_frameRate_26673 0b00000010
#define gr_param_frameRate_30995 0b00000011
#define gr_param_frameRate_35198 0b00000100
#define gr_param_frameRate_39402 0b00000101
#define gr_param_frameRate_43609 0b00000110
#define gr_param_frameRate_47758 0b00000111
#define gr_param_frameRate_52000 0b00001000
#define gr_param_frameRate_55791 0b00001001
#define gr_param_frameRate_59986 0b00001010
#define gr_param_frameRate_64398 0b00001011
#define gr_param_frameRate_68374 0b00001100
#define gr_param_frameRate_72101 0b00001101
#define gr_param_frameRate_76100 0b00001111
#define gr_param_frameRate_80426 0b00001111

//commands
#define gr_c_setDisplayOff 0x28
#define gr_c_setDisplayOn 0x29
#define gr_c_sleepOut 0x11
#define gr_c_setPower 0xD0
#define gr_c_setPanelDriving 0xC0
#define gr_c_setPowerForNormalMode 0xD2
#define gr_c_setVCOM  0xD1
#define gr_c_setDisplayFrame 0xC5
#define gr_c_setGamma 0xC8
#define gr_c_setAddressMode 0x36
#define gr_c_setClumnAddress 0x2A
#define gr_c_setPixelFormat 0x3A
#define gr_c_setPageAddress 0x2B
#define gr_c_WriteRam 0x2C
#define gr_c_setBrightness 0x51

#define gr_c_enterInversionMode 0x21
#define gr_c_exitInversionMode 0x20
#define gr_c_setScrollStart 0x37
#define gr_c_setScrollArea 0x33

//orientations
#define gr_MADCTL_MY  0x80
#define gr_MADCTL_MX  0x40
#define gr_MADCTL_MV  0x20
#define gr_MADCTL_ML  0x10
#define gr_MADCTL_RGB 0x00
#define gr_MADCTL_BGR 0x08
#define gr_MADCTL_SS  0x02
#define gr_MADCTL_GS  0x01

#define gr_TFTWIDTH 480
#define gr_TFTHEIGHT 320

#define gr_h_CS(x) bitw_sset(PORTG, 1, x)
#define gr_h_WR(x) bitw_sset(PORTG, 2, x)
#define gr_h_RST(x) bitw_sset(PORTG, 0, x)
#define gr_h_RS(x) bitw_sset(PORTD, 7, x)

#define gr_h_RS_H bitw_set(PORTD, 7)
#define gr_h_RS_L bitw_clear(PORTD, 7)
#define gr_h_CS_H bitw_set(PORTG, 1)
#define gr_h_CS_L bitw_clear(PORTG,1)
#define gr_h_WR_H bitw_set(PORTG, 2)
#define gr_h_WR_L bitw_clear(PORTG, 2)
#define gr_h_WR_STB {gr_h_WR_L;gr_h_WR_H;}

#define gr_h_DB15(x) bitw_sset(PORTA, 7, x)
#define gr_h_DB14(x) bitw_sset(PORTA, 6, x)
#define gr_h_DB13(x) bitw_sset(PORTA, 5, x)
#define gr_h_DB12(x) bitw_sset(PORTA, 4, x)
#define gr_h_DB11(x) bitw_sset(PORTA, 3, x)
#define gr_h_DB10(x) bitw_sset(PORTA, 2, x)
#define gr_h_DB9(x) bitw_sset(PORTA, 1, x)
#define gr_h_DB8(x) bitw_sset(PORTA, 0, x)
#define gr_h_DB7(x) bitw_sset(PORTC, 7, x)
#define gr_h_DB6(x) bitw_sset(PORTC, 6, x)
#define gr_h_DB5(x) bitw_sset(PORTC, 5, x)
#define gr_h_DB4(x) bitw_sset(PORTC, 4, x)
#define gr_h_DB3(x) bitw_sset(PORTC, 3, x)
#define gr_h_DB2(x) bitw_sset(PORTC, 2, x)
#define gr_h_DB1(x) bitw_sset(PORTC, 1, x)
#define gr_h_DB0(x) bitw_sset(PORTC, 0, x)

#endif
