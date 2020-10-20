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
	struct property *prop;
	u32 val;
	int ret;
	int i;
	u8 buf8[32];
	u16 buf16[32];
	u32 buf[32];
	u64 buf64[32];

	printk("%s\n", __func__);
	printk("of_node %px\n", dev->of_node);

	prop = of_find_property(dev->of_node, "reg", NULL);
	printk("reg len %d\n", prop->length);

	prop = of_find_property(dev->of_node, "reg2", NULL);
	printk("reg2 len %d\n", prop->length);

	ret = of_property_read_u32(dev->of_node, "#interrupt-cells", &val);
	if (ret == 0) {
		printk("#interrupt-cells %x\n", val);
	}
	for (i = 0 ; i < 8 ; i++) {
		ret = of_property_read_u32_index(dev->of_node, "interrupts", i, &val);
		if (ret == 0) {
			printk("interrupts%d %x\n", i, val);
		}
	}

	ret = of_property_read_variable_u8_array(dev->of_node, "u8bits", buf8, 0, 32);
	for (i = 0 ; i < ret ; i++) {
		printk("%d: %02x\n", i, buf8[i]);
	}
	ret = of_property_read_variable_u16_array(dev->of_node, "u16bits", buf16, 0, 32);
	for (i = 0 ; i < ret ; i++) {
		printk("%d: %02x\n", i, buf16[i]);
	}
	ret = of_property_read_variable_u32_array(dev->of_node, "u32bits", buf, 0, 32);
	for (i = 0 ; i < ret ; i++) {
		printk("%d: %02x\n", i, buf[i]);
	}
	ret = of_property_read_variable_u64_array(dev->of_node, "u64bits", buf64, 0, 32);
	for (i = 0 ; i < ret ; i++) {
		printk("%d: %llx\n", i, buf64[i]);
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

