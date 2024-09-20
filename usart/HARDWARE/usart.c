#include "usart.h"

void usart1_init(void){
    GPIO_InitTypeDef GPIO_InitStruct;
    USART_InitTypeDef USART_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
    
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStruct.GPIO_Pin = USART1_TX;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA,&GPIO_InitStruct);
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStruct.GPIO_Pin = USART1_RX;
    GPIO_Init(GPIOA,&GPIO_InitStruct);
    USART_DeInit(USART1);
    USART_InitStruct.USART_BaudRate = 115200;
    USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;
    USART_InitStruct.USART_Parity = USART_Parity_No;
    USART_InitStruct.USART_StopBits = USART_StopBits_1;
    USART_InitStruct.USART_WordLength = USART_WordLength_8b;
    USART_Init(USART1,&USART_InitStruct);
    
    //需要配置NVIC的优先级组（只需要配置一次，目前在这里配置，后续可更改）
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    //配置串口1的中断
    NVIC_InitStruct.NVIC_IRQChannel = USART1_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
    NVIC_Init(&NVIC_InitStruct);
    //配置窗口接收响应中断
    USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
    USART_Cmd(USART1,ENABLE);
}

void USART1_IRQHandler(){
    if(USART_GetITStatus(USART1,USART_IT_RXNE) == SET){ 
        uint16_t r = USART_ReceiveData(USART1);
        USART_ClearITPendingBit(USART1,USART_IT_RXNE);
        USART_SendData(USART1,r);      
    }
}

void usart1_SendString(char* chs,int len){
    int i=0;
    for(i=0;i<len;){
        if(USART_GetFlagStatus(USART1,USART_FLAG_TC)){
            USART_SendData(USART1,chs[i]);
            i++;
        }
    }
       
}

