#ifdef USE_MYSELF_USART

#include "stm32f10x.h"

#define USART1_TX GPIO_Pin_9
#define USART1_RX GPIO_Pin_10

void usart1_init(void);
void usart1_SendString(char* chs,int len);

#endif