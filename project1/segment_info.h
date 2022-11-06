struct ma_struct
{
	unsigned long vm_start, vm_end;
	char name[24];
};

struct segment_info
{
	unsigned long start_code, end_code;
	unsigned long start_data, end_data;
	unsigned long start_brk, brk;
	unsigned long start_stack, end_stack;
	unsigned long thread_sp;
	unsigned long mmap_base;
	unsigned long ma_size;
	struct ma_struct ma[24];
};
