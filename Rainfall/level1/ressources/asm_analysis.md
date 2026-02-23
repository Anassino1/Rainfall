0x08048480 <+0>:	push   %ebp
0x08048481 <+1>:	mov    %esp,%ebp                        Standard stack frame setup.
0x08048483 <+3>:	and    $0xfffffff0,%esp                                   Align stack to 16 bytes. 
0x08048486 <+6>:	sub    $0x50,%esp                       0x50 = 80 bytes so the function reserves 80 bytes on the stack.
0x08048489 <+9>:	lea    0x10(%esp),%eax                     EAX = ESP + 0x10 So the buffer does NOT start exactly at ESP. ESP + 16 bytes
0x0804848d <+13>:	mov    %eax,(%esp)
0x08048490 <+16>:	call   0x8048340 <gets@plt>                it reads input, It does NOT check length, It allows unlimited overflow
0x08048495 <+21>:	leave  
0x08048496 <+22>:	ret                                  <+21> - <+22> : These two lines allow us to find the state of the registers before executing the function. In others terms we quit the main() function.

