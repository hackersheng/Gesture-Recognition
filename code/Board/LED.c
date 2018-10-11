/*!
 * @file       LED.c
 * @brief      LED配置
 * @author     胡冀威
 * @version    v1.0
 * @date       2018-06-08
 */

#include "LED.h"

/*!
 *  @brief      LED接口初始化
 *  @since      v1.0
 */
void LED_Init(void)
{
    gpio_init(PTC2, GPO, 1);
	port_init_NoALT(PTC2, PULLUP);
    gpio_init(PTC1, GPO, 1);
	port_init_NoALT(PTC1, PULLUP);
    gpio_init(PTC0, GPO, 1);
	port_init_NoALT(PTC0, PULLUP);
}

/*!
 *  @brief      设置一个LED的亮灭
 *  @param      led    LED编号
 *  @param      mode   0灭， 1亮
 *  @since      v1.0
 *  Sample usage:       LED_Set(LED1， 1);
 */
void LED_Set(uint8 led, uint8 mode)
{
    switch(led)
    {
        case LED1:
            gpio_set(PTC2, 1 - mode);
        break;

        case LED2:
            gpio_set(PTC1, 1 - mode);
        break;

        case LED3:
            gpio_set(PTC0, 1 - mode);
        break;
    }
}

/*!
 *  @brief      翻转一次LED
 *  @param      led    LED编号
 *  @since      v1.0
 *  Sample usage:       LED_Toggle(LED1);
 */
void LED_Toggle(uint8 led)
{
    switch(led)
    {
        case LED1:
            gpio_turn(PTC2);
        break;

        case LED2:
            gpio_turn(PTC1);
        break;

        case LED3:
            gpio_turn(PTC0);
        break;
    }
}



