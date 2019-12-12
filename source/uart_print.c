#include <uart_print.h>



int uart_print (char *data,...) {

    char sendbuf[buffer_size] = {0}; //buffer to be sent to uart
    uint8_t count = 0; //send times
    va_list arg_ptr;
    va_start(arg_ptr,data);
    vsnprintf(sendbuf,buffer_size+1,data,arg_ptr);

    while ( (count < buffer_size) && sendbuf[count] ) {
        uart_put_c(sendbuf[count++]);
    }

    va_end(arg_ptr); // free memory
    
    return 0;  // ok 
}