#ifndef __UART_H_
#define __UART_H_
#include "reg.h"
#include "main.h"

#define BAUDRATE(x)     (HSE_CLK/x)

#define APB1_UART2      (17)
#define APB1_UART3      (18)
#define APB1_UART4      (19)
#define APB1_UART5      (20)

void uart_init();
void uart_put_c();
#endif
