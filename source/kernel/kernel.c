#include "../io/screen.c"

kernel_main_func()
{
  setIoAddr(_DefaultIoAddr);

  clear();
  print("WELCOME TO VOS");

}
