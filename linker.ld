
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 1M
    
    SRAM (rw)   : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
    .text :
    {
        *(.isr_vector)         
        *(.text*)               
        *(.rodata*)             
        . = ALIGN(4);           
    } > FLASH

    .data : 
    {
        *(.data*)
    } > SRAM

    .bss :
    {
        *(.bss*)
    } > SRAM

    .stack (NOLOAD) : 
    {
        . = ALIGN(8);
        __stack_start__ = .;  
        . = . + 0x400;        
        __stack_end__ = .;    
    } > SRAM

    .heap (NOLOAD) : 
    {
        __heap_start__ = .;   
        . = . + 0x2000;       
        __heap_end__ = .;     
    } > SRAM

    .isr_vector :
    {
        KEEP(*(.isr_vector))
    } > FLASH

    /DISCARD/ :
    {
        *(.note.gnu.property)
        *(.comment)
        *(.debug*)
    }
}

