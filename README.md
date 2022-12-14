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

## PROJECT 2: Check how memory areas are shared by two processes that execute this program simultaneously

### [Write Up](project2/README.md)

Replacing multi-thread from project1/main.c with single-thread and sleep 10s

Modifying $PROJECT from `project1` to `/home/cliff/projects/course-linux-operating-system/project2`

Testing command in qemu:

```shell
hush -c '/mnt/host_share/main & /mnt/host_share/main'
```

## Output

```shell
˅˅˅˅˅˅˅˅˅˅˅˅˅˅˅ [User Mode] main thread id: 126 ˅˅˅˅˅˅˅˅˅˅˅˅˅˅
>>>>>> [code]:          '0x4017b5' -> '0x5c25000'
>>>>>> [data]:          '0x4c70f0' -> '0x6334000'
>>>>>> [bss]:           '0x4c93b0' -> '0x631a000'
>>>>>> [heap]:          '0x100b780' -> '0x5c07000'
>>>>>> [mmap]:          '0x7f3210b8a000' -> '0x631d000'
>>>>>> [lib]:           '0x40bf90' -> '0x40bf90'
>>>>>> [stack]:         '0x7ffeb725718a' -> '0x63ef000'
>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<
>>>>>> <start_code>:    '0x401000'
>>>>>> <end_code>:      '0x49885d'
>>>>>> <start_data>:    '0x4c37b0'
>>>>>> <end_data>:      '0x4c9350'
>>>>>> <start_brk>:     '0x1009000'
>>>>>> <brk>:           '0x102b000'
>>>>>> <mmap_base>:     '0x7f3210b8b000'
>>>>>> <thread_sp>:     '0x7ffeb7256d48'
>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<
>>>>>> '0x400000'-'0x401000' unknown
>>>>>> '0x401000'-'0x499000' code/text segment
>>>>>> '0x499000'-'0x4c2000' unknown
>>>>>> '0x4c3000'-'0x4c7000' data segment
>>>>>> '0x4c7000'-'0x4ca000' data segment
>>>>>> '0x4ca000'-'0x4cf000' bss segment
>>>>>> '0x1009000'-'0x102b000' heap segment
>>>>>> '0x7f3210b8a000'-'0x7f3210b8b000' mmap segment(shared library, thread stack...)
>>>>>> '0x7ffeb7237000'-'0x7ffeb7258000' main stack segment
>>>>>> '0x7ffeb72a1000'-'0x7ffeb72a5000' unknown [vvar]
>>>>>> '0x7ffeb72a5000'-'0x7ffeb72a7000' unknown [vdso]
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
˅˅˅˅˅˅˅˅˅˅˅˅˅˅˅ [User Mode] main thread id: 125 ˅˅˅˅˅˅˅˅˅˅˅˅˅˅
>>>>>> [code]:          '0x4017b5' -> '0x5c25000'
>>>>>> [data]:          '0x4c70f0' -> '0x631e000'
>>>>>> [bss]:           '0x4c93b0' -> '0x632e000'
>>>>>> [heap]:          '0x5df780' -> '0x5c23000'
>>>>>> [mmap]:          '0x7fadf6258000' -> '0x6b92000'
>>>>>> [lib]:           '0x40bf90' -> '0x40bf90'
>>>>>> [stack]:         '0x7ffd18286aea' -> '0x63ec000'
>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<
>>>>>> <start_code>:    '0x401000'
>>>>>> <end_code>:      '0x49885d'
>>>>>> <start_data>:    '0x4c37b0'
>>>>>> <end_data>:      '0x4c9350'
>>>>>> <start_brk>:     '0x5dd000'
>>>>>> <brk>:           '0x5ff000'
>>>>>> <mmap_base>:     '0x7fadf6259000'
>>>>>> <thread_sp>:     '0x7ffd182866a8'
>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<
>>>>>> '0x400000'-'0x401000' unknown
>>>>>> '0x401000'-'0x499000' code/text segment
>>>>>> '0x499000'-'0x4c2000' unknown
>>>>>> '0x4c3000'-'0x4c7000' data segment
>>>>>> '0x4c7000'-'0x4ca000' data segment
>>>>>> '0x4ca000'-'0x4cf000' bss segment
>>>>>> '0x5dd000'-'0x5ff000' heap segment
>>>>>> '0x7fadf6258000'-'0x7fadf6259000' mmap segment(shared library, thread stack...)
>>>>>> '0x7ffd18267000'-'0x7ffd18288000' main stack segment
>>>>>> '0x7ffd1830f000'-'0x7ffd18313000' unknown [vvar]
>>>>>> '0x7ffd18313000'-'0x7ffd18315000' unknown [vdso]
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
```
