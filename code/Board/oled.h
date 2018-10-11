#ifndef _OELD_H
#define _OELD_H
#include "MK60_gpio.h"
/********************************************************************/
/*-----------------------------------------------------------------------
LCD_init          : OLED初始化

编写日期          ：2012-11-01
最后修改日期      ：2012-11-01
-----------------------------------------------------------------------*/

void OLED_WR_Byte(char dat,char cmd);	    //向SSD1306写入一个字节。
void OLED_Display_On(void);      //开启OLED显示 
void OLED_Display_Off(void);     //关闭OLED显示 
void OLED_Refresh_Gram(void);		 //更新显存到OLED  
							   		    
void OLED_Init(void);   //OLED初始化函数
void OLED_Clear(void);  //清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!	 
void OLED_DrawPoint(unsigned short x,char y,char t);  //画点 
void OLED_Fill(char x1,char y1,char x2,char y2,char dot);  //x1,y1,x2,y2 填充区域的对角坐标
void OLED_ShowChar(char x,char y,char chr,char size,char mode);  //在指定位置显示一个字符,包括部分字符
void OLED_ShowNum(char x,char y,int num,char len,char size);  //显示2个数字
void OLED_Show_Num(char x,char y,int num,char len,char size);	//显示正负数字
void OLED_ShowString(char x,char y,const char *p,char size);	 //显示字符串
void OLED_Line(uint8_t A[][3],uint8_t hang_stop);
void OLED_MidLine(uint8_t B[]);
void OLED_photo(uint8_t** ppData);
void OLED_photo_7620(int8_t image[60][120]);
void Dly_ms(uint16_t ms);  //MS延时函数
void OLED_ShowChineseLattice16(uint16_t n,uint16_t m,uint8_t len,uint8_t a[][32],uint8_t mode);
void LCD_ShowChineseAndEnglish(uint16_t x0,uint16_t y0,uint8_t *p,uint8_t size);
/********************************************************************/

#endif
