
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

// Removed after initialization (static kerenl or module)
static int __init hello_init(void)
{
    pr_debug("Hello World\n");
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