/*
 * サンプルドライバ
 *
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/siphash.h>
#include <linux/io.h>
#include <linux/interrupt.h>
#include <linux/of_fdt.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a sample driver.");
MODULE_AUTHOR("Yutaka Hirata");

struct sample_driver {
	struct device_driver driver;
};

static int sample_init(struct sample_driver *drv)
{
	unsigned char *fdt = initial_boot_params;
	int val = 0;

	printk("%px %x\n", initial_boot_params, *(unsigned int *)initial_boot_params);
	memcpy(initial_boot_params, &val, 4);
	printk("%px %x\n", initial_boot_params, *(unsigned int *)initial_boot_params);

	return 0;
}

static void sample_exit(struct sample_driver *drv)
{
	printk(KERN_ALERT "driver unloaded\n");
}

static struct sample_driver sa_drv = {
	.driver = {
		.name = "sample_driver",
		.of_match_table = NULL,
	},
};

module_driver(sa_drv, sample_init, sample_exit);

