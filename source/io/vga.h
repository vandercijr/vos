#ifndef VGA_H
#define VGA_H
#define VGA_VIDEO_MEM_ADDR           0xB8000
/*
 attribute byte :

 bit 0-2 : foreground (red, green, blue)
 bit 3   : foreground intensity
 bit 4-6 : background color (red, green blue)
 bit 7   : background intensity or blink
*/
#define VGA_VIDEO_ATTRIBUTE_BYTE_BW  0x7
//
#define NUM_OF_ROWS                  24
#define NUM_OF_COLS                  80
#define SCREEN_OFFSET                2  //VGA mode 7 uses 2 bytes for character. One for character, and one for attribute
#endif
