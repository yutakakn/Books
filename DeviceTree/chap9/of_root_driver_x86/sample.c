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
#include <linux/of.h>
#include <linux/of_device.h>

#define MODULE_NAME "sample_driver"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a sample driver.");
MODULE_AUTHOR("Yutaka Hirata");

struct sample_driver {
	struct device_driver driver;
};

static int sample_init(struct sample_driver *drv)
{
	const char *s;

	printk(KERN_ALERT "driver loaded\n");

	if (of_root == NULL) {
		printk("%s: Device Tree not found\n", __func__);
		return -ENODEV;
	}

	of_node_get(of_root);

	s = of_get_property(of_root, "compatible", NULL);
	printk("%s\n", s);

	of_node_put(of_root);

	return 0;
}

static void sample_exit(struct sample_driver *drv)
{
	printk(KERN_ALERT "driver unloaded\n");
}

static struct sample_driver sa_drv = {
	.driver = {
		.name = MODULE_NAME,
	},
};

module_driver(sa_drv, sample_init, sample_exit);

