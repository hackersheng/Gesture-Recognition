#include "common.h"
#include "include.h"
1

//u8 idfind(u8 *buf,u8 *val,u8 len);
void caiquan(void);
void huaquan(void);
void xuexi(void);
void uart4_handler(void);
void pingjun();

unsigned char key,beep;
//unsigned char Res;
uint32 date0=0, date1=0, date2=0, date3=0;
int chua,chua1;
int fre0, fre1, fre2, fre3;
int date7[7];

static int fivemsec_flag;
static char ch,mh;



int x,y;
int j=0;
int sum=0;
int itum[4];
int temp;
int mg[16];
static int pd[8];


 int main(void)
 {	
	// double c,c1,c2,c3,c4,c5,c6,c7;
	//
	 
	 int u[99];
	 
         IIC_Init(); 
         IIC_Stop();
         FDC2214_Init(); 
	 uart_init(UART4,115200);     //³õÊ¼»¯´®¿Ú
    
     //uart_putstr   (UART4 ,"\n\n\n½ÓÊÕÖÐ¶Ï²âÊÔ£º");           //·¢ËÍ×Ö·û´®
      set_vector_handler(UART4_RX_TX_VECTORn,uart4_handler);   // ÉèÖÃÖÐ¶Ï·þÎñº¯Êýµ½ÖÐ¶ÏÏòÁ¿±íÀï
      uart_rx_irq_en (UART4);  
	
	 
	 DELAY_MS(5);  
        
         
	
	 
  while(1)
	{
		//printf("");
		//HMISends("t7.txt=\"1\"");
		//HMISends("t");
		//HMISendb(0xff);		
			//Res=USART_ReceiveData(USART2);
          FDC2214_GetChannelData(FDC2214_Channel_2, &date2);
          fre1 = FDC2214_CalculateFrequency(FDC2214_Channel_2, date2);
          fre2 = fre1/1000;
          pingjun();
        //  printf("%d\t\n",fre2);
          //DELAY_MS(300);
              
              
	  xuexi();
         
				

	  if(ch=='c')
          {
	 //printf("ss: %c",Res);
	  caiquan();
          //DELAY_MS(10);  
			
          }		
		   if(ch=='h')
		    {
		        huaquan();
                       // DELAY_MS(10);  
			
	            }
		}
              //DELAY_MS(50);  
	
	

}

void caiquan(void)
{
      
  if(fre2>pd[2]-25&&fre2<pd[2]+25)
	{
              gpio_init (PTC0,  GPO,0);    //Ç°×ó
              gpio_init (PTA17, GPO,1);    //Ç°ÓÒ
	      printf("t9.txt=\"²¼\"");
              uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
              uart_putchar   (UART4 , 0xff); 
              uart_putchar   (UART4 , 0xff); 
				
				//printf("²¼\r\n");
	}
	if(fre2>pd[0]-25&&fre2<pd[0]+25)
	{
              printf("t9.txt=\"Ê¯Í·\"");
              uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
              uart_putchar   (UART4 , 0xff); 
              uart_putchar   (UART4 , 0xff); 
				
					//printf("Ê¯Í·\r\n");
	}
       if(fre2>pd[1]-25&&fre2<pd[1]+25)
	{
              printf("t9.txt=\"¼ôµ¶\"");
              uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
              uart_putchar   (UART4 , 0xff); 
              uart_putchar   (UART4 , 0xff); 
				
				//printf("¼ôµ¶\r\n");
	}
  }
  
		////ÅÐ¶Ï²¼
  
	
 
