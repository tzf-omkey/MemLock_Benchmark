#PROG: strip
#source: empty.s
#strip: -R .text -R .data -R .bss -R .ARM.attributes -R .reginfo -R .gnu.attributes -R .MIPS.abiflags -R .pdr -R .xtensa.info -R .ARC.attributes
#readelf: -S --wide
#name: strip empty file
#target: *-*-linux* *-*-gnu* arm*-*-uclinuxfdpiceabi

#...
  \[[ 0]+\][ \t]+NULL[ \t]+.*
  \[[ 1]+\] \.shstrtab.*[ \t]+STRTAB[ \t]+.*
#pass
