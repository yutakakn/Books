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
	const struct of_device_id *match = NULL;
	struct device *dev = &pdev->dev;
	int i;

	printk("%s\n", __func__);
	printk("of_node %px\n", dev->of_node);

	match = of_match_device(of_match_ptr(of_sample_ids), &pdev->dev);
	printk("%px\n", match);
	if (match) {
		printk("name [%s] type [%s] compatible [%s] data[%px]\n", 
				match->name, match->type, match->compatible, match->data
				);
	}

	for (i  = 0 ; i < pdev->num_resources ; i++) {
        printk("%s: resource %pr num_resources %u\n", __func__,
                &pdev->resource[i], pdev->num_resources);
	}

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

