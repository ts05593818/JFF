#include "../header/uart_print.h"

int uart_print (const char *data,...) {
    
    va_list arg_ptr;
    va_start(arg_ptr,data);
    int count=0;

    while (data[count] != '\0') {

        if (data[count] != '%') {       //output char data until '%'
            uart_put_c(data[count++]);
            continue;
        }

        data++;         // backward a char
       
            switch (data[count]) {
            case 'd' : {
                int dd;
                dd=va_arg(arg_ptr,int);
                uart_put_c(dd);
                break;
            }
            case 'c' : {
                char cc;
                cc=(char)va_arg(arg_ptr,int);
                uart_put_c(cc);
                break;
            };
            case 's' : {
                char *ss;
                ss=va_arg(arg_ptr,char*);
                while (*ss) {
                    uart_put_c(*ss++);
                }
                break;
            };
            case 'x' : {
                int xx;
                char hex_char[17]="0123456789ABCDEF";    // HEX string
                xx=va_arg(arg_ptr,int);
                uart_put_c(hex_char[high_bits(xx)]);
                uart_put_c(hex_char[low_bits(xx)]);
                break;
            };
            default:
                break;
            }
         va_end(arg_ptr); // free memory
   
    }
    

    
    return 0;  // ok 
}