#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <pthread.h>

#include "segment_info.h"

char bss[4];                    // bss
char data[5] = "data";          // data
char *heap;                     // heap
char *mmmap;                    // mmap
char *code() { return "code"; } // code

char intersect(unsigned long a1, unsigned long a2, unsigned long b1, unsigned long b2)
{
  return (b2 > a1 && b2 <= a2) || (b1 >= a1 && b1 < a2) || (b1 <= a1 && b2 > a2);
}

void print_segment_info(char *thread_name)
{
  setvbuf(stdout, NULL, _IOFBF, 16384);
  char stack[6] = "stack"; // stack

  struct segment_info si;
  printf("˅˅˅˅˅˅˅˅˅˅˅˅˅˅˅ [User Mode] %s thread id: %d ˅˅˅˅˅˅˅˅˅˅˅˅˅˅\n", thread_name, syscall(451, &si));
  printf(">>>>>> [%s]:\t\t'%p'\n", code(), &code);
  printf(">>>>>> [%s]:\t\t'%p'\n", data, &data);
  printf(">>>>>> [%s]:\t\t'%p'\n", bss, &bss);
  printf(">>>>>> [%s]:\t\t'%p'\n", heap, heap);
  printf(">>>>>> [%s]:\t\t'%p'\n", mmmap, mmmap);
  printf(">>>>>> [%s]:\t\t'%p'\n", stack, &stack);
  printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
  printf(">>>>>> <start_code>:\t'%p'\n", si.start_code);
  printf(">>>>>> <end_code>:\t'%p'\n", si.end_code);
  printf(">>>>>> <start_data>:\t'%p'\n", si.start_data);
  printf(">>>>>> <end_data>:\t'%p'\n", si.end_data);
  printf(">>>>>> <start_brk>:\t'%p'\n", si.start_brk);
  printf(">>>>>> <brk>:\t\t'%p'\n", si.brk);
  printf(">>>>>> <mmap_base>:\t'%p'\n", si.mmap_base);
  printf(">>>>>> <thread_sp>:\t'%p'\n", si.thread_sp);
  printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");

  for (int w = 0; w < si.ma_size; ++w)
  {
    char msg[100] = "unknown ";
    if (intersect(si.ma[w].vm_start, si.ma[w].vm_end, si.start_code, si.end_code))
      strcpy(msg, "code/text segment ");
    else if (intersect(si.ma[w].vm_start, si.ma[w].vm_end, si.start_data, si.end_data))
      strcpy(msg, "data segment ");
    else if (intersect(si.ma[w].vm_start, si.ma[w].vm_end, si.end_data, si.start_brk))
      strcpy(msg, "bss segment ");
    else if (intersect(si.ma[w].vm_start, si.ma[w].vm_end, si.start_brk, si.brk))
      strcpy(msg, "heap segment ");
    else if (intersect(si.ma[w].vm_start, si.ma[w].vm_end, si.thread_sp, si.thread_sp))
      sprintf(msg, "%s stack segment ", thread_name);
    else if (intersect(si.ma[w].vm_start, si.ma[w].vm_end, si.brk, si.mmap_base))
      strcpy(msg, "mmap segment(shared library, thread stack...) ");

    if (si.ma[w].name)
      sprintf(msg, "%s%s", msg, si.ma[w].name);

    printf(">>>>>> '%p'-'%p' %s\n", si.ma[w].vm_start, si.ma[w].vm_end, msg);
  }

  printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
  fflush(stdout);
}

int main()
{
  heap = (char *)malloc(sizeof(char) * 5);
  mmmap = mmap(NULL, 5 * sizeof(char), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
  strcpy(bss, "bss");
  strcpy(heap, "heap");
  strcpy(mmmap, "mmap");

  print_segment_info("main");

  pthread_t t1, t2;
  pthread_create(&t1, NULL, print_segment_info, "t1");
  pthread_create(&t2, NULL, print_segment_info, "t2");
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  free(heap);
}
