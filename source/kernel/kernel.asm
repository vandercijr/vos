;VOS bootloader
;developed by vanderci curvelo junior
;vandercijr@gmail.com
;2016
bits 32 ;32 BITS OS

section   .data

BAD_BOOT_ADDR equ 0x1BADB002 ;multiple b
BOOT_FLAG     equ 0x00
BOOT_CHECKSUM equ - (BAD_BOOT_ADDR+BOOT_FLAG)

section   .text

  align   4                ; enforce addresses being aligned by 4 bytes (32bits)
  ;define the multiboot header (m+f+c) in this case result is 0
  dd      BAD_BOOT_ADDR
  dd      BOOT_FLAG
  dd      BOOT_CHECKSUM

  global  _boot
  extern  kernel_main_func ;define main as an external function

_boot:
  cli                      ;clear interrupts
  call kernel_main_func    ;call SO C main function defined in kernel.c
  hlt                      ;pause CPU, idle state

