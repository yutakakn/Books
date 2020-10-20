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

static int sample_init(struct sample_driver *drv)
{
	u32 phyaddr;
	void *vaddr;

	phyaddr = 0xA0001000;
	vaddr = phys_to_virt(phyaddr);
	printk("PHY %x => VIR %p\n", phyaddr, vaddr);

	phyaddr = virt_to_phys(vaddr);
	printk("VIR %p => %x\n", vaddr, phyaddr);

	return 0;
}

static void sample_exit(struct sample_driver *drv)
{
	printk(KERN_ALERT "driver unloaded\n");
}

static struct sample_driver sa_drv = {
	.driver = {
		.name = "sample_driver",
		.of_match_table = NULL,
	},
};

module_driver(sa_drv, sample_init, sample_exit);

