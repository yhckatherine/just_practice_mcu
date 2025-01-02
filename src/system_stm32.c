#include "system_stm32f4xx.h"

#define HSE_VALUE    ((uint32_t)8000000)  
#define HSI_VALUE    ((uint32_t)16000000) 

uint32_t SystemCoreClock = 16000000; 

void SystemInit(void)
{
    RCC->CR |= RCC_CR_HSEON;               
    while (!(RCC->CR & RCC_CR_HSERDY)) {}  

    RCC->CFGR |= RCC_CFGR_PLLSRC_HSE;      
    RCC->CR |= RCC_CR_PLLON;               
    while (!(RCC->CR & RCC_CR_PLLRDY)) {}  

    RCC->CFGR |= RCC_CFGR_SW_PLL;          
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL) {}  
    SystemCoreClock = HSE_VALUE * 9; 
    
}

void SystemCoreClockUpdate(void)
{
    uint32_t pll_multiplier = 9; 

    SystemCoreClock = HSE_VALUE * pll_multiplier;
}

