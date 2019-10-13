#include "../header/uart.h"

void uart_init(void){
/**************RCC Config****************/
RCC_APB1_ENR |= (1<<APB1_UART2); //EN UART2
RCC_AHB1_ENR |= (1<<0); //EN GPIOA
/**************GPIO Config****************/
GPIO_MODER(GPIOA_BASE) |= (0x02<<6)|(0x02<<4);
// GPIO_OSPEEDR(GPIOA_BASE) |=(1<<6)|(1<<4);
// GPIO_OTYPER(GPIOA_BASE) |= (1<<3)|(1<<2);
// GPIO_PUPDR(GPIOA_BASE) |=(1<<6)|(1<<4);
GPIO_AFRL(GPIOA_BASE) |=(7<<12)|(7<<8);
/**************UART Config****************/
USART2_CR1 =(1<<13)|(1<<3)|(1<<2);
USART2_BRR = (0x4<<4)|(0x05); //baudrate 115200 ; 8000000 / 115200 = 69.444;69 ->0x45;  0.44*16 ->0x07
}
void uart_put_c(uint8_t data){
USART2_DR = data;
while(!(USART2_SR & (1<<6)));
}
void uart_get_c(uint8_t* data){
while(!(USART2_SR & (1<<5)));
*data = USART2_DR;
}
