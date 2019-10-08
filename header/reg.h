#ifndef __REG_H
#define __REG_H
#endif
#include "stdint.h"


#define __REG(x)        *((volatile uint32_t*)x)

/**************register base address***************/
#define RCC_BASE            (0x40023800UL)
#define GPIOA_BASE          (0x40020000UL)
#define USB_OTG_FS_BASE     (0x50000000UL)
#define UART

/***********RCC related***************/
/************CR reset value: 0x0000 xx83************************/
#define RCC_CR              (__REG(RCC_BASE+0x00))
#define HSE_ON              (1<<16)
#define PLL_ON               (1<<24)

/************PLL config register reset value: 0x2400 3010************************/
/********2<=PLLQ<=15 ;PLLP 2,4,6,8; 50<=PLLN<=432;2<=PLLM<=63*******************************************/
#define RCC_PLLCFGR         (__REG(RCC_BASE+0x04))
#define PLLQ(x)             (x<<24)
#define PLLM(x)             (x<<0)
#define PLLN(x)             (x<<6)
#define PLLP(x)             (((x>>1)-1)<<16)

