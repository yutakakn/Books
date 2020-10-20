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

static void print_phandle_args(char *msg, struct of_phandle_args *args)
{
	int i;

	printk("%s [%pOF]", msg, args->np);
	for (i = 0; i < args->args_count; i++) {
		const char delim = i ? ',' : ':';

		pr_cont("%c%08x", delim, args->args[i]);
	}
	pr_cont("\n");
}

/*
 * ドライバとデバイスが紐付けされると、probeルーチンが
 * 呼び出される。
 */
static int sa_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct of_phandle_args args;
	int ret;
    int idx;

	printk("%s\n", __func__);
	printk("of_node %px\n", dev->of_node);

	for (idx = 0 ; idx < 2; idx++) {
		memset(&args, 0, sizeof(args));
		ret = of_parse_phandle_with_args(dev->of_node, 
				"list", "#list-cells", idx, &args);
		if (ret == 0) {
			print_phandle_args("test", &args);
		}
	}

	memset(&args, 0, sizeof(args));
	ret = of_parse_phandle_with_args_map(dev->of_node, 
			"list2", "list", 1, &args);
	if (ret == 0) {
		print_phandle_args("test2", &args);
	}

	ret = of_count_phandle_with_args(dev->of_node, "list", "#list-cells");
	printk("of_count_phandle_with_args %d\n", ret);

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

