#include "string.h"

unsigned int strlen(char * data)
{
  unsigned i = 0;
  while(data[i]) i++;

  return i;
}
