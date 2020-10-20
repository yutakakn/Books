/*
 * サンプルドライバ
 *
 * プラットフォームデバイスを登録する。
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
#include "sample.h"

#define DRV_NAME "board_driver"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a sample driver.");
MODULE_AUTHOR("Yutaka Hirata");

struct board_driver {
	struct device_driver driver;
};

static void board_release(struct device *dev)
{
	printk("%s\n", __func__);
}

static struct sample_platdata sa_platdata = {
	.flags = 0xcafebabe,
	.dummy = 0,
};

#define BOARD_BAR 0xdeadbeaf
#define BOARD_IRQ 80

static struct resource sample_resources[] = {
	[0] = {
		.start = BOARD_BAR + 0,
		.end = BOARD_BAR + 0x100,
		.flags = IORESOURCE_MEM,
	},

	[1] = {
		.start = BOARD_IRQ,
		.end = BOARD_IRQ,
		.flags = IORESOURCE_IRQ,
	},
};

static struct platform_device sa_dev = {
	.name = MODULE_NAME,
	.id = 0,
	.dev = {
		.platform_data = &sa_platdata,
	},
	.num_resources  = ARRAY_SIZE(sample_resources),
	.resource = sample_resources,
	.dev.release = board_release,
};

static int board_init(struct board_driver *drv)
{
	printk("%s\n", __func__);

	platform_device_register(&sa_dev);
	return 0;
}

static void board_exit(struct board_driver *drv)
{
	printk("%s\n", __func__);
	platform_device_unregister(&sa_dev);
}

static struct board_driver sa_drv = {
	.driver = {
		.name = DRV_NAME,
	},
};

module_driver(sa_drv, board_init, board_exit);

