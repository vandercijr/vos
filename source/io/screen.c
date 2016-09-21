//basic io routines
#include "vga.h"
#include "screen.h"
#include "../includes/chars.h"
#include "../includes/string.c"

char * _DefaultIoAddr = (char *)VGA_VIDEO_MEM_ADDR;
char * _CurrentIoAddr;
struct position cursor;

void setIoAddr(char * _IoAddr)
{
  if (_IoAddr) _CurrentIoAddr = _IoAddr;
}

void printc(char ch)
{
  struct position cursor = getCursor();

  int address_index = (cursor.y * NUM_OF_COLS + cursor.x) * SCREEN_OFFSET;

  _CurrentIoAddr[address_index] = ch;
  _CurrentIoAddr[address_index+1] = VGA_VIDEO_ATTRIBUTE_BYTE_BW;

  if (isCursorLimitY(cursor.y)) {
    //scroll
  }

  cursor.x++;
  if (isCursorLimitX(cursor.x)) {
    cursor.x = 0;
    cursor.y++;
  }

  setCursor(cursor);
}
void print(char* data)
{
  unsigned int i = 0;
  for (i; i < strlen(data); i++) {
    printc(data[i]);
  }
}

void clearLine(unsigned int line)
{
  unsigned int x = 0;
  unsigned int y = line;
  int address_index;

  for (x; x < NUM_OF_COLS;x++) {
    address_index = (y * NUM_OF_COLS + x) * SCREEN_OFFSET;
    _CurrentIoAddr[address_index]   = NUL;
  }
}

void clear()
{
  unsigned int line = 0;

  for (line; line < NUM_OF_ROWS;line++) {
    clearLine(line);
  }
}

int isCursorLimitY(unsigned y)
{
  return y > NUM_OF_ROWS-1;
}

int isCursorLimitX(unsigned x)
{
  return x > NUM_OF_COLS-1;
}

void setCursor(struct position _position)
{
  cursor = _position;
}

struct position getCursor()
{
  return cursor;
}
