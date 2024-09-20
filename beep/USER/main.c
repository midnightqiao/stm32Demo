#include "stm32f10x.h"
#include "delay.h"

int main()
{
    GPIO_InitTypeDef GPIO_InitStruct;
    delay_init();
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE,ENABLE);
    //蜂鸣器初始化
    
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB,&GPIO_InitStruct);
    //按键初始化
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
    GPIO_Init(GPIOE,&GPIO_InitStruct);
    while(1){
        if(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) == Bit_RESET){
            while(GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4) == Bit_RESET){
              delay_ms(20);  
            }
            if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_8)){
                GPIO_WriteBit(GPIOB,GPIO_Pin_8,Bit_RESET);
            }else{
                GPIO_WriteBit(GPIOB,GPIO_Pin_8,Bit_SET);
            }
        }
    }
}

