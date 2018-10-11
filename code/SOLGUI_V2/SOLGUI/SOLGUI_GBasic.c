#include"SOLGUI_Include.h"

#if GBASIC_LINE_EN==1||MENU_FRAME_EN==1


void _LineModes(int16_t x,int16_t y,uint8_t mode,uint32_t cnt)  		//线型
{
	switch(mode&0x03)
	{
		case 0:SOLGUI_DrawPoint(x,y,0);break;  			//0擦除线
		case 2:
		{
			if(cnt%2>=1) SOLGUI_DrawPoint(x,y,1); 	//2点线	
			else	SOLGUI_DrawPoint(x,y,0);break;	
		}
		case 3:
		{
			if(cnt%4>=2) SOLGUI_DrawPoint(x,y,1);  		//3短划线
			else	SOLGUI_DrawPoint(x,y,0);break;		
		}
		case 1:;										//1实线
		default:SOLGUI_DrawPoint(x,y,1);	   			
	}	
}

void SOLGUI_GBasic_Line(uint32_t x0,uint32_t y0,uint32_t xEnd,uint32_t yEnd,uint8_t mode)		//画线（mode：0擦除线，1实线，2点线，3短划线）
{
	int16_t dx=xEnd-x0;
	int16_t dy=yEnd-y0;
	int16_t ux=((dx>0)<<1)-1;//x的增量方向，取或-1
	int16_t uy=((dy>0)<<1)-1;//y的增量方向，取或-1
	int16_t x=x0,y=y0,eps;//eps为累加误差
	uint32_t cnt=0;
	
	eps=0;
	dx=SOLGUI_Fabs(dx);
	dy=SOLGUI_Fabs(dy); 
	if(dx>dy) 
	{
		for(x=x0;x!=xEnd+ux;x+=ux)
		{
			cnt++;
			_LineModes(x,y,mode,cnt);
			eps+=dy;
			if((eps<<1)>=dx)
			{
				y+=uy;
				eps-=dx;
			}
		}
	}
	else
	{
		for(y=y0;y!=yEnd+uy;y+=uy)
		{
			cnt++;
			_LineModes(x,y,mode,cnt);
			eps+=dx;
			if((eps<<1)>=dy)
			{
				x+=ux; 
				eps-=dy;
			}
		}
	}   
}

void SOLGUI_GBasic_MultiLine(const uint32_t *points,uint8_t num,uint8_t mode)
{
	uint32_t x0,y0;
	uint32_t x1,y1;
	uint8_t i=0;
	if(num<=0) return;		//没有点
	if(1==num)				// 单点
	{  
		x0=*points++;
		y0=*points;
		SOLGUI_DrawPoint(x0,y0,1);
	}
   /* 画多条线条 */
	x0=*points++;					// 取出第一点坐标值，作为原起点坐标值
	y0=*points++;
	for(i=1;i<num;i++)
	{  
		x1=*points++;				// 取出下一点坐标值
		y1=*points++;
		SOLGUI_GBasic_Line(x0,y0,x1,y1,mode);
		x0=x1;					// 更新原起点坐标
		y0=y1;
	}

}

#endif


#if GBASIC_RECTANGLE_EN==1||MENU_FRAME_EN==1

void  SOLGUI_GBasic_Rectangle(uint32_t x0,uint32_t y0,uint32_t x1,uint32_t y1,uint8_t mode)		//画矩形（左下角，右上角，模式）
{
	uint32_t i=0;
	uint8_t m=0;
	if(bit_istrue(mode,bit(2))||(mode==DELETE))	//是否填充
	{
		if(x0>x1) {i=x0;x0=x1;x1=i;}	//若x0>x1，则x0与x1交换
		if(y0>y1) {i=y0;y0=y1;y1=i;}	//若y0>y1，则y0与y1交换
		if(mode==DELETE) m=DELETE;
		else m=ACTUAL;
		if(y0==y1) 
		{  
			SOLGUI_GBasic_Line(x0,y0,x1,y0,m);
			return;
		}
		if(x0==x1) 
		{  
			SOLGUI_GBasic_Line(x0,y0,x0,y1,m);
			return;
		}						
		while(y0<=y1)						
		{  
			SOLGUI_GBasic_Line(x0,y0,x1,y0,m);
			y0++;				
		}
	}
	else			   //非填充
	{
		SOLGUI_GBasic_Line(x0,y0,x0,y1,mode);
		SOLGUI_GBasic_Line(x0,y1,x1,y1,mode);
		SOLGUI_GBasic_Line(x1,y0,x1,y1,mode);
		SOLGUI_GBasic_Line(x0,y0,x1,y0,mode);
	}
}

#endif


#if GBASIC_CIRCLE_EN==1||MENU_FRAME_EN==1
						                        
void SOLGUI_GBasic_Circle(uint32_t x0,uint32_t y0,uint32_t r,uint8_t mode)
{
	u16 x=0,y=r;
	int16_t delta,temp;
	
	delta = 3-(r<<1);  //3-r*2
	while(y>x)
	{
		if(mode==FILL)
		{
			SOLGUI_GBasic_Line(x0+x,y0+y,x0-x,y0+y,ACTUAL);
			SOLGUI_GBasic_Line(x0+x,y0-y,x0-x,y0-y,ACTUAL);
			SOLGUI_GBasic_Line(x0+y,y0+x,x0-y,y0+x,ACTUAL);
			SOLGUI_GBasic_Line(x0+y,y0-x,x0-y,y0-x,ACTUAL);
		}
		else
		{
			SOLGUI_DrawPoint(x0+x,y0+y,mode);
			SOLGUI_DrawPoint(x0-x,y0+y,mode);
			SOLGUI_DrawPoint(x0+x,y0-y,mode);
			SOLGUI_DrawPoint(x0-x,y0-y,mode);
			SOLGUI_DrawPoint(x0+y,y0+x,mode);
			SOLGUI_DrawPoint(x0-y,y0+x,mode);
			SOLGUI_DrawPoint(x0+y,y0-x,mode);
			SOLGUI_DrawPoint(x0-y,y0-x,mode);
		}
		x++;
		if(delta >= 0)
		{
			y--;
			temp= (x<<2); //x*4
			temp-=(y<<2); //y*4
			delta += (temp+10);
		}
		else
		{
			delta += ((x<<2)+6); //x*4 + 6
		}
	}
}

#endif

