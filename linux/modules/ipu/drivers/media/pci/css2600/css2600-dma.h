/*
 * Copyright (c) 2013--2014 Intel Corporation. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef CSS2600_DMA_H
#define CSS2600_DMA_H

#include <linux/iova.h>

struct iommu_domain;

struct css2600_dma_mapping {
	struct iommu_domain *domain;
	struct iova_domain iovad;
	struct kref ref;
};

extern struct dma_map_ops css2600_dma_ops;

#endif /* CSS2600_DMA_H */
