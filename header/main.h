#ifndef __MAIN_H_
#define __MAIN_H_
#include "reg.h"
#include"stdint.h"
#include"uart.h"
#include "stdlib.h"
#define HSE_CLK 8000000UL

void init_core_clk();
int main();
#endif