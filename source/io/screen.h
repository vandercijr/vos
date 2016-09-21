//basic io routines
#ifndef SCREEN_H
#define SCREEN_H
struct position {
 unsigned int x;
 unsigned int y;
};
void setIoAddr(char* _IoAddr);
void print(char* data);
void printc(char ch);
void clear();
void setCursor(struct position _position);
struct position getCursor();
int isCursorLimitY(unsigned y);
int isCursorLimitX(unsigned x);
#endif
