#include "wwdg.h"
#include "led.h"

uint8_t WWDOG_CNT = 0x7f;
BitAction cur;


void wwdg_init(uint8_t tr,uint8_t wr,uint32_t pret){
    
    NVIC_InitTypeDef NVIC_InitStruct;
    LED1 = 0;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG,ENABLE);
    WWDOG_CNT &= tr;
    WWDG_DeInit();
    WWDG_SetPrescaler(pret);
    WWDG_SetWindowValue(wr);
    WWDG_Enable(WWDOG_CNT);
    WWDG_ClearFlag();
    
    NVIC_InitStruct.NVIC_IRQChannel = WWDG_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
    WWDG_EnableIT();
    
//    RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE); // WWDG ???? 
//    WWDG_CNT=tr&WWDG_CNT; //??? WWDG_CNT. 
//    WWDG_SetPrescaler(fprer); //?? IWDG ???? 
//    WWDG_SetWindowValue(wr); //????? 
//    WWDG_Enable(WWDG_CNT); //?????,?? counter 
//    WWDG_ClearFlag(); //??????????? 
//    WWDG_NVIC_Init(); //???????? NVIC 
//    WWDG_EnableIT(); //?????????
}

void WWDG_IRQHandler(void){
    if(WWDG_GetFlagStatus() == SET){
        WWDG_ClearFlag();
        WWDG_SetCounter(WWDOG_CNT);
        LED1 = !LED1;
//        cur = GPIO_ReadOutputDataBit(GPIOE,GPIO_Pin_5);
//        if(cur == Bit_RESET){
//            GPIO_SetBits(GPIOE,GPIO_Pin_5);
//        }else{
//            GPIO_ResetBits(GPIOE,GPIO_Pin_5);
//        }
    }
}

