/*
 * RCC_EN.h
 *
 *  Created on: Dec 11, 2023
 *      Author: tyler
 */

#ifndef RCC_AHB1_EN_H_
#define RCC_AHB1_EN_H_

typedef struct {
	uint32_t GPIOA_CLK_EN		:1;
	uint32_t GPIOB_CLK_EN		:1;
	uint32_t GPIOC_CLK_EN		:1;
	uint32_t GPIOD_CLK_EN		:1;
	uint32_t GPIOE_CLK_EN		:1;
	uint32_t GPIOF_CLK_EN		:1;
	uint32_t GPIOG_CLK_EN		:1;
	uint32_t GPIOH_CLK_EN		:1;
	uint32_t GPIOI_CLK_EN		:1;
	uint32_t RESERVED			:3;
	uint32_t CRC_CLK_EN			:1;
	uint32_t RESERVED2			:5;
	uint32_t BKUP_SRAM_EN		:1;
	uint32_t RESERVED3			:1;
	uint32_t CCM_DATA_RAM_EN	:1;
	uint32_t DMA1_CLK_EN		:1;
	uint32_t DMA2_CLK_EN		:1;
	uint32_t RESERVED4			:2;
	uint32_t ETH_MAC_CLK_EN		:1;
	uint32_t ETH_MAC_TX_EN		:1;
	uint32_t ETH_MAC_RX_EN		:1;
	uint32_t ETH_PTP_CLK_EN		:1;
	uint32_t USB_OTG_HS_CLK_EN	:1;
	uint32_t USB_OTG_HSULPI_EN	:1;
	uint32_t RESERVED5			:1;
}RCC_AHB1_EN_t;

#endif /* RCC_AHB1_EN_H_ */
