#ifndef __REG_H
#define __REG_H

#define __REG_TYPE  volatile uint32_t*
#define __REG       (*(__REG_TYPE))

/**************register base address***************/
#define RCC_BASE ((__REG_TYPE)0x0x40023800)
#define GPIOA_BASE ((__REG_TYPE)0x40020000)
#define USB_OTG_FS_BASE ((__REG_TYPE)0x50000000)


