#ifndef _CHINESE_H_
#define _CHINESE_H_

struct china                  // ������ģ���ݽṹ 
{
	unsigned char  Index[2];            // ������������,һ������ռ�����ֽ�	
	unsigned char  Msk[32];             // ����������(16*16��32������) 
};
//���룬���� ˳��
struct china table[]=
{
"��",0x00,0x88,0x20,0x88,0x20,0x91,0x20,0xA1,0xFF,0xC9,0x2A,0x89,0x2A,0x89,0x2A,0xBF,0x2A,0x89,0x2A,0x89,0xFF,0xC9,0x20,0xA1,0x20,0x91,0x20,0x88,0x00,0x88,0x00,0x00,/*"?",0*/

"��",0x02,0x00,0x02,0x00,0x42,0x00,0x42,0x00,0x42,0x00,0x42,0x02,0x42,0x01,0x7F,0xFE,0x42,0x00,0x42,0x00,0x42,0x00,0x42,0x00,0x42,0x00,0x02,0x00,0x02,0x00,0x00,0x00,/*"?",1*/

"ʵ",0x08,0x20,0x30,0x21,0x20,0x21,0x21,0x22,0x28,0xE2,0x26,0x24,0xA0,0x28,0x60,0x30,0x2F,0xE0,0x20,0x30,0x20,0x28,0x20,0x24,0x20,0x22,0x28,0x21,0x30,0x20,0x00,0x00,/*"?",2*/

"ʱ",0x00,0x00,0x3F,0xFC,0x21,0x08,0x21,0x08,0x21,0x08,0x3F,0xFC,0x00,0x00,0x08,0x00,0x08,0x80,0x08,0x60,0x08,0x02,0x08,0x01,0xFF,0xFE,0x08,0x00,0x08,0x00,0x00,0x00,/*"?",3*/

"��",0x04,0x80,0x08,0x80,0x34,0x80,0xE7,0xFE,0x24,0x84,0x24,0x88,0x00,0x00,0x0F,0xE0,0x08,0x40,0x08,0x40,0xFF,0xFF,0x08,0x40,0x08,0x40,0x0F,0xE0,0x00,0x00,0x00,0x00,/*"?",4*/

"��",0x02,0x00,0x02,0x00,0x42,0x00,0x33,0xFC,0x00,0x09,0x02,0x11,0x05,0x02,0x79,0xC2,0x41,0x34,0x41,0x08,0x41,0x14,0x79,0x62,0x05,0x82,0x04,0x01,0x04,0x01,0x00,0x00,/*"?",5*/

"��",0x02,0x00,0x02,0x00,0x42,0x00,0x33,0xFE,0x00,0x04,0x02,0x08,0x02,0x00,0x02,0x00,0x02,0x00,0xFF,0xFF,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x00,0x00,/*"?",6*/

"��",0x01,0x00,0x09,0x01,0x31,0x01,0x21,0x21,0x21,0x62,0x21,0x92,0xAF,0x14,0x61,0x08,0x21,0x08,0x21,0x34,0x21,0xC4,0x21,0x02,0x29,0x01,0x31,0x00,0x01,0x00,0x00,0x00,//?0

"��",0x22,0x00,0x2A,0xFF,0x2A,0xA8,0xFE,0xAA,0x2A,0xA9,0x2A,0xFE,0x22,0x00,0x04,0x90,0x14,0x92,0xE4,0x91,0x27,0xFE,0x2C,0x90,0x34,0x90,0x07,0xF8,0x00,0x80,0x00,0x00,//?1

"��",0x00,0x00,0x1F,0xFE,0x30,0x84,0xD0,0x84,0x10,0x84,0x10,0x84,0x1F,0xFE,0x02,0x00,0x0C,0x00,0xF1,0x00,0x10,0xC2,0x10,0x01,0x10,0x02,0x1F,0xFC,0x00,0x00,0x00,0x00,//?8

"��",0x00,0x00,0x00,0x22,0x00,0x42,0x7D,0x92,0x54,0x92,0x54,0x92,0x54,0x92,0x57,0xFE,0x54,0x92,0x54,0x92,0x54,0x92,0x7C,0x92,0x00,0x82,0x00,0x02,0x00,0x00,0x00,0x00,/*"?",3*/

"��",0x00,0x11,0x20,0x12,0xFF,0xF4,0x24,0x90,0x24,0x90,0x24,0x98,0xFF,0xF5,0x20,0x12,0x00,0x0C,0x7F,0xF0,0x44,0x40,0x44,0x42,0x44,0x41,0x7F,0xFE,0x00,0x00,0x00,0x00,/*"?",4*/

"��",0x01,0x00,0x02,0x01,0x04,0x02,0x09,0x04,0x11,0x18,0x61,0xE0,0x01,0x00,0x01,0x02,0x01,0x01,0xC1,0x02,0x31,0xFC,0x08,0x00,0x04,0x00,0x02,0x00,0x01,0x00,0x00,0x00,/*"?",5*/

"��",0x24,0x10,0x24,0x60,0x25,0x80,0x7F,0xFF,0xC4,0x80,0x44,0x60,0x00,0x81,0x03,0x01,0x1C,0x02,0x00,0x02,0xFF,0xE4,0x00,0x08,0x10,0x30,0x08,0xC0,0x06,0x00,0x00,0x00,/*"?",6*/

"��",0x00,0x00,0x1F,0xFF,0x80,0x00,0x44,0x00,0x04,0xF8,0x44,0x80,0x54,0x80,0x4F,0xFE,0x44,0x90,0x44,0x88,0x44,0xF0,0x44,0x02,0x40,0x01,0x7F,0xFE,0x00,0x00,0x00,0x00,/*"?",7*/

"��",0x10,0x08,0x10,0x0C,0x10,0x08,0x1F,0xF8,0x10,0x10,0x10,0x11,0x10,0x12,0x08,0x0C,0x08,0x70,0xFF,0x80,0x08,0x02,0x08,0x01,0x08,0x02,0x0F,0xFC,0x00,0x00,0x00,0x00,/*"?",8*/

"��",0x10,0x00,0x33,0xFF,0x52,0x48,0x92,0x48,0x12,0x4A,0x52,0x49,0x33,0xFE,0x18,0x00,0x00,0x00,0xFE,0x7E,0x11,0x11,0x11,0x11,0x21,0x21,0x41,0x41,0x07,0x07,0x00,0x00,/*"?",9*/

"��",0x02,0x80,0x0C,0x80,0xF7,0xFE,0x24,0x84,0x24,0x8A,0x01,0x64,0x27,0x18,0x39,0xE4,0x08,0x22,0x2A,0xA2,0x2A,0xA2,0xFF,0xFA,0x2A,0xA2,0x3E,0xA2,0x08,0x22,0x00,0x00,/*"?",10*/

"˵",0x02,0x00,0x02,0x00,0x42,0x00,0x33,0xFC,0x00,0x09,0x00,0x12,0x8F,0x84,0x68,0x98,0x08,0xE0,0x08,0x80,0x18,0xFC,0x28,0x82,0xCF,0x82,0x00,0x02,0x00,0x0E,0x00,0x00,/*"?",11*/

"��",0x00,0x00,0x3F,0xF0,0x22,0x20,0x22,0x20,0x22,0x20,0x3F,0xF1,0x00,0x02,0x00,0x0C,0x7F,0xF0,0x44,0x40,0x44,0x40,0x44,0x42,0x44,0x41,0x7F,0xFE,0x00,0x00,0x00,0x00,/*"?",12*/

"ѡ",0x02,0x00,0x02,0x02,0x42,0x04,0x33,0xF8,0x00,0x04,0x0A,0x0A,0x72,0x32,0x13,0xC2,0x12,0x02,0xFE,0x02,0x13,0xF2,0x12,0x0A,0x12,0x0A,0x02,0x3A,0x00,0x02,0x00,0x00,/*"?",13*/

"��",0x08,0x42,0x08,0x41,0xFF,0xFE,0x08,0x80,0x00,0x00,0x41,0x08,0x61,0x48,0x52,0x48,0x4A,0x48,0x45,0xFF,0x4A,0x48,0x52,0x48,0x61,0x48,0x01,0x08,0x01,0x00,0x00,0x00,/*"?",14*/

"ֵ",0x00,0x80,0x01,0x00,0x06,0x00,0x1F,0xFF,0xE0,0x02,0x20,0x02,0x27,0xFE,0x25,0x52,0x25,0x52,0xFD,0x52,0x25,0x52,0x25,0x52,0x27,0xFE,0x20,0x02,0x00,0x02,0x00,0x00,/*"?",15*/

"��",0x04,0x08,0x04,0x0C,0xFF,0xF8,0x04,0x10,0x04,0x10,0x1F,0x80,0x90,0xBF,0x54,0xAA,0x12,0xAA,0x1F,0xAA,0x12,0xAA,0x54,0xAA,0x90,0xBF,0x1F,0x80,0x00,0x00,0x00,0x00,/*"?",16*/

"��",0x00,0x40,0x40,0x40,0x30,0xFE,0x03,0x01,0x00,0x02,0x1F,0xFC,0x10,0x00,0x12,0x78,0x12,0x49,0x12,0x7A,0x10,0x04,0xFF,0xE8,0x10,0x1C,0x90,0x62,0x51,0x8F,0x00,0x00,/*"?",17*/

"��",0x08,0x01,0x08,0x02,0x08,0x0C,0xFF,0xF0,0x08,0x02,0x08,0x01,0x0F,0xFE,0x00,0x00,0x00,0x00,0x1F,0xFE,0x10,0x04,0x10,0x04,0x10,0x04,0x1F,0xFE,0x00,0x00,0x00,0x00,/*"?",0*/

"һ",0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x00,0x00,/*"?",18*/

"��",0x00,0x08,0x00,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x00,0x08,0x00,0x08,0x00,0x00,/*"?",19*/

"��",0x00,0x04,0x20,0x04,0x21,0x04,0x21,0x04,0x21,0x04,0x21,0x04,0x21,0x04,0x21,0x04,0x21,0x04,0x21,0x04,0x21,0x04,0x21,0x04,0x21,0x04,0x20,0x04,0x00,0x04,0x00,0x00,/*"?",20*/

"��",0x00,0x00,0x3F,0xFE,0x20,0x14,0x20,0x24,0x20,0xC4,0x3F,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x3F,0x84,0x20,0x44,0x20,0x44,0x20,0x44,0x3F,0xFE,0x00,0x00,0x00,0x00,/*"?",21*/

"��",0x00,0x02,0x40,0x02,0x42,0x02,0x42,0x02,0x42,0x1E,0x43,0xE2,0x7E,0x02,0x42,0x02,0x42,0x02,0x42,0x02,0x42,0x02,0x43,0xFE,0x40,0x02,0x40,0x02,0x00,0x02,0x00,0x00,

"��",0x04,0x00,0x04,0x02,0x04,0x04,0x04,0x08,0x04,0x30,0x04,0xC0,0x84,0x00,0x44,0x00,0x34,0x00,0x04,0x80,0x04,0x40,0x04,0x20,0x04,0x18,0x04,0x06,0x04,0x00,0x00,0x00,

"��",0x09,0x41,0x4A,0x59,0x2C,0x6A,0x08,0xC6,0xFF,0x44,0x08,0x4A,0x2C,0x71,0x4A,0x00,0x01,0x01,0x0E,0x02,0xF1,0xCC,0x10,0x30,0x10,0xCC,0x1F,0x02,0x10,0x01,0x00,0x00,

"��",0x00,0x20,0x04,0x20,0x18,0x20,0xE3,0xE0,0x22,0x20,0x22,0x20,0x22,0x20,0x22,0x20,0x3F,0xFF,0x22,0x20,0x22,0x20,0x22,0x20,0x22,0x20,0x20,0x20,0x00,0x20,0x00,0x00,

"��",0x00,0x01,0x00,0x02,0x00,0x0C,0x7F,0xF0,0x44,0x40,0x44,0x40,0x44,0x40,0x44,0x40,0x44,0x40,0x44,0x40,0x44,0x42,0x44,0x41,0x7F,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,

"��",0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,0x41,0x02,0x41,0x02,0x41,0x02,0x41,0x02,0x41,0x02,0x41,0x02,0x41,0x02,0x7F,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

"ս",0x00,0x00,0x00,0xFE,0x00,0x84,0xFF,0x84,0x10,0x84,0x10,0x84,0x10,0xFE,0x02,0x01,0x02,0x02,0x02,0x04,0xFF,0xE8,0x04,0x18,0x44,0x64,0x35,0x82,0x04,0x0F,0x00,0x00,

"��",0x01,0x01,0x3F,0xFE,0x69,0x40,0xA7,0x32,0x21,0x01,0x3F,0xFE,0x00,0x01,0x7F,0xC2,0x40,0x0C,0x40,0x70,0x4F,0x80,0x40,0x7E,0x40,0x01,0x7F,0xC1,0x00,0x07,0x00,0x00,

"��",0x02,0x40,0x3C,0x60,0x08,0x40,0xFF,0xFF,0x08,0x80,0x08,0x80,0x04,0x20,0x08,0x42,0xF1,0x84,0x1E,0x18,0x10,0x62,0x1F,0x81,0x10,0x02,0x1F,0xFC,0x00,0x00,0x00,0x00,

"��",0x20,0x04,0x21,0x06,0x21,0x04,0x3F,0xF8,0x21,0x08,0x21,0x08,0x00,0x02,0x7F,0x22,0x49,0x22,0x49,0x22,0x7F,0xFE,0x49,0x22,0x49,0x22,0x7F,0x22,0x00,0x02,0x00,0x00,

};

#endif