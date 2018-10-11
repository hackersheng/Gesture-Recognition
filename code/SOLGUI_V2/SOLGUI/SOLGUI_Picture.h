#ifndef SOLGUI_PICTURE_H
#define SOLGUI_PICTURE_H

//##########################【mode参数】############################

#define	NORMAL	0x01	//正常显示
#define	REVERSE	0x00	//反白显示

//##########################【API】############################
void SOLGUI_Pictrue(uint32_t x0,uint32_t y0,const uint8_t *pic,uint32_t x_len,uint32_t y_len,uint8_t mode);		//单色图片显示（mode：0反白，1正常）
//应储存为1维数组，取模方式列行式：数据水平，字节垂直，从左到右，从上到下扫描
uint8_t SOLGUI_GetPixel(uint32_t x,uint32_t y,const uint8_t *pic,uint32_t x_len,uint32_t y_len);				//获取像素点值（返回1点亮，0熄灭）

#endif

