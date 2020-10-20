/*
 * サンプルドライバ
 *
 * プラットフォームドライバを登録する。
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

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a sample driver.");
MODULE_AUTHOR("Yutaka Hirata");

static int sa_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct sample_platdata *pd = dev_get_platdata(&pdev->dev);
	struct resource *res;
	int irq;

	printk("%s\n", __func__);
	printk("of_node %px\n", dev->of_node);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (res) {
		printk("%s: %pr\n", __func__, res);
	}
	irq = platform_get_irq(pdev, 0);
	printk("%s: IRQ %d\n", __func__, irq);

	printk("%s: Platform data %x %x\n", __func__, pd->flags, pd->dummy);

	return 0;
}

static int sa_remove(struct platform_device *pdev)
{
	printk("%s\n", __func__);

	return 0;
}

static struct platform_driver sa_drv = {
	.probe = sa_probe,
	.remove = sa_remove,
	.driver = {
		.name = MODULE_NAME,
		.owner = THIS_MODULE,
	},
};

module_platform_driver(sa_drv);

