#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"
#include "iwdg.h"
#include "key.h"
#include "led.h"
#include "wwdg.h"
int main()
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    delay_init();
    LED_Init();
    LED0 = 0;
    delay_ms(500);
    LED0 = 1;
    wwdg_init(0x7f,0x5f,WWDG_Prescaler_8);
    while(1){
        
    }
}

