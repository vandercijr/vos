//basic io routines
#include "vga.h"
#include "screen.h"
#include "../includes/string.c"

char * _DefaultIoAddr = (char *)VGA_MODE_ADDR;
char * _CurrentIoAddr;
struct position cursor;

void setIoAddr(char * _IoAddr)
{
  if (_IoAddr) _CurrentIoAddr = _IoAddr;
}

void printc(char ch)
{
  cursor = getCursor();

  int address_index = (cursor.y * NUM_OF_COLS + cursor.x) * SCREEN_OFFSET;

  _CurrentIoAddr[address_index] = ch;
  _CurrentIoAddr[address_index+1] = ch;

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

void clear()
{
}

int isCursorLimitY(unsigned y)
{
  return y > NUM_OF_ROWS;
}

int isCursorLimitX(unsigned x)
{
  return x > NUM_OF_COLS;
}

void setCursor(struct position _position)
{
  cursor = _position;
}

struct position getCursor()
{
  return cursor;
}
