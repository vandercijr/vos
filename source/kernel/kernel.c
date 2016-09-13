#define VGA_VIDEO_MEM_ADDR 0xB8000;

kernel_main_func()
{
  char* video = (char *)VGA_VIDEO_MEM_ADDR;

  video[0] = 'W';
  video[2] = 'E';
  video[4] = 'L';
  video[6] = 'C';
  video[8] = 'O';
  video[10] = 'M';
  video[12] = 'E';
  video[14] = 0x00;
  video[16] = 'T';
  video[18] = 'O';  
  video[20] = 'V';
  video[22] = 'O';
  video[24] = 'S';
  video[26] = 0x07;
}
