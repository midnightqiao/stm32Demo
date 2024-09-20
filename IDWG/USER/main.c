#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"
#include "iwdg.h"
#include "key.h"
#include "led.h"
int main()
{
    delay_init();
    LED_Init();
    keyInit();
    LED0 = 1;
    delay_ms(500);
    idwg_init(IWDG_Prescaler_4,625);
    LED0 = 0;
    LED1 = 0;
    while(1){
        if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)== SET){
           IWDG_ReloadCounter();
        }
        delay_ms(10);
    }
}

