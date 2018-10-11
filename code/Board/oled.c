#include "common.h"
#include "oled.h"	
//#include "VCAN_camera.h"
#include "oledfont.h"  	
#include "stdlib.h"	   
#include "chinese.h"

//OLEDģʽ����
//0:4�ߴ���ģʽ
//1:����8080ģʽ
#define OLED_MODE 0 
int OLED_GRAM[132][8];	 
		    						  
//-----------------OLED�˿ڶ���----------------  

//#define OLED_SDA  PCout(17)  //D1				   
//#define OLED_SCL  PCout(16)  //D0
//#define OLED_RST  PCout(18)  //RES
//#define OLED_DC   PCout(19)  //DC
                        

#define OLED_RST_Clr() gpio_set (PTC18, 0)   //RES C18
#define OLED_RST_Set() gpio_set (PTC18, 1)

#define OLED_RS_Clr() gpio_set (PTC19, 0)     //DC C19
#define OLED_RS_Set() gpio_set (PTC19, 1)

#define OLED_SCLK_Clr() gpio_set (PTC16, 0)  //D0 C16
#define OLED_SCLK_Set() gpio_set (PTC16, 1)

#define OLED_SDIN_Clr() gpio_set (PTC17, 0)  //D1 C17
#define OLED_SDIN_Set() gpio_set (PTC17, 1)   

//#define OLED_RST_Clr() OLED_RST=0   //RES
//#define OLED_RST_Set() OLED_RST=1
//
//#define OLED_RS_Clr() OLED_DC=0     //DC
//#define OLED_RS_Set() OLED_DC=1
//
//#define OLED_SCLK_Clr() OLED_SCL=0  //D0
//#define OLED_SCLK_Set() OLED_SCL=1
//
//#define OLED_SDIN_Clr() OLED_SDA=0  //D1
//#define OLED_SDIN_Set() OLED_SDA=1
 		     
