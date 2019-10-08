#include <stdint.h>

extern void main(void);
void reset_handler(void) {
    uint32_t* end_text = &_endtext;
    uint32_t* start_data = &_startdata;
    uint32_t* end_data = &_enddata;
    while(start_data<end_data) *start_data++=*end_text++;
    uint32_t* start_bss = &_startbss;
    uint32_t* endbss = &_endbss;
    while(start_bss<endbss)*start_bss++=0;

    main();
}

__attribute((section(".isr_vector"))) uint32_t *isr_vectors[] = {
    0, (uint32_t *)reset_handler, /* code entry point */
};