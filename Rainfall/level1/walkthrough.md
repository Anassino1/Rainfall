1)))))))))))))))))))))))))

level1@RainFall:~$ ls -la
total 17
dr-xr-x---+ 1 level1 level1   80 Mar  6  2016 .
dr-x--x--x  1 root   root    340 Sep 23  2015 ..
-rw-r--r--  1 level1 level1  220 Apr  3  2012 .bash_logout
-rw-r--r--  1 level1 level1 3530 Sep 23  2015 .bashrc
-rwsr-s---+ 1 level2 users  5138 Mar  6  2016 level1
-rw-r--r--+ 1 level1 level1   65 Sep 23  2015 .pass
-rw-r--r--  1 level1 level1  675 Apr  3  2012 .profile

That means SUID bit is set. When we run ./level1, it runs with the privileges of level2, not level1.
So even though we are level1, the program runs as level2.

2))))))))))))))))))))))))))

let's check the functions inside GDB

gdb) info functions
All defined functions:

Non-debugging symbols:
0x080482f8  _init                                             Internal System Functions (Not Useful)
0x08048340  gets                                              Library Functions
0x08048340  gets@plt
0x08048350  fwrite                                            Library Functions
0x08048350  fwrite@plt
0x08048360  system                                            Library Functions
0x08048360  system@plt
0x08048370  __gmon_start__
0x08048370  __gmon_start__@plt
0x08048380  __libc_start_main                                 Internal System Functions (Not Useful)
0x08048380  __libc_start_main@plt
0x08048390  _start                                            Internal System Functions (Not Useful)
0x080483c0  __do_global_dtors_aux
0x08048420  frame_dummy                                       Internal System Functions (Not Useful)
0x08048444  run                                               Custom Functions (Interesting!)
0x08048480  main                                              Custom Functions (Interesting!)
0x080484a0  __libc_csu_init                                   Internal System Functions (Not Useful)
0x08048510  __libc_csu_fini
0x08048512  __i686.get_pc_thunk.bx
0x08048520  __do_global_ctors_aux





Inside main() we saw: gets() is extremely dangerous because: It reads input, It keeps reading until newline, It DOES NOT check buffer size.
"The gets() function is a deprecated and unsafe C standard library function used to read a line of text from the standard input (stdin). It is no longer part of the official C11 standard and subsequent ones due to a critical security vulnerability."

So if the buffer is 64 bytes… And we send 200 bytes… It will happily overwrite everything. caled: "Stack Buffer Overflow"