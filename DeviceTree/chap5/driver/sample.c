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

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a sample driver.");
MODULE_AUTHOR("Yutaka Hirata");

struct sample_driver {
	struct device_driver driver;
};

/*
 * ハードウェアの情報定義
 * ※値は仮なので、実際にはハードウェアにアクセスはできません。
 *
 */
#define MMIO_ADDR	0x10009000
#define IO_PORT		0x00001000
#define IRQ_NUM		28

static u8 __iomem *g_hw_addr = NULL;
static int g_irq_enabled = 0;
static void *g_dev_id = NULL;

static irqreturn_t sample_interrupt(int irq, void *dev_id)
{
	int handled = 0;

	printk_ratelimited("%s\n", __func__);

	return IRQ_RETVAL(handled);
}

static int sample_init(struct sample_driver *drv)
{
	unsigned char buf[] = "abc\0defgh";
	u8 __iomem *hw_addr = NULL;
	size_t mmio_len = 16;
	unsigned int val;
	int ret;

	printk("buf %*ph\n", 8, buf);
	printk("buf %*phC\n", 8, buf);
	printk("buf %*phD\n", 8, buf);
	printk("buf %*phN\n", 8, buf);

	/* MMIO */
	hw_addr = ioremap(MMIO_ADDR, mmio_len);
	if (hw_addr == NULL) {
		printk("ioremap error\n");
	}
	printk("MMIO %p\n", hw_addr);
	g_hw_addr = hw_addr;

	/* I/O port */
	val = inb(IO_PORT);
	printk("I/O port 0x%x\n", val);

	/* Interrupt */
	g_dev_id = &g_irq_enabled;
	ret = request_irq(IRQ_NUM, sample_interrupt, IRQF_SHARED, "sample_irq", g_dev_id);
	if (ret < 0) {
		printk("request_irq error\n");
	} else {
		g_irq_enabled = 1;
	}

	printk(KERN_ALERT "driver loaded\n");

	return 0;
}

static void sample_exit(struct sample_driver *drv)
{
	if (g_hw_addr) {
		iounmap(g_hw_addr);
		printk("iounmap %p\n", g_hw_addr);
	}

	if (g_irq_enabled) {
		free_irq(IRQ_NUM, g_dev_id);
		printk("free_irq\n");
	}

	printk(KERN_ALERT "driver unloaded\n");
}

static struct sample_driver sa_drv = {
	.driver = {
		.name = "sample_driver",
		.of_match_table = NULL,
	},
};

module_driver(sa_drv, sample_init, sample_exit);

