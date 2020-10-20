# 1 "arch/arm/boot/compressed/misc.c"
# 1 "<コマンドライン>"
# 1 "././include/linux/kconfig.h" 1




# 1 "./include/generated/autoconf.h" 1
# 6 "././include/linux/kconfig.h" 2
# 1 "<コマンドライン>" 2
# 1 "././include/linux/compiler_types.h" 1
# 59 "././include/linux/compiler_types.h"
# 1 "./include/linux/compiler_attributes.h" 1
# 60 "././include/linux/compiler_types.h" 2
# 68 "././include/linux/compiler_types.h"
# 1 "./include/linux/compiler-gcc.h" 1
# 69 "././include/linux/compiler_types.h" 2
# 85 "././include/linux/compiler_types.h"
struct ftrace_branch_data {
 const char *func;
 const char *file;
 unsigned line;
 union {
  struct {
   unsigned long correct;
   unsigned long incorrect;
  };
  struct {
   unsigned long miss;
   unsigned long hit;
  };
  unsigned long miss_hit[2];
 };
};

struct ftrace_likely_data {
 struct ftrace_branch_data data;
 unsigned long constant;
};
# 1 "<コマンドライン>" 2
# 1 "arch/arm/boot/compressed/misc.c"
# 20 "arch/arm/boot/compressed/misc.c"
unsigned int __machine_arch_type;

# 1 "./include/linux/compiler.h" 1




# 1 "./include/linux/compiler_types.h" 1
# 6 "./include/linux/compiler.h" 2
# 180 "./include/linux/compiler.h"
# 1 "./include/uapi/linux/types.h" 1




# 1 "./arch/arm/include/uapi/asm/types.h" 1




# 1 "./include/asm-generic/int-ll64.h" 1
# 11 "./include/asm-generic/int-ll64.h"
# 1 "./include/uapi/asm-generic/int-ll64.h" 1
# 12 "./include/uapi/asm-generic/int-ll64.h"
# 1 "./arch/arm/include/generated/uapi/asm/bitsperlong.h" 1
# 1 "./include/asm-generic/bitsperlong.h" 1




# 1 "./include/uapi/asm-generic/bitsperlong.h" 1
# 6 "./include/asm-generic/bitsperlong.h" 2
# 1 "./arch/arm/include/generated/uapi/asm/bitsperlong.h" 2
# 13 "./include/uapi/asm-generic/int-ll64.h" 2







typedef __signed__ char __s8;
typedef unsigned char __u8;

typedef __signed__ short __s16;
typedef unsigned short __u16;

typedef __signed__ int __s32;
typedef unsigned int __u32;


__extension__ typedef __signed__ long long __s64;
__extension__ typedef unsigned long long __u64;
# 12 "./include/asm-generic/int-ll64.h" 2




typedef __s8 s8;
typedef __u8 u8;
typedef __s16 s16;
typedef __u16 u16;
typedef __s32 s32;
typedef __u32 u32;
typedef __s64 s64;
typedef __u64 u64;
# 6 "./arch/arm/include/uapi/asm/types.h" 2
# 6 "./include/uapi/linux/types.h" 2
# 14 "./include/uapi/linux/types.h"
# 1 "./include/uapi/linux/posix_types.h" 1




# 1 "./include/linux/stddef.h" 1




# 1 "./include/uapi/linux/stddef.h" 1
# 6 "./include/linux/stddef.h" 2




enum {
 false = 0,
 true = 1
};
# 6 "./include/uapi/linux/posix_types.h" 2
# 25 "./include/uapi/linux/posix_types.h"
typedef struct {
 unsigned long fds_bits[1024 / (8 * sizeof(long))];
} __kernel_fd_set;


typedef void (*__kernel_sighandler_t)(int);


typedef int __kernel_key_t;
typedef int __kernel_mqd_t;

# 1 "./arch/arm/include/uapi/asm/posix_types.h" 1
# 23 "./arch/arm/include/uapi/asm/posix_types.h"
typedef unsigned short __kernel_mode_t;


typedef unsigned short __kernel_ipc_pid_t;


typedef unsigned short __kernel_uid_t;
typedef unsigned short __kernel_gid_t;


typedef unsigned short __kernel_old_dev_t;


# 1 "./include/uapi/asm-generic/posix_types.h" 1