#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����
//��ʼ��OLED
void OLED_Init(void)
{
	gpio_init (PTC16,GPO,1);
        gpio_init (PTC17,GPO,1);
        gpio_init (PTC18,GPO,1);
        gpio_init (PTC19,GPO,1);

//	OLED_SCL=1;   //D0
//	OLED_SDA=1;   //D1
//	OLED_RST=1;   //RES
//	OLED_DC=1; 	 //DC
	
	OLED_RST_Clr();
	Dly_ms(100);
	OLED_RST_Set(); 
					  
	OLED_WR_Byte(0xAE,OLED_CMD); //�ر���ʾ
	OLED_WR_Byte(0xD5,OLED_CMD); //����ʱ�ӷ�Ƶ����,��Ƶ��
	OLED_WR_Byte(80,OLED_CMD);   //[3:0],��Ƶ����;[7:4],��Ƶ��
	OLED_WR_Byte(0xA8,OLED_CMD); //��������·��
	OLED_WR_Byte(0X3F,OLED_CMD); //Ĭ��0X3F(1/64) 
	OLED_WR_Byte(0xD3,OLED_CMD); //������ʾƫ��
	OLED_WR_Byte(0X00,OLED_CMD); //Ĭ��Ϊ0

	OLED_WR_Byte(0x40,OLED_CMD); //������ʾ��ʼ�� [5:0],����.
													    
	OLED_WR_Byte(0x8D,OLED_CMD); //��ɱ�����
	OLED_WR_Byte(0x14,OLED_CMD); //bit2������/�ر�
	OLED_WR_Byte(0x20,OLED_CMD); //�����ڴ��ַģʽ
	OLED_WR_Byte(0x02,OLED_CMD); //[1:0],00���е�ַģʽ;01���е�ַģʽ;10,ҳ��ַģʽ;Ĭ��10;
	OLED_WR_Byte(0xA1,OLED_CMD); //���ض�������,bit0:0,0->0;1,0->127;
	OLED_WR_Byte(0xC0,OLED_CMD); //����COMɨ�跽��;bit3:0,��ͨģʽ;1,�ض���ģʽ COM[N-1]->COM0;N:����·��
	OLED_WR_Byte(0xDA,OLED_CMD); //����COMӲ����������
	OLED_WR_Byte(0x12,OLED_CMD); //[5:4]����
		 
	OLED_WR_Byte(0x81,OLED_CMD); //�Աȶ�����
	OLED_WR_Byte(0xEF,OLED_CMD); //1~255;Ĭ��0X7F (��������,Խ��Խ��)
	OLED_WR_Byte(0xD9,OLED_CMD); //����Ԥ�������
	OLED_WR_Byte(0xf1,OLED_CMD); //[3:0],PHASE 1;[7:4],PHASE 2;
	OLED_WR_Byte(0xDB,OLED_CMD); //����VCOMH ��ѹ����
	OLED_WR_Byte(0x30,OLED_CMD); //[6:4] 000,0.65*vcc;001,0.77*vcc;011,0.83*vcc;

	OLED_WR_Byte(0xA4,OLED_CMD); //ȫ����ʾ����;bit0:1,����;0,�ر�;(����/����)
	OLED_WR_Byte(0xA6,OLED_CMD); //������ʾ��ʽ;bit0:1,������ʾ;0,������ʾ	    						   
	OLED_WR_Byte(0xAF,OLED_CMD); //������ʾ	 
	OLED_Clear();
}
//MS��ʱ����
void Dly_ms(uint16_t ms)
{
   uint16_t ii,jj;
   if (ms<1) ms=1;
   ms = ms*12 ;
   for(ii=0;ii<ms;ii++)
     for(jj=0;jj<1335;jj++);  //16MHz--1ms
			// for(jj=0;jj<4006;jj++);  //48MHz--1ms
      // for(jj=0;jj<5341;jj++);    //64MHz--1ms
}
//�����Դ浽OLED  
void OLED_Refresh_Gram(void)
{
	unsigned short i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //����ҳ��ַ��0~7��
		OLED_WR_Byte (0x00,OLED_CMD);      //������ʾλ�á��е͵�ַ
		OLED_WR_Byte (0x10,OLED_CMD);      //������ʾλ�á��иߵ�ַ   
		for(n=0;n<131;n++)
			OLED_WR_Byte(OLED_GRAM[n][i],OLED_DATA); 
	}   
}
#if OLED_MODE==1
//��SSD1306д��һ���ֽڡ�
//dat:Ҫд�������/����
//cmd:����/�����־ 0,��ʾ����;1,��ʾ����;
void OLED_WR_Byte(char dat,char cmd)
{
	DATAOUT(dat);	    
	if(cmd)
	  OLED_RS_Set();
	else 
	  OLED_RS_Clr();		   
//	OLED_CS_Clr();
//	OLED_WR_Clr();	 
//	OLED_WR_Set();
//	OLED_CS_Set();	  
	OLED_RS_Set();	 
} 	    	    
#else
//��SSD1306д��һ���ֽڡ�
//dat:Ҫд�������/����
//cmd:����/�����־ 0,��ʾ����;1,��ʾ����;
void OLED_WR_Byte(char dat,char cmd)
{	
	char i;			  
	if(cmd)
	  OLED_RS_Set();
	else 
	  OLED_RS_Clr();		  
//	OLED_CS_Clr();
	for(i=0;i<8;i++)
	{			  
		OLED_SCLK_Clr();
		if(dat&0x80)
		   OLED_SDIN_Set();
		else 
		   OLED_SDIN_Clr();
		OLED_SCLK_Set();
		dat<<=1;   
	}				 		  
//	OLED_CS_Set();
	OLED_RS_Set();   	  
} 
#endif
	  	  
