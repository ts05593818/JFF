#ifndef __REG_H
#define __REG_H
#include "stdint.h"


#define __REG(x)        *((volatile uint32_t*)(x))

/**************register base address***************/
#define RCC_BASE            (0x40023800UL)
#define GPIOA_BASE          (0x40020000UL)
#define USB_OTG_FS_BASE     (0x50000000UL)
#define USART2_BASE         (0x40004400UL)

/***********RCC related***************/
/************CR reset value: 0x0000 xx83************************/
#define RCC_CR              (__REG(RCC_BASE+0x00))
#define HSE_ON              (1<<16)
#define PLL_ON              (1<<24)

#define RCC_CFGR            (__REG(RCC_BASE+0x08))
#define SWHSI                  (0<<0)
#define SWHSE                  (1<<0)
#define SWPLL                  (2<<0)
/************PLL config register reset value: 0x2400 3010************************/
/********2<=PLLQ<=15 ;PLLP 2,4,6,8; 50<=PLLN<=432;2<=PLLM<=63*******************************************/
#define RCC_PLLCFGR         (__REG(RCC_BASE+0x04))
#define PLLQ(x)             (x<<24)
#define PLLM(x)             (x<<0)
#define PLLN(x)             (x<<6)
#define PLLP(x)             (((x>>1)-1)<<16)
#define RCC_AHB1_ENR         ((__REG(RCC_BASE+0x30)))
#define RCC_AHB2_ENR         ((__REG(RCC_BASE+0x34)))
#define RCC_AHB3_ENR         ((__REG(RCC_BASE+0x38)))
#define RCC_APB1_ENR         ((__REG(RCC_BASE+0x40)))
#define RCC_APB2_ENR         ((__REG(RCC_BASE+0x44)))

/************uart2 for debug*********************/
#define USART2_SR         (__REG(USART2_BASE+0x00))
#define USART2_DR         (__REG(USART2_BASE+0x04))
#define USART2_BRR        (__REG(USART2_BASE+0x08))
#define USART2_CR1        (__REG(USART2_BASE+0x0c))
#define USART2_CR2        (__REG(USART2_BASE+0x10))
#define USART2_CR3        (__REG(USART2_BASE+0x14))
#define USART2_GTPR       (__REG(USART2_BASE+0x18))

/**************GPIO related**************************/
#define GPIO_MODER(GPIO_BASE)           (__REG(GPIO_BASE+0x00))
#define GPIO_OTYPER(GPIO_BASE)          (__REG(GPIO_BASE+0x04))
#define GPIO_OSPEEDR(GPIO_BASE)         (__REG(GPIO_BASE+0x08))
#define GPIO_PUPDR(GPIO_BASE)           (__REG(GPIO_BASE+0x0c))
#define GPIO_IDR(GPIO_BASE)             (__REG(GPIO_BASE+0x10))
#define GPIO_ODR(GPIO_BASE)             (__REG(GPIO_BASE+0x14))
#define GPIO_BSRR(GPIO_BASE)            (__REG(GPIO_BASE+0x18))
#define GPIO_LCKR(GPIO_BASE)            (__REG(GPIO_BASE+0x1C))
#define GPIO_AFRL(GPIO_BASE)            (__REG(GPIO_BASE+0x20))
#define GPIO_AFRH(GPIO_BASE)            (__REG(GPIO_BASE+0x24))



#endif