# 1 "./arch/arm/include/generated/uapi/asm/bitsperlong.h" 1
# 6 "./include/uapi/asm-generic/posix_types.h" 2
# 15 "./include/uapi/asm-generic/posix_types.h"
typedef long __kernel_long_t;
typedef unsigned long __kernel_ulong_t;



typedef __kernel_ulong_t __kernel_ino_t;







typedef int __kernel_pid_t;
# 41 "./include/uapi/asm-generic/posix_types.h"
typedef __kernel_long_t __kernel_suseconds_t;



typedef int __kernel_daddr_t;



typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;



typedef __kernel_uid_t __kernel_old_uid_t;
typedef __kernel_gid_t __kernel_old_gid_t;
# 68 "./include/uapi/asm-generic/posix_types.h"
typedef unsigned int __kernel_size_t;
typedef int __kernel_ssize_t;
typedef int __kernel_ptrdiff_t;
# 79 "./include/uapi/asm-generic/posix_types.h"
typedef struct {
 int val[2];
} __kernel_fsid_t;





typedef __kernel_long_t __kernel_off_t;
typedef long long __kernel_loff_t;
typedef __kernel_long_t __kernel_old_time_t;



typedef long long __kernel_time64_t;
typedef __kernel_long_t __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef char * __kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
# 37 "./arch/arm/include/uapi/asm/posix_types.h" 2
# 37 "./include/uapi/linux/posix_types.h" 2
# 15 "./include/uapi/linux/types.h" 2
# 29 "./include/uapi/linux/types.h"
typedef __u16 __le16;
typedef __u16 __be16;
typedef __u32 __le32;
typedef __u32 __be32;
typedef __u64 __le64;
typedef __u64 __be64;

typedef __u16 __sum16;
typedef __u32 __wsum;
# 52 "./include/uapi/linux/types.h"
typedef unsigned __poll_t;
# 181 "./include/linux/compiler.h" 2
# 196 "./include/linux/compiler.h"
static inline __attribute__((__gnu_inline__)) __attribute__((__unused__)) __attribute__((__no_instrument_function__)) __attribute__((__always_inline__))
void __read_once_size(const volatile void *p, void *res, int size)
{
 ({ switch (size) { case 1: *(__u8 *)res = *(volatile __u8 *)p; break; case 2: *(__u16 *)res = *(volatile __u16 *)p; break; case 4: *(__u32 *)res = *(volatile __u32 *)p; break; case 8: *(__u64 *)res = *(volatile __u64 *)p; break; default: __asm__ __volatile__("": : :"memory"); __builtin_memcpy((void *)res, (const void *)p, size); __asm__ __volatile__("": : :"memory"); } });
}
# 214 "./include/linux/compiler.h"
static inline __attribute__((__gnu_inline__)) __attribute__((__unused__)) __attribute__((__no_instrument_function__)) __attribute__((__always_inline__))
void __read_once_size_nocheck(const volatile void *p, void *res, int size)
{
 ({ switch (size) { case 1: *(__u8 *)res = *(volatile __u8 *)p; break; case 2: *(__u16 *)res = *(volatile __u16 *)p; break; case 4: *(__u32 *)res = *(volatile __u32 *)p; break; case 8: *(__u64 *)res = *(volatile __u64 *)p; break; default: __asm__ __volatile__("": : :"memory"); __builtin_memcpy((void *)res, (const void *)p, size); __asm__ __volatile__("": : :"memory"); } });
}

static inline __attribute__((__gnu_inline__)) __attribute__((__unused__)) __attribute__((__no_instrument_function__)) __attribute__((__always_inline__)) void __write_once_size(volatile void *p, void *res, int size)
{
 switch (size) {
 case 1: *(volatile __u8 *)p = *(__u8 *)res; break;
 case 2: *(volatile __u16 *)p = *(__u16 *)res; break;
 case 4: *(volatile __u32 *)p = *(__u32 *)res; break;
 case 8: *(volatile __u64 *)p = *(__u64 *)res; break;
 default:
  __asm__ __volatile__("": : :"memory");
  __builtin_memcpy((void *)p, (const void *)res, size);
  __asm__ __volatile__("": : :"memory");
 }
}
# 256 "./include/linux/compiler.h"
# 1 "./arch/arm/include/asm/barrier.h" 1
# 100 "./arch/arm/include/asm/barrier.h"
# 1 "./include/asm-generic/barrier.h" 1
# 16 "./include/asm-generic/barrier.h"
# 1 "./include/linux/compiler.h" 1
# 17 "./include/asm-generic/barrier.h" 2
# 101 "./arch/arm/include/asm/barrier.h" 2
# 257 "./include/linux/compiler.h" 2
# 1 "./include/linux/kasan-checks.h" 1




