
.*:     file format.*


Disassembly of section destsect:

00108004 <[^>]*>:
  108004:	f7ff fffe 	bl	108004 <dest>

Disassembly of section .text:

000080.. <[^>]*>:
    80..:	(8002f040|f0408002) 	.word	0x(8002f040|f0408002)
    80..:	0000      	movs	r0, r0
	...

000080.. <[^>]*>:
    80..:	f85f f000 	ldr.w	pc, \[pc\]	; 800c <__dest_veneer\+0x4>
    80..:	00108005 	.word	0x00108005
