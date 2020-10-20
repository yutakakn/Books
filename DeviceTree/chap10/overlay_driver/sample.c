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

#define MODULE_NAME "overlay_driver"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a sample driver.");
MODULE_AUTHOR("Yutaka Hirata");

/* 
 * ドライバと紐付けしたいデバイスは、Device Treeの
 * ノードにあるcompatibleで指定する。
 */
static const struct of_device_id of_sample_ids[] = {
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
	struct device_node *sub;
	u32 pval[2];
	int ret;
	//int i;

	printk("%s\n", __func__);
	printk("of_node %px\n", dev->of_node);

#if 0
	for (i  = 0 ; i < pdev->num_resources ; i++) {
        printk("%s: resource %pr num_resources %u\n", __func__,
                &pdev->resource[i], pdev->num_resources);
	}
#endif

	sub = of_find_node_by_name(dev->of_node, "subnode");
	printk("%pOF\n", sub);
	if (sub) {
		ret = of_property_read_u32_array(sub, "reg", pval, 2);
		if (ret == 0) {
			printk("%x, %x\n", pval[0], pval[1]);
		}

		of_node_put(sub);
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

