#ifndef _OELD_H
#define _OELD_H
#include "MK60_gpio.h"
/********************************************************************/
/*-----------------------------------------------------------------------
LCD_init          : OLED��ʼ��

��д����          ��2012-11-01
����޸�����      ��2012-11-01
-----------------------------------------------------------------------*/

void OLED_WR_Byte(char dat,char cmd);	    //��SSD1306д��һ���ֽڡ�
void OLED_Display_On(void);      //����OLED��ʾ 
void OLED_Display_Off(void);     //�ر�OLED��ʾ 
void OLED_Refresh_Gram(void);		 //�����Դ浽OLED  
							   		    
void OLED_Init(void);   //OLED��ʼ������
void OLED_Clear(void);  //��������,������,������Ļ�Ǻ�ɫ��!��û����һ��!!!	 
void OLED_DrawPoint(unsigned short x,char y,char t);  //���� 
void OLED_Fill(char x1,char y1,char x2,char y2,char dot);  //x1,y1,x2,y2 �������ĶԽ�����
void OLED_ShowChar(char x,char y,char chr,char size,char mode);  //��ָ��λ����ʾһ���ַ�,���������ַ�
void OLED_ShowNum(char x,char y,int num,char len,char size);  //��ʾ2������
void OLED_Show_Num(char x,char y,int num,char len,char size);	//��ʾ��������
void OLED_ShowString(char x,char y,const char *p,char size);	 //��ʾ�ַ���
void OLED_Line(uint8_t A[][3],uint8_t hang_stop);
void OLED_MidLine(uint8_t B[]);
void OLED_photo(uint8_t** ppData);
void OLED_photo_7620(int8_t image[60][120]);
void Dly_ms(uint16_t ms);  //MS��ʱ����
void OLED_ShowChineseLattice16(uint16_t n,uint16_t m,uint8_t len,uint8_t a[][32],uint8_t mode);
void LCD_ShowChineseAndEnglish(uint16_t x0,uint16_t y0,uint8_t *p,uint8_t size);
/********************************************************************/

#endif
