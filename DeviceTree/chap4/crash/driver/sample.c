/*
 * サンプルドライバ
 *
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>
#include <linux/siphash.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a sample driver.");
MODULE_AUTHOR("Yutaka Hirata");

struct sample_driver {
	struct device_driver driver;
};

static int sample_init(struct sample_driver *drv)
{
	char *p = NULL;

	printk(KERN_ALERT "driver loaded\n");

	/* NULLポインタアクセスを行う */
	*p = 0;

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

