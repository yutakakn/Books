/*
 * platform deviceとplatform driverの共有ヘッダ
 *
 */
#ifndef __SAMPLE_H__
#define __SAMPLE_H__

#define MODULE_NAME "sample_driver"

struct sample_platdata {
	unsigned int flags;
	unsigned char dummy;
};

#endif /* __SAMPLE_H__ */

