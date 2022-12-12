# Hands-on

Please refer to [project-1 hands-on](../project1/README.md.

Not much changed. Replacing multi-thread from project1/main.c with single-thread and sleep 10s

Modifying $PROJECT from `project1` to `/home/cliff/projects/course-linux-operating-system/project2`

Testing command in qemu:

```shell
hush -c /mnt/host_share/main & /mnt/host_share/main && fg
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
