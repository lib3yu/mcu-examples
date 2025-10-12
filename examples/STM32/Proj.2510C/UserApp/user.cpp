#include "main.h"
#include "usart.h"
#include "gpio.h"
#include <string.h>
#include <stdint.h>

#include <FreeRTOS.h>
#include <task.h>

#if __cplusplus
extern "C" {
#endif

/* Called by "defaultTask" task in freertos.c */
void StartDefaultTask(void *argument)
{
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
    
    while (1) 
    {
        HAL_GPIO_TogglePin(LED0_GPIO_Port, LED0_Pin);
        vTaskDelay(200);
    }
}

#if __cplusplus
}
#endif
