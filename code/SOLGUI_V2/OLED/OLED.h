#ifndef __OLED_H
#define __OLED_H			  	 

#include "common.h"
#include "include.h"

//-----------------OLED端口定义----------------  					   
#define OLED_D0_H    gpio_set(PTC8, 1)
#define OLED_D0_L    gpio_set(PTC8, 0)

#define OLED_D1_H    gpio_set(PTC7, 1)
#define OLED_D1_L    gpio_set(PTC7, 0)

#define OLED_RES_H   gpio_set(PTC6, 1)
#define OLED_RES_L   gpio_set(PTC6, 0)

#define OLED_DC_H    gpio_set(PTC5, 1)
#define OLED_DC_L    gpio_set(PTC5, 0)

#define OLED_CS_H    gpio_set(PTC4, 1)
#define OLED_CS_L    gpio_set(PTC4, 0)


#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据
//OLED控制用函数
void OLED_Fill(uint8_t GRAM[128][8]);
void OLED_WR_Byte(uint8_t dat,uint8_t cmd);
void OLED_Init(void);
#endif  
	 



