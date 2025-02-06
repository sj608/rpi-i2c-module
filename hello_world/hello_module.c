
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#define OP_READ     0
#define OP_WRITE    1
#define OP_OOPS     OP_WRITE

// Removed after initialization (static kerenl or module)
static int __init hello_init(void)
{
    int *a;
    a = (int*) 0x00001234;
#if OP_OOPS == OP_WRITE
    *a = 3;
#elif OP_OOPS == OP_READ
    printk(KERN_ALERT "value = %d\n", *a);
#else
#error "Unknown op for oops"
#endif

    return 0;
}

// Discarded when module compiled statically into the kernel, or when module unloading suppport is not enabled
static void __exit hello_exit(void)
{
    pr_debug("Goodbye World\n");

}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Greeting Module");
MODULE_AUTHOR("SJ Park");