#ifndef SOLGUI_GBASIC_H
#define SOLGUI_GBASIC_H

//##############################【mode参数】##############################
/*----------------------------------------------------------------------

	mode定义：
	mode[1:0]	线型控制：00灭，01实线，10点线，11短划线
	mode[2]		是否填充: 1填充，0不填充

----------------------------------------------------------------------*/
//-------------------【线型】
#define DELETE 		0x00		//消除
#define ACTUAL 		0x01		//实线
#define DOTTED 		0x02		//点线
#define DASHED 		0x03		//短划线
//-------------------【是否填充】
#define FILL		0x04		//实填充


//##############################【API】##############################
void SOLGUI_GBasic_Line(uint32_t x0,uint32_t y0,uint32_t xEnd,uint32_t yEnd,uint8_t mode);	//画线（起点，终点，参数）
void SOLGUI_GBasic_Rectangle(uint32_t x0,uint32_t y0,uint32_t x1,uint32_t y1,uint8_t mode);		//画矩形（左下角，右上角，参数）
void SOLGUI_GBasic_MultiLine(const uint32_t *points,uint8_t num,uint8_t mode);		//连续画线（点数组指针，点数，参数）
void SOLGUI_GBasic_Circle(uint32_t x0,uint32_t y0,uint32_t r,uint8_t mode);			//画圆（圆心，半径，参数）


#endif