//����OLED��ʾ    
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC����
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
//�ر�OLED��ʾ     
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC����
	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
}		   			 
//��������,������,������Ļ�Ǻ�ɫ��!��û����һ��!!!	  
void OLED_Clear(void)  
{  
	unsigned short i,n;  
	for(i=0;i<8;i++)for(n=0;n<130;n++)OLED_GRAM[n][i]=0X00;  
	OLED_Refresh_Gram();//������ʾ
}
//���� 
//x:0~127
//y:0~63
//t:1 ��� 0,���				   
void OLED_DrawPoint(unsigned short x,char y,char t)
{
	char pos,bx,temp=0;
	if(x>131||y>63)return;//������Χ��.
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);
	if(t)OLED_GRAM[x][pos]|=temp;
	else OLED_GRAM[x][pos]&=~temp;	    
}
//x1,y1,x2,y2 �������ĶԽ�����
//ȷ��x1<=x2;y1<=y2 0<=x1<=127 0<=y1<=63	 	 
//dot:0,���;1,���	  
void OLED_Fill(char x1,char y1,char x2,char y2,char dot)  
{  
	char x,y;  
	for(x=x1;x<=x2;x++)
	{
		for(y=y1;y<=y2;y++)OLED_DrawPoint(x,y,dot);
	}													    
	OLED_Refresh_Gram();//������ʾ
}
//��ָ��λ����ʾһ���ַ�,���������ַ�
//x:0~127
//y:0~63
//mode:0,������ʾ;1,������ʾ				 
//size:ѡ������ 16/12 
void OLED_ShowChar(char x,char y,char chr,char size,char mode)
{      			    
	char temp,t,t1;
	char y0=y;
	chr=chr-' ';//�õ�ƫ�ƺ��ֵ				   
    for(t=0;t<size;t++)
    {   
		if(size==12)temp=oled_asc2_1206[chr][t];  //����1206����
		else temp=oled_asc2_1608[chr][t];		 //����1608���� 	                          
        for(t1=0;t1<8;t1++)
		{
			if(temp&0x80)OLED_DrawPoint(x,y,mode);
			else OLED_DrawPoint(x,y,!mode);
			temp<<=1;
			y++;
			if((y-y0)==size)
			{
				y=y0;
				x++;
				break;
			}
		}  	 
    }          
}
//m^n����
unsigned int oled_pow(char m,char n)
{
	unsigned int result=1;	 
	while(n--)result*=m;    
	return result;
}				  
//��ʾ2������
//x,y :�������	 
//len :���ֵ�λ��
//size:�����С
//mode:ģʽ	0,���ģʽ;1,����ģʽ
//num:��ֵ(0~4294967295);	 		  
void OLED_ShowNum(char x,char y,int num,char len,char size)
{         	
	char t,temp;
	char enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size/2)*t,y,' ',size,1);
				continue;
			}else enshow=1; 
		 	 
		}
	 	OLED_ShowChar(x+(size/2)*t,y,temp+'0',size,1); 
	}
} 

void OLED_Show_Num(char x,char y,int num,char len,char size)
{   
	char t,temp;
	char enshow=0;			
	if(num<0)
	{
		OLED_ShowChar(x,y,'-',size,1);
		num = -num;
	}
	else
	{
		OLED_ShowChar(x,y,'+',size,1);
	}	
	x += size/2;
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size/2)*t,y,'0',size,1);
				continue;
			}else enshow=1; 
		 	 
		}
	 	OLED_ShowChar(x+(size/2)*t,y,temp+'0',size,1); 
	}
} 

//��ʾ�ַ���
//x,y:�������  
//*p:�ַ�����ʼ��ַ
//��16����
void OLED_ShowString(char x,char y,const char *p,char size)
{
// #define MAX_CHAR_POSX 122
	#define MAX_CHAR_POSX 126
	#define MAX_CHAR_POSY 58          
    while(*p!='\0')
    {       
			if(size == 16)
			{
        if(x>MAX_CHAR_POSX){x=0;y+=16;}
        if(y>MAX_CHAR_POSY){y=x=0;OLED_Clear();}
        OLED_ShowChar(x,y,*p,16,1);	 
        x+=8;
        p++;
			}
			if(size == 12)
			{
				if(x>MAX_CHAR_POSX){x=0;y+=12;}
        if(y>MAX_CHAR_POSY){y=x=0;OLED_Clear();}
        OLED_ShowChar(x,y,*p,12,1);	 
        x+=6;
        p++;
			}
    }  
}	
//�Ե���ķ�ʽ��ʾ����
//����ʽ�����룬˳��ȡģ
void OLED_ShowChineseLattice16(uint16_t n,uint16_t m,uint8_t len,uint8_t a[][32],uint8_t mode)    
{	
	uint16_t i,j;
	uint16_t m0=m,x=n;
	uint8_t num,temp;
	for(num=0;num<len;num++)
	{
		for(i=0;i<32;i++)
		{   
			temp=a[num][i];							
			for(j=0;j<8;j++)
			{		
        if((n-x)%16==0)		
        if((128-n)<16)
				{
					if(mode==1)
					{
					n=x;
					m+=16;
					m0=m;
					}
					if(mode==0)
					{
					n=3;
					m+=16;
					m0=m;
					}
				}				
				if(temp&0x80)OLED_DrawPoint(n,m,1);
				temp<<=1;
				m++;
				if(m>64)return;		//��������
				if((m-m0)==16)
				{
					m=m0;
					n++;
					if(n>128)return;	//��������
					break;
				}
			} 	 
		} 
  }	
}	
void LCD_ShowChineseAndEnglish(uint16_t x0,uint16_t y0,uint8_t *p,uint8_t size)
{
	int y1=y0,x1=x0;
	char temp;
	char a,b;
	char num;
//	char bits;
	char English_Chinese;    //��Ӣ��ģʽ��ʾ  1��Ӣ�� 0������

//	bits=sizeof(struct china);
  while(*p !='\0')	 //��C�������ַ��������ԡ�\0����β
	{
		English_Chinese=1;   //ÿ��ɨ��Ĭ��ΪӢ��
    for (a=0;a<64; a++)
		{
			if ((table[a].Index[0] ==*p)&&(table[a].Index[1] == *(p+1)))
			{
				English_Chinese=0;  //�ѳɹ���⵽�����룬��ģʽ����Ϊ����
		    //X����ʣ��Ŀ�Ȳ�����ʾһ�����֣�����		
				if((127-x0)<size)
				{
					x0=x1;
					y1+=(size+2);
				}	
        //��ʾ����				
        for(b=2;b<34;b++)           //2���ֽڵĵ�ַλ
				{
					temp=table[a].Index[b];
					for(num=0;num<8;num++)
					{
					  if(temp&0x80)OLED_DrawPoint(x0,y0,1);
						temp<<=1;
						y0++;
				    if((y0-y1)==size)
				    {
              y0=y1;
					    x0++;
					    break;
            }
          }			
        }
       }
		}	
		if(English_Chinese==1)
		{
			//X����ʣ��Ŀ�Ȳ�����ʾһ�����֣�����		
			if((127-x0)<(size/2))
			{
				x0=x1;
				y1+=(size+2);
		  }					
    	OLED_ShowChar(x0,y1,*p,size,1);//��ʾASCII�ַ�	  
			x0+=(size/2);
			p+=1;
    }
		else p+= 2;
  }
}

