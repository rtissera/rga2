# SPDX-License-Identifier: GPL-2.0
rga2-y	:= rga2_drv.o rga2_mmu_info.o rga2_reg_info.o

obj-$(CONFIG_ROCKCHIP_RGA2)	+= rga2.o