# 1 "./include/linux/types.h" 1
# 13 "./include/linux/types.h"
typedef u32 __kernel_dev_t;

typedef __kernel_fd_set fd_set;
typedef __kernel_dev_t dev_t;
typedef __kernel_ino_t ino_t;
typedef __kernel_mode_t mode_t;
typedef unsigned short umode_t;
typedef u32 nlink_t;
typedef __kernel_off_t off_t;
typedef __kernel_pid_t pid_t;
typedef __kernel_daddr_t daddr_t;
typedef __kernel_key_t key_t;
typedef __kernel_suseconds_t suseconds_t;
typedef __kernel_timer_t timer_t;
typedef __kernel_clockid_t clockid_t;
typedef __kernel_mqd_t mqd_t;

typedef _Bool bool;

typedef __kernel_uid32_t uid_t;
typedef __kernel_gid32_t gid_t;
typedef __kernel_uid16_t uid16_t;
typedef __kernel_gid16_t gid16_t;

typedef unsigned long uintptr_t;



typedef __kernel_old_uid_t old_uid_t;
typedef __kernel_old_gid_t old_gid_t;



typedef __kernel_loff_t loff_t;
# 55 "./include/linux/types.h"
typedef __kernel_size_t size_t;




typedef __kernel_ssize_t ssize_t;




typedef __kernel_ptrdiff_t ptrdiff_t;




typedef __kernel_clock_t clock_t;




typedef __kernel_caddr_t caddr_t;



typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;


typedef unsigned char unchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;




typedef u8 u_int8_t;
typedef s8 int8_t;
typedef u16 u_int16_t;
typedef s16 int16_t;
typedef u32 u_int32_t;
typedef s32 int32_t;



typedef u8 uint8_t;
typedef u16 uint16_t;
typedef u32 uint32_t;


typedef u64 uint64_t;
typedef u64 u_int64_t;
typedef s64 int64_t;
# 125 "./include/linux/types.h"
typedef u64 sector_t;
typedef u64 blkcnt_t;
# 145 "./include/linux/types.h"
typedef u32 dma_addr_t;


typedef unsigned int gfp_t;
typedef unsigned int slab_flags_t;
typedef unsigned int fmode_t;




typedef u32 phys_addr_t;


typedef phys_addr_t resource_size_t;





typedef unsigned long irq_hw_number_t;

typedef struct {
 int counter;
} atomic_t;







struct list_head {
 struct list_head *next, *prev;
};

struct hlist_head {
 struct hlist_node *first;
};

struct hlist_node {
 struct hlist_node *next, **pprev;
};

struct ustat {
 __kernel_daddr_t f_tfree;
 __kernel_ino_t f_tinode;
 char f_fname[6];
 char f_fpack[6];
};
# 214 "./include/linux/types.h"
struct callback_head {
 struct callback_head *next;
 void (*func)(struct callback_head *head);
} __attribute__((aligned(sizeof(void *))));


typedef void (*rcu_callback_t)(struct callback_head *head);
typedef void (*call_rcu_func_t)(struct callback_head *head, rcu_callback_t func);

typedef void (*swap_func_t)(void *a, void *b, int size);

