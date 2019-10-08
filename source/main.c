#include "..\header\main.h"

int main(){
    init_core_clk();
    
}

void init_core_clk(){
    RCC_CR = PLL_ON;
    RCC_PLLCFGR = (PLLM(5)) | (PLLN(60)) | (PLLQ(2))|(PLLP(2));
    RCC_CFGR = SWHSE;
}