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

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a sample driver.");
MODULE_AUTHOR("Yutaka Hirata");

/* Device Tree Assembler sourceの先頭と末端ポインタ */
extern unsigned char dt_blob_start[];
extern unsigned char dt_blob_end[];

/* Overlay 情報 */
static int g_overlay_id;
static bool g_overlay_applied = false;

static int sample_init(void)
{
	unsigned int len;
	int ret;

	printk(KERN_ALERT "driver loaded\n");

	len = dt_blob_end - dt_blob_start;
	printk("DTB start %px\n", dt_blob_start);
	printk("DTB end %px\n", dt_blob_end);
	printk("DTB len %d\n", len);

	ret = of_overlay_fdt_apply(dt_blob_start, len, &g_overlay_id);
	if (ret == 0) {
		g_overlay_applied = true;
		printk("Overlay ID %d\n", g_overlay_id);
	}
		
	return 0;
}

static void sample_exit(void)
{
	int ret;

	printk(KERN_ALERT "driver unloaded\n");

	if (g_overlay_applied) {
		ret = of_overlay_remove(&g_overlay_id);
		printk("of_overlay_remove %d\n", ret);
	}
}

module_init(sample_init);
module_exit(sample_exit);

