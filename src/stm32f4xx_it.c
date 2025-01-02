#include "main.h"
#include "stm32f4xx_it.h"

void NMI_Handler(void)
{
    while (1)
    {
        Log_Error("NMI occurred!");
        System_Reset();
    }
}

void HardFault_Handler(void)
{
    while (1)
    {
        Log_Error("HardFault occurred!");
        Debug_DumpRegisters();
    }
}

void MemManage_Handler(void)
{
    while (1)
    {
        Log_Error("Memory Management Fault!");
        System_Reset();
    }
}

void BusFault_Handler(void)
{
    while (1)
    {
        Debug_DumpBusStatus();
    }
}

void UsageFault_Handler(void)
{
    while (1)
    {
        Log_Error("Usage Fault!");
        System_Reset();
    }
}

void SVC_Handler(void)
{
    Handle_SVC_Request();
}

void DebugMon_Handler(void)
{
    Handle_DebugEvent();
}

void SysTick_Handler(void)
{
    HAL_IncTick();

    Custom_Tick_Handler();
}

void EXTI15_10_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);

    Handle_ButtonInterrupt();
}