typedef int (*cmp_r_func_t)(const void *a, const void *b, const void *priv);
typedef int (*cmp_func_t)(const void *a, const void *b);
# 6 "./include/linux/kasan-checks.h" 2
# 16 "./include/linux/kasan-checks.h"
static inline __attribute__((__gnu_inline__)) __attribute__((__unused__)) __attribute__((__no_instrument_function__)) bool __kasan_check_read(const volatile void *p, unsigned int size)
{
 return true;
}
static inline __attribute__((__gnu_inline__)) __attribute__((__unused__)) __attribute__((__no_instrument_function__)) bool __kasan_check_write(const volatile void *p, unsigned int size)
{
 return true;
}
# 34 "./include/linux/kasan-checks.h"
static inline __attribute__((__gnu_inline__)) __attribute__((__unused__)) __attribute__((__no_instrument_function__)) bool kasan_check_read(const volatile void *p, unsigned int size)
{
 return true;
}
static inline __attribute__((__gnu_inline__)) __attribute__((__unused__)) __attribute__((__no_instrument_function__)) bool kasan_check_write(const volatile void *p, unsigned int size)
{
 return true;
}
# 258 "./include/linux/compiler.h" 2
# 277 "./include/linux/compiler.h"
static inline __attribute__((__gnu_inline__)) __attribute__((__unused__)) __attribute__((__no_instrument_function__)) __attribute__((__always_inline__))
unsigned long read_word_at_a_time(const void *addr)
{
 kasan_check_read(addr, 1);
 return *(unsigned long *)addr;
}
# 308 "./include/linux/compiler.h"
static inline __attribute__((__gnu_inline__)) __attribute__((__unused__)) __attribute__((__no_instrument_function__)) void *offset_to_ptr(const int *off)
{
 return (void *)((unsigned long)off + *off);
}
# 23 "arch/arm/boot/compressed/misc.c" 2

# 1 "./include/linux/linkage.h" 1





# 1 "./include/linux/stringify.h" 1
# 7 "./include/linux/linkage.h" 2
# 1 "./include/linux/export.h" 1
# 72 "./include/linux/export.h"
struct kernel_symbol {
 unsigned long value;
 const char *name;
 const char *namespace;
};
# 8 "./include/linux/linkage.h" 2
# 1 "./arch/arm/include/asm/linkage.h" 1
# 9 "./include/linux/linkage.h" 2
# 25 "arch/arm/boot/compressed/misc.c" 2
# 1 "arch/arm/boot/compressed/misc.h" 1





void error(char *x) __attribute__((__noreturn__));
extern unsigned long free_mem_ptr;
extern unsigned long free_mem_end_ptr;
# 26 "arch/arm/boot/compressed/misc.c" 2

static void putstr(const char *ptr);

# 1 "./arch/arm/include/debug/uncompress.h" 1




static inline __attribute__((__gnu_inline__)) __attribute__((__unused__)) __attribute__((__no_instrument_function__)) void putc(int c) {}

static inline __attribute__((__gnu_inline__)) __attribute__((__unused__)) __attribute__((__no_instrument_function__)) void flush(void) {}
static inline __attribute__((__gnu_inline__)) __attribute__((__unused__)) __attribute__((__no_instrument_function__)) void arch_decomp_setup(void) {}
# 30 "arch/arm/boot/compressed/misc.c" 2
# 87 "arch/arm/boot/compressed/misc.c"
static void putstr(const char *ptr)
{
 char c;

 while ((c = *ptr++) != '\0') {
  if (c == '\n')
   putc('\r');
  putc(c);
 }

 flush();
}




extern char input_data[];
extern char input_data_end[];

unsigned char *output_data;

unsigned long free_mem_ptr;
unsigned long free_mem_end_ptr;





void error(char *x)
{
 ;

 putstr("\n\n");
 putstr(x);
 putstr("\n\n -- System halted");

 while(1);
}

 void __div0(void)
{
 error("Attempting division by 0!");
}

const unsigned long __stack_chk_guard = 0x000a0dff;

void __stack_chk_fail(void)
{
 error("stack-protector: Kernel stack is corrupted\n");
}

extern int do_decompress(u8 *input, int len, u8 *output, void (*error)(char *x));


void
decompress_kernel(unsigned long output_start, unsigned long free_mem_ptr_p,
  unsigned long free_mem_ptr_end_p,
  int arch_id)
{
 int ret;

 output_data = (unsigned char *)output_start;
 free_mem_ptr = free_mem_ptr_p;
 free_mem_end_ptr = free_mem_ptr_end_p;
 __machine_arch_type = arch_id;

 arch_decomp_setup();

 putstr("Uncompressing Linux...");
 ret = do_decompress(input_data, input_data_end - input_data,
       output_data, error);
 if (ret)
  error("decompressor returned an error");
 else
  putstr(" done, booting the kernel.\n");
}

void fortify_panic(const char *name)
{
 error("detected buffer overflow");
}
