/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __RGA_API_H__
#define __RGA_API_H__

#include <linux/miscdevice.h>

#include "rga2_reg_info.h"
#include "rga2.h"

struct rga2_drvdata_t {
	struct miscdevice miscdev;
	struct device *dev;
	void *rga_base;
	int irq;

	struct delayed_work power_off_work;
	struct wakeup_source wake_lock;

	struct clk *aclk_rga2;
	struct clk *hclk_rga2;
	struct clk *clk_rga2;

	char version[16];
};

#define ENABLE      1
#define DISABLE     0

#define IS_YUV_420(format) \
     ((format == RK_FORMAT_YCbCr_420_P) | (format == RK_FORMAT_YCbCr_420_SP) | \
      (format == RK_FORMAT_YCrCb_420_P) | (format == RK_FORMAT_YCrCb_420_SP))

#define IS_YUV_422(format) \
     ((format == RK_FORMAT_YCbCr_422_P) | (format == RK_FORMAT_YCbCr_422_SP) | \
      (format == RK_FORMAT_YCrCb_422_P) | (format == RK_FORMAT_YCrCb_422_SP))

#define IS_YUV(format) \
     ((format == RK_FORMAT_YCbCr_420_P) | (format == RK_FORMAT_YCbCr_420_SP) | \
      (format == RK_FORMAT_YCrCb_420_P) | (format == RK_FORMAT_YCrCb_420_SP) | \
      (format == RK_FORMAT_YCbCr_422_P) | (format == RK_FORMAT_YCbCr_422_SP) | \
      (format == RK_FORMAT_YCrCb_422_P) | (format == RK_FORMAT_YCrCb_422_SP))

#endif
