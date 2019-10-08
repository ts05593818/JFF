#include "../header/uart.h"

__attribute((section(".text.UART_DEBUG"))) void uart_init(){
/**************RCC Config****************/
RCC_APB1_ENR = (1<<APB1_UART2);

/**************GPIO Config****************/
GPIO_MODER(GPIOA_BASE) |= (0x02<<6)|(0x02<<4);
GPIO_OSPEEDR(GPIOA_BASE) |=(1<<6)|(1<<4);
GPIO_AFRL(GPIOA_BASE) |=(7<<12)|(7<<8);
/**************UART Config****************/
USART2_CR1 =(1<<13)|(1<<3)|(1<<2);
USART2_BRR = (0x45<<4)|((0x07)); //baudrate 115200 ; 8000000 / 115200 = 69.444;69 ->0x45;  0.44*16 ->0x07
}
__attribute((section(".text.UART_DEBUG"))) void uart_put_c(){


}