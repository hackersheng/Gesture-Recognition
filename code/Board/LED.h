/*!
 * @file       LED.h
 * @brief      LED配置
 * @author     胡冀威
 * @version    v1.0
 * @date       2018-06-08
 */

#ifndef __LED_H
#define __LED_H			  	 

#include "common.h"
#include "include.h"

#define LED1 1
#define LED2 2
#define LED3 3

void LED_Init(void);
void LED_Set(uint8 led, uint8 mode);
void LED_Toggle(uint8 led);
#endif  
	 

