#include <linux/types.h>
#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/ptrace.h>
#include <linux/thread_info.h>
#include <asm/current.h>

#include <linux/segment_info.h>

SYSCALL_DEFINE1(segment_info, struct segment_info *, dsi)
{
  struct vm_area_struct *vma = current->mm->mmap;
  struct segment_info si = {
      .ma_size = 0,
      .start_code = current->mm->start_code,
      .end_code = current->mm->end_code,
      .start_data = current->mm->start_data,
      .end_data = current->mm->end_data,
      .start_brk = current->mm->start_brk,
      .brk = current->mm->brk,
      .mmap_base = current->mm->mmap_base,
      .thread_sp = current_user_stack_pointer(),
  };

  while (vma)
  {
    struct ma_struct *ma = si.ma + si.ma_size++;
    *ma = (struct ma_struct){
        .vm_start = vma->vm_start,
        .vm_end = vma->vm_end,
        .name = "\0",
    };

    if (vma->vm_file)
      // fs/d_path.c
      d_path(&vma->vm_file->f_path, ma->name, sizeof(ma->name));
    else if (vma->vm_ops && vma->vm_ops->name)
      strcpy(ma->name, vma->vm_ops->name(vma));

    vma = vma->vm_next;
  }

  if (copy_to_user(dsi, &si, sizeof(si)))
    return -1;

  return current->pid;
}
