#include "..\header\main.h"

int main(){
   
    uart_init();
    uint8_t data  = 0;
   
    while (1)
    {
        uart_put_c(data);
        data++;
    }
    
}

