#include "stm32f10x.h"
#include "delay.h"

int main()
{
    delay_init();
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE,ENABLE);
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStruct);
    GPIO_Init(GPIOE,&GPIO_InitStruct);
    while(1){
        GPIO_SetBits(GPIOE,GPIO_Pin_5);
        GPIO_ResetBits(GPIOB,GPIO_Pin_5);
        delay_ms(500);
        GPIO_SetBits(GPIOB,GPIO_Pin_5);
        GPIO_ResetBits(GPIOE,GPIO_Pin_5);
        delay_ms(500);

    }
}