void huaquan(void)
{
  if(fre2>pd[3]-12&&fre2<pd[3]+15)
		{
                  printf("t9.txt=\"1\"");
                uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
                uart_putchar   (UART4 , 0xff); 
                uart_putchar   (UART4 , 0xff); 
				
		//printf("1\r\n");
		}
		if(fre2>pd[4]-7&&fre2<pd[4]+12)
		{
                  printf("t9.txt=\"2\"");
                uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
                uart_putchar   (UART4 , 0xff); 
                uart_putchar   (UART4 , 0xff); 
		
		//printf("2\r\n");
		}
		if(fre2>pd[5]-7&&fre2<pd[5]+7)
		{
                  printf("t9.txt=\"3\"");
                uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
                uart_putchar   (UART4 , 0xff); 
                uart_putchar   (UART4 , 0xff); 
			
		//printf("3\r\n");
		}
		if(fre2>pd[6]-25&&fre2<pd[6]+10)
		{
                  printf("t9.txt=\"4\"");
                uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
                uart_putchar   (UART4 , 0xff); 
                uart_putchar   (UART4 , 0xff); 
			
		//printf("4\r\n");
		}
		if(fre2>pd[7]-99&&fre2<pd[7]+99)
		{
                  printf("t9.txt=\"5\"");
                uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
                uart_putchar   (UART4 , 0xff); 
                uart_putchar   (UART4 , 0xff); 
			
		//printf("5\r\n");
		}
  
		
}
/***Ñ§Ï°***/
	void xuexi(void)
	{	
		static int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;


		
		if(ch=='s')
		{
			ch=0;
                        
                        //printf("daolm");
                        DELAY_MS(100);  
		
				a++;
		}
		//printf("c0:%d\r\n",a);
		if(a==1)
		{
			//printf("t1:%d\r\n",t);
			mg[0]=fre2;
			a++;
		}
		//printf("c1:%d\r\n",a);
		if(a==3)
		{
                 
			//printf("t2:%d\r\n",t);
		mg[1]=fre2;
		pd[0]=(mg[0]+mg[1])/2;
                printf("t0.txt=\"yes\"");
                uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
                uart_putchar   (UART4 , 0xff); 
                uart_putchar   (UART4 , 0xff); 
		
			a=0;
		}
		
		//¼ôµ¶
		if(ch=='j')
		{
			ch=0;
                        DELAY_MS(10);  
		
		b++;
		}
		if(b==1)
		{
		        mg[2]=fre2;
			b++;
		}
		if(b==3)
		{
		mg[3]=fre2;
			pd[1]=(mg[2]+mg[3])/2;
                 printf("t1.txt=\"%d\"",fre2);
                uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
                uart_putchar   (UART4 , 0xff); 
                uart_putchar   (UART4 , 0xff); 
			
			b=0;
		}
		
		////////////²¼
		if(ch=='b')
		{
			ch=0;
                        DELAY_MS(10);  
		
		c++;
		}
		if(c==1)
		{
		mg[4]=fre2;
			c++;
		}
		if(c==3)
		{
		mg[5]=fre2;
			pd[2]=(mg[4]+mg[5])/2;
                        printf("t2.txt=\"yes\"");
                uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
                uart_putchar   (UART4 , 0xff); 
                uart_putchar   (UART4 , 0xff); 
			
			c=0;
		}
		
		///////////   1
		if(ch=='1')
		{
			ch=0;
                        DELAY_MS(10);  
	
		d++;
		}
		if(d==1)
		{
		mg[6]=fre2;
			d++;
		}
		if(d==3)
		{
		mg[7]=fre2;
			pd[3]=(mg[6]+mg[7])/2;
                        printf("t3.txt=\"yes\"");
                uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
                uart_putchar   (UART4 , 0xff); 
                uart_putchar   (UART4 , 0xff); 
			
			d=0;
		}
		
		///////////  2
		if(ch=='2')
		{
			ch=0;
                        DELAY_MS(10);  
			
		e++;
		}
		if(e==1)
		{
		mg[8]=fre2;
			e++;
		}
		if(e==3)
		{
		mg[9]=fre2;
			pd[4]=(mg[8]+mg[9])/2;
                        printf("t4.txt=\"yes\"");
                uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
                uart_putchar   (UART4 , 0xff); 
                uart_putchar   (UART4 , 0xff); 
			
			e=0;
		}
		
		//////      3
		if(ch=='3')
		{
			ch=0;
                        DELAY_MS(10);  
	
		f++;
		}
		if(f==1)
		{
		mg[10]=fre2;
			f++;
		}
		if(f==3)
		{
		mg[11]=fre2;
			pd[5]=(mg[10]+mg[11])/2;
                        printf("t5.txt=\"yes\"");
                uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
                uart_putchar   (UART4 , 0xff); 
                uart_putchar   (UART4 , 0xff); 
			
			f=0;
		}
		
		////////  4
		if(ch=='4')
		{
			ch=0;
                        DELAY_MS(10);  
	
		g++;
		}
		if(g==1)
		{
		mg[12]=fre2;
			g++;
		}
		if(g==3)
		{
		mg[13]=fre2;
			pd[6]=(mg[12]+mg[13])/2;
                        printf("t6.txt=\"yes\"");
                uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
                uart_putchar   (UART4 , 0xff); 
                uart_putchar   (UART4 , 0xff); 
			
			g=0;
		}
		
		/////////  5
		if(ch=='5')
		{
			ch=0;
                        DELAY_MS(10);  

		h++;
		}
		if(h==1)
		{
		mg[14]=fre2;
			h++;
		}
		if(h==3)
		{
		mg[15]=fre2;
		pd[7]=(mg[14]+mg[15])/2;
                printf("t7.txt=\"yes\"");
                uart_putchar   (UART4 , 0xff);                    //·¢ËÍ×Ö·û´®
                uart_putchar   (UART4 , 0xff); 
                uart_putchar   (UART4 , 0xff); 	
		h=0;
		}
		
	}
			
	



void uart4_handler(void)
{
   
    
    
    
    if(uart_query    (UART4) == 1)               //²éÑ¯ÊÇ·ñ½ÓÊÕµ½×Ö·û´®
    {
       uart_getchar   (UART4, &ch);                    //ÎÞÏÞµÈ´ý½ÓÊÜ1¸ö×Ö½Ú
       // uart_putchar   (UART4 , ch);                    //·¢ËÍ×Ö·û´®
       fivemsec_flag = 1;

       
       
     //PORTE_ISFR  = ~0;                                   //ÇåÖÐ¶Ï±êÖ¾Î»
     PORTD_ISFR  = ~0; 
     //PORTC_ISFR  = ~0; 
     //PORTA_ISFR  = ~0; 
     //PORTB_ISFR  = ~0; 
      
    }
     
    
}

void pingjun()
{
  int a2;
  
  for(a2=0;a2<6;a2++)
  {
       date7[a2]=fre2;           
       //DelayMS(3000);
  } 
   date7[6]=0;
   for(a2=0;a2<6;a2++)  
   date7[6]+=date7[a2];
   date7[6]=date7[6]/6;   
}




