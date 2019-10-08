ENTRY(reset_handler)

MEMORY
{
    FLASH(rx)   : ORIGIN = 0x08000000,LENGTH = 128k
    SRAM(rwx)   : ORIGIN = 0x20000000,LENGTH = 40k 
}
SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vector))
        *(.text)
        *(.text.*)
        *(.rodata)

    }>FLASH
    .data :
    {
        *(.data)
        *(.data.*)
    }>SRAM
    .bss :
    {
        *(.bss)
    }>SRAM
}