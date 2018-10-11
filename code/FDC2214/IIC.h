#ifndef _IIC_H
#define _IIC_H

#include "common.h"
#include "include.h"

//IO方向设置
#define SDA_IN()   {gpio_ddr(PTD9, GPI);} //PTB2输入模式
#define SDA_OUT()  {gpio_ddr(PTD9, GPO);} //PTB2输出模式
//IO操作
#define IIC_SCL(n)  gpio_set(PTD8,  n) //PTB3
#define IIC_SDA(n)  gpio_set(PTD9, n) //PTB2
#define READ_SDA    gpio_get(PTD9)  //输入SDA

//IIC所有操作函数
void IIC_Init(void);                //初始化IIC的IO口				 
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(uint8 txd);			//IIC发送一个字节
uint8 IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
uint8 IIC_Wait_Ack(void); 				//IIC等待ACK信号
void IIC_Ack(void);					//IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号

void IIC_Write_One_Byte(uint8 daddr,uint8 addr,uint8 data);
uint8 IIC_Read_One_Byte(uint8 daddr,uint8 addr);	 
#endif

