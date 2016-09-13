OUTPUT_FORMAT(elf32-i386)
ENTRY(_boot)
SECTIONS
{
 . = 0x100000;
 .data : {*(.data)}
 .code : {*(.code)}
 .bss  : {*(.bss)}
}
