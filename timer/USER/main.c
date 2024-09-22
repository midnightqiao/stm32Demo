#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"
#include "timer.h"

char num = 0;
int main()
{
   TIM3_Int_Init(9999,7200-1);
    uart_init(115200);
    delay_init();
    
    LCD_Init();
    
    LCD_Clear(WHITE);
    POINT_COLOR = RED;
    
    while(1){
       LCD_ShowNum(20,20,num,3,24);
    }
}

