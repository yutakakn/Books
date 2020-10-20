/*
 * サンプルドライバ
 *
 * Device Treeに対応したプラットフォームドライバを登録する。
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

/* 
 * ドライバと紐付けしたいデバイスは、Device Treeの
 * ノードにあるcompatibleで指定する。
 */
static const struct of_device_id of_sample_ids[] = {
	//{ .compatible = "arm,versatile-pb" },
	//{ .compatible = "smsc,lan91c111" },
	{ .compatible = "arm,versatile-lcd" },
    { },
};
MODULE_DEVICE_TABLE(of, of_sample_ids);

/*
 * ドライバとデバイスが紐付けされると、probeルーチンが
 * 呼び出される。
 */
static int sa_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	int ret;

	printk("%s\n", __func__);
	printk("of_node %px\n", dev->of_node);

	ret = of_alias_get_id(dev->of_node, "lcd");
	printk("of_alias_get_id %d\n", ret);

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
		.of_match_table = of_sample_ids,
	},
};

module_platform_driver(sa_drv);

