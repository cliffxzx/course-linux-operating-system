# Linux Operating System Course

## PROJECT 1: Add `segment_info` system call to get thread segments information

### [Write Up](project1/README.md)

In this project, added system call `segment_info` was run under qemu with [busybox 1.35.0](https://github.com/mirror/busybox) and [linux kernel 6.0.5](https://lwn.net/Articles/912506/). You can compile and run the program [main.c](project1/main.c), linux kernel to check how does the thread segment arrange by following [these steps](project1/README.md).

Below is the sample output:

```
...
>>>>>> '0x7ffc10bc1000'-'0x7ffc10bc5000' unknown [vvar]
>>>>>> '0x7ffc10bc5000'-'0x7ffc10bc7000' unknown [vdso]
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
˅˅˅˅˅˅˅˅˅˅˅˅˅˅˅ [User Mode] t2 thread id: 79 ˅˅˅˅˅˅˅˅˅˅˅˅˅˅
>>>>>> [code]:          '0x401845'
>>>>>> [data]:          '0x4e1110'
>>>>>> [bss]:           '0x4e33d0'
>>>>>> [heap]:          '0x1d16770'
>>>>>> [mmap]:          '0x7fa3955d4000'
>>>>>> [stack]:         '0x7fa394dd215a'
>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<
>>>>>> <start_code>:    '0x401000'
>>>>>> <end_code>:      '0x4b099d'
>>>>>> <start_data>:    '0x4dd768'
>>>>>> <end_data>:      '0x4e3370'
>>>>>> <start_brk>:     '0x1d15000'
>>>>>> <brk>:           '0x1d37000'
>>>>>> <mmap_base>:     '0x7fa3955d5000'
>>>>>> <thread_sp>:     '0x7fa394dd1d18'
>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<
>>>>>> '0x400000'-'0x401000' unknown
>>>>>> '0x401000'-'0x4b1000' code/text segment
>>>>>> '0x4b1000'-'0x4dd000' unknown
>>>>>> '0x4dd000'-'0x4e1000' data segment
>>>>>> '0x4e1000'-'0x4e4000' data segment
>>>>>> '0x4e4000'-'0x4ea000' bss segment
>>>>>> '0x1d15000'-'0x1d37000' heap segment
>>>>>> '0x7fa3945d2000'-'0x7fa3945d3000' mmap segment(shared library, thread stack...)
>>>>>> '0x7fa3945d3000'-'0x7fa394dd3000' t2 stack segment
>>>>>> '0x7fa394dd3000'-'0x7fa394dd4000' mmap segment(shared library, thread stack...)
>>>>>> '0x7fa394dd4000'-'0x7fa3955d5000' mmap segment(shared library, thread stack...)
>>>>>> '0x7ffc10a7f000'-'0x7ffc10aa0000' unknown
>>>>>> '0x7ffc10bc1000'-'0x7ffc10bc5000' unknown [vvar]
>>>>>> '0x7ffc10bc5000'-'0x7ffc10bc7000' unknown [vdso]
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
˅˅˅˅˅˅˅˅˅˅˅˅˅˅˅ [User Mode] t1 thread id: 78 ˅˅˅˅˅˅˅˅˅˅˅˅˅˅
>>>>>> [code]:          '0x401845'
>>>>>> [data]:          '0x4e1110'
>>>>>> [bss]:           '0x4e33d0'
>>>>>> [heap]:          '0x1d16770'
...
```
