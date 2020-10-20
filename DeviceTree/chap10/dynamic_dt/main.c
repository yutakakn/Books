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
#include <linux/slab.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is a sample driver.");
MODULE_AUTHOR("Yutaka Hirata");

static struct of_changeset chgset;

struct property *__of_prop_dup(const struct property *prop, gfp_t allocflags)
{
    struct property *new;

    new = kzalloc(sizeof(*new), allocflags);
    if (!new)
        return NULL;

    /*
     * NOTE: There is no check for zero length value.
     * In case of a boolean property, this will allocate a value
     * of zero bytes. We do this to work around the use
     * of of_get_property() calls on boolean values.
     */
    new->name = kstrdup(prop->name, allocflags);
    new->value = kmemdup(prop->value, prop->length, allocflags);
    new->length = prop->length;
    if (!new->name || !new->value)
        goto err_free;

    /* mark the property as dynamic */
    of_property_set_flag(new, OF_DYNAMIC);

    return new;

 err_free:
    kfree(new->name);
    kfree(new->value);
    kfree(new);
    return NULL;
}

static int sample_init(void)
{
	struct property *ppadd, padd = { .name = "prop-add", .length = 3, .value = "ok" };
	struct device_node *node;
	int ret;

	printk(KERN_ALERT "driver loaded\n");

	node = of_find_node_by_path("/lcd@10008000");
	printk("%pOF\n", node);

	ppadd = __of_prop_dup(&padd, GFP_KERNEL);

	of_changeset_init(&chgset);
	ret = of_changeset_add_property(&chgset, node, ppadd);
	printk("of_changeset_add_property %d\n", ret);

	ret = of_changeset_apply(&chgset);
	printk("of_changeset_apply %d\n", ret);
		
	return 0;
}

static void sample_exit(void)
{
	int ret;

	printk(KERN_ALERT "driver unloaded\n");

	ret = of_changeset_revert(&chgset);
	printk("of_changeset_revert %d\n", ret);
	of_changeset_destroy(&chgset);
}

module_init(sample_init);
module_exit(sample_exit);