void OLED_Line(uint8_t A[][3],uint8_t hang_stop)
{
	uint8_t i;
  for(i=0;i<hang_stop;i++)
	{
		OLED_DrawPoint((A[i][0]),i,1);
		OLED_DrawPoint((A[i][1]),i,1);
		OLED_DrawPoint((A[i][2]),i,1);
	}
}

void OLED_MidLine(uint8_t B[])
{
	uint16_t i;
  for(i=0;i<50;i++)
	{
		if(B[i]>0)
		OLED_DrawPoint(B[i],i,1);

	}
}

void OLED_photo(uint8_t ** ppData)
{
	uint16_t i,j;
  for(i=0;i<60;i++)
	{
		for(j=0;j<10;j++)
		{
			if(((ppData[i][j]>>7) & 0x01)>0) OLED_DrawPoint(8*j+20+0,i,1);
				else OLED_DrawPoint(8*j+20+0,i,0);
			if(((ppData[i][j]>>6) & 0x01)>0) OLED_DrawPoint(8*j+20+1,i,1);
				else OLED_DrawPoint(8*j+20+1,i,0);
			if(((ppData[i][j]>>5) & 0x01)>0) OLED_DrawPoint(8*j+20+2,i,1);
				else OLED_DrawPoint(8*j+20+2,i,0);
			if(((ppData[i][j]>>4) & 0x01)>0) OLED_DrawPoint(8*j+20+3,i,1);
				else OLED_DrawPoint(8*j+20+3,i,0);
			if(((ppData[i][j]>>3) & 0x01)>0) OLED_DrawPoint(8*j+20+4,i,1);
				else OLED_DrawPoint(8*j+20+4,i,0);
			if(((ppData[i][j]>>2) & 0x01)>0) OLED_DrawPoint(8*j+20+5,i,1);
				else OLED_DrawPoint(8*j+20+5,i,0);
			if(((ppData[i][j]>>1) & 0x01)>0) OLED_DrawPoint(8*j+20+6,i,1);
				else OLED_DrawPoint(8*j+20+6,i,0);
			if(((ppData[i][j]>>0) & 0x01)>0) OLED_DrawPoint(8*j+20+7,i,1);
				else OLED_DrawPoint(8*j+20+7,i,0);
				
		}
	}
}
void OLED_photo_7620(int8_t image[60][120])
{
	uint16_t i,j;
  for(i=0;i<60;i++)
	{
		for(j=0;j<120;j++)
		{
			if(image[i][j]>0) OLED_DrawPoint(j,i,1);
				else OLED_DrawPoint(j,i,0);		
		}
	}
}
