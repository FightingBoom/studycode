
int printf( const char* format, ...);

int global_init_var = 84;
int global_uninit_var;

void func1( int i )
{
    printf("%d\n", i);
}

int main(void)
{
    static int static_var = 85;
    static int static_var2;

    int a = 1;
    int b;

    func1(static_var + static_var2 + a + b);

    return a;
}


/*
zhaochen@zhaochendeAir code_3.01 % gcc -c SimpleSection.c    
zhaochen@zhaochendeAir code_3.01 % objdump -h SimpleSection.o

SimpleSection.o:        file format mach-o arm64

Sections:
Idx Name             Size     VMA              Type
  0 __text           00000088 0000000000000000 TEXT
  1 __data           00000008 0000000000000088 DATA
  2 __cstring        00000004 0000000000000090 DATA
  3 __bss            00000004 00000000000000d8 BSS
  4 __compact_unwind 00000040 0000000000000098 DATA
zhaochen@zhaochendeAir code_3.01 %
*/

/*
zhaochen@zhaochendeAir code_3.01 % size SimpleSection.o 
__TEXT  __DATA  __OBJC  others  dec     hex
140     12      0       64      216     d8
zhaochen@zhaochendeAir code_3.01 %
*/

/*
zhaochen@zhaochendeAir code_3.01 % objdump -s -d SimpleSection.o 

SimpleSection.o:        file format mach-o arm64
Contents of section __TEXT,__text:
 0000 ff8300d1 fd7b01a9 fd430091 a0c31fb8  .....{...C......
 0010 a9c35fb8 e80309aa e9030091 280100f9  .._.........(...
 0020 00000090 00000091 00000094 fd7b41a9  .............{A.
 0030 ff830091 c0035fd6 ff8300d1 fd7b01a9  ......_......{..
 0040 fd430091 bfc31fb8 28008052 e80b00b9  .C......(..R....
 0050 08000090 080140b9 09000090 290140b9  ......@.....).@.
 0060 0801090b e90b40b9 0801090b e90740b9  ......@.......@.
 0070 0001090b 00000094 e00b40b9 fd7b41a9  ..........@..{A.
 0080 ff830091 c0035fd6                    ......_.
Contents of section __DATA,__data:
 0088 54000000 55000000                    T...U...
Contents of section __TEXT,__cstring:
 0090 25640a00                             %d..
Contents of section __DATA,__bss:
<skipping contents of bss section at [00d8, 00dc)>
Contents of section __LD,__compact_unwind:
 0098 00000000 00000000 38000000 00000004  ........8.......
 00a8 00000000 00000000 00000000 00000000  ................
 00b8 38000000 00000000 50000000 00000004  8.......P.......
 00c8 00000000 00000000 00000000 00000000  ................

Disassembly of section __TEXT,__text:

0000000000000000 <ltmp0>:
       0: d10083ff      sub     sp, sp, #0x20
       4: a9017bfd      stp     x29, x30, [sp, #0x10]
       8: 910043fd      add     x29, sp, #0x10
       c: b81fc3a0      stur    w0, [x29, #-0x4]
      10: b85fc3a9      ldur    w9, [x29, #-0x4]
      14: aa0903e8      mov     x8, x9
      18: 910003e9      mov     x9, sp
      1c: f9000128      str     x8, [x9]
      20: 90000000      adrp    x0, 0x0 <ltmp0>
      24: 91000000      add     x0, x0, #0x0
      28: 94000000      bl      0x28 <ltmp0+0x28>
      2c: a9417bfd      ldp     x29, x30, [sp, #0x10]
      30: 910083ff      add     sp, sp, #0x20
      34: d65f03c0      ret

0000000000000038 <_main>:
      38: d10083ff      sub     sp, sp, #0x20
      3c: a9017bfd      stp     x29, x30, [sp, #0x10]
      40: 910043fd      add     x29, sp, #0x10
      44: b81fc3bf      stur    wzr, [x29, #-0x4]
      48: 52800028      mov     w8, #0x1                ; =1
      4c: b9000be8      str     w8, [sp, #0x8]
      50: 90000008      adrp    x8, 0x0 <ltmp0>
      54: b9400108      ldr     w8, [x8]
      58: 90000009      adrp    x9, 0x0 <ltmp0>
      5c: b9400129      ldr     w9, [x9]
      60: 0b090108      add     w8, w8, w9
      64: b9400be9      ldr     w9, [sp, #0x8]
      68: 0b090108      add     w8, w8, w9
      6c: b94007e9      ldr     w9, [sp, #0x4]
      70: 0b090100      add     w0, w8, w9
      74: 94000000      bl      0x74 <_main+0x3c>
      78: b9400be0      ldr     w0, [sp, #0x8]
      7c: a9417bfd      ldp     x29, x30, [sp, #0x10]
      80: 910083ff      add     sp, sp, #0x20
      84: d65f03c0      ret
zhaochen@zhaochendeAir code_3.01 %
*/
