#include"SOLGUI_Include.h"

void SOLGUI_Pictrue(uint32_t x0,uint32_t y0,const uint8_t *pic,uint32_t x_len,uint32_t y_len,uint8_t mode)		//原尺寸直出
{
	int16_t y_i=0,x_i=0;
	y0+=y_len; 	//将原点改为左下角（原本原点为右上角）
	for(x_i=0;x_i<x_len;x_i++)
	{
		for(y_i=0;y_i<y_len;y_i++)
		{
		   if(SOLGUI_GetPixel(x_i,y_i,pic,x_len,y_len)) SOLGUI_DrawPoint(x0+x_i,y0-y_i,mode);
		   else SOLGUI_DrawPoint(x0+x_i,y0-y_i,!mode);
		}
	}
}

uint8_t SOLGUI_GetPixel(uint32_t x,uint32_t y,const uint8_t *pic,uint32_t x_len,uint32_t y_len)		//获取像素点值（原点为左上角为）
{     
	return bit_istrue(*(pic+(y>>3)*x_len+x),bit((7-y%8)));
}
