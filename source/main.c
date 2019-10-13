#include "..\header\main.h"

int main(){
    init_core_clk();
    uart_init();
    uint8_t data  = 0;
    
    while (1)
    {
        uart_put_c(data);
        data ++;
    }
    
}

void init_core_clk(void){
    RCC_CR = PLL_ON;
    RCC_PLLCFGR = (PLLM(5)) | (PLLN(60)) | (PLLQ(2))|(PLLP(2));
    RCC_CFGR = SWHSE;
}