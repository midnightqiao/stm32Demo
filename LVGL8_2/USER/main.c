#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"
#include "iwdg.h"
#include "key.h"
#include "led.h"
#include "wwdg.h"
#include "timer.h"
#include "lvgl.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"

int main()
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    delay_init();
    LED_Init();
    
    LED1 = 0;
    TIM3_Int_Init(9999,7199);
    
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    LED0 = 0;
    lv_obj_t * switch1 = lv_switch_create(lv_scr_act());
    lv_obj_set_size(switch1,120,60);
    lv_obj_set_align(switch1,LV_ALIGN_CENTER);
    while(1){
        delay_ms(5);
        lv_timer_handler();
    }
}

