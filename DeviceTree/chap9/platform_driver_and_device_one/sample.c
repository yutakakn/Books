/*
 * サンプルドライバ
 *
 * プラットフォームデバイスとドライバを一度に登録する。
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

/* platform driverとplatform deviceを紐付けするモジュール名 */
#define MODULE_NAME "test_module"
/* サンプルドライバの名前 */
#define DRV_NAME "sample_driver"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a sample driver.");
MODULE_AUTHOR("Yutaka Hirata");

struct sample_driver {
	struct device_driver driver;
};

static int test_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;

	printk("%s\n", __func__);
	printk("of_node %px\n", dev->of_node);

	return 0;
}

static int test_remove(struct platform_device *pdev)
{
	printk("%s\n", __func__);

	return 0;
}

static struct platform_driver test_drv = {
	.probe = test_probe,
	.remove = test_remove,
	.driver = {
		.name = MODULE_NAME,
		.owner = THIS_MODULE,
	},
};

static void test_release(struct device *dev)
{
	printk("%s\n", __func__);
}

static struct platform_device test_dev = {
	.name = MODULE_NAME,
	.id = -1,
	.dev.release = test_release,
};

static int sample_init(struct sample_driver *drv)
{
	printk("%s\n", __func__);

	platform_driver_register(&test_drv);
	platform_device_register(&test_dev);
	return 0;
}

static void sample_exit(struct sample_driver *drv)
{
	printk("%s\n", __func__);

	platform_device_unregister(&test_dev);
	platform_driver_unregister(&test_drv);
}

static struct sample_driver sa_drv = {
	.driver = {
		.name = DRV_NAME,
	},
};

module_driver(sa_drv, sample_init, sample_exit);

