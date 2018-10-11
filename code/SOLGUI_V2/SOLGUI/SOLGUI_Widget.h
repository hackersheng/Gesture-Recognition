#ifndef SOLGUI_WIDGET_H


//##################################【mode宏定义】########################################

//------------【SPIN控件】
#define INT8	0x00
#define UINT8	0x01	
#define INT16	0x02	
#define INT32	0x03	
#define FLT16	0x04	
#define FLT32	0x05			


//------------【BAR控件】
//mode[0]  生长方向
#define DIREC_X		0x00	//x方向生长
#define DIREC_Y		0x01	//y方向生长
//mode[2:1]	外观类型		 
#define PROGBAR 	0x00	//进度条
#define SCALEBAR 	0x02	//刻度

//------------【PICTURE控件】
#define NML			0x00	//正常无附加
#define FRM			0x40	//mode[6]:边框开关
#define REV			0x80	//mode[7]:反白开关


//####################################【结构体定义】##########################################
//------------【光标结构体】
typedef struct _CURSOR{
	uint8_t cursor_rel_offset;	//光标相对视口的偏移
	uint8_t viewport_offset;		//视口的偏移
	uint8_t row_start;			//选项起始行（光标运动上界）
	uint8_t viewport_width;		//视口宽度
	uint32_t y_t;				//边界上坐标
	uint32_t	y_b;				//边界下坐标
}CURSOR;					//光标类


//------------【EDIT控件】

typedef struct _IME_CLUSTER{ 
			uint8_t 	finger;		//字符簇当前指向储存
	const 	uint8_t 	*name;		//字符簇名
	const 	uint8_t 	size;		//该字符簇容量
	const 	uint8_t	*table;		//字符簇本体
}IME_CLUSTER;				//字符簇结构体

#define SOL_ASCII_IME_SIZE 5

typedef struct _EDIT_IME{
			uint8_t 	finger;		//字符集当前指向储存 
	const 	uint8_t 	size;	 	//字符集容量
	IME_CLUSTER *cluster[SOL_ASCII_IME_SIZE];	//字符集本体
}EDIT_IME;					//输入法字符集结构体


//------------【Oscillogram控件】
typedef struct _WaveMemBlk{
	uint16_t size;				//储存点数（数组大小）
	int32_t	*mem; 				//存放点数组的内存地址
}WaveMemBlk;				//波形数据储存块

/*
空间申请范例:
	int32_t test_mem[128];						
	WaveMemBlk _wave_test1={128,test_mem};
	WaveMemBlk *wave_test1=&_wave_test1;

也可以用下面的宏来申请：__M_WMB_MALLOC(名,大小)
*/
//------------【自动化宏】
#define __M_WMB_MALLOC(name,size) 		\
int32_t _##name##_mem[size];				\
WaveMemBlk _##name={size,_##name##_mem};\
WaveMemBlk *##name=&_##name;

//####################################【API】##########################################
//---------------【光标】
void SOLGUI_Cursor(uint8_t rowBorder_Top,uint8_t rowBorder_Bottom,uint8_t option_num);				//光标（上边界行，下边界行，选项个数）

//---------------【选项式控件】
void SOLGUI_Widget_GotoPage(uint8_t USN,MENU_PAGE *page);								//页面跳转
void SOLGUI_Widget_Spin(uint8_t USN,const uint8_t *name,uint8_t type,double max,double min,void* value);	//数字旋钮
void SOLGUI_Widget_OptionText(uint8_t USN,const uint8_t* str,...);							//选项文本（太长的文字str会遮盖滚动条）
void SOLGUI_Widget_Button(uint8_t USN,const uint8_t *name,void (*func)(void));				//按键
void SOLGUI_Widget_Switch(uint8_t USN,const uint8_t *name,uint32_t *mem_value,uint8_t L_shift);			//变量开关（mem_value是一个外部申请的非易失性存储器变量）
void SOLGUI_Widget_Edit(uint8_t USN,const uint8_t *name,uint16_t char_num,uint8_t *buf);				//文本编辑器（char_num可修改长度）

//---------------【自由式控件】
void SOLGUI_Widget_Text(uint32_t x0,uint32_t y0,uint8_t mode,const uint8_t* str,...);			//文字（在该层应尽量避免调用printf）
void SOLGUI_Widget_Bar(uint32_t x0,uint32_t y0,uint32_t xsize,uint32_t ysize,int32_t max,int32_t min,int32_t value,uint8_t mode);		//条
void SOLGUI_Widget_Spectrum(uint32_t x0,uint32_t y0,uint32_t xsize,uint32_t ysize,int32_t max,int32_t min,uint16_t val_num,int32_t value[]);	//谱
void SOLGUI_Widget_Oscillogram(uint32_t x0,uint32_t y0,uint32_t xsize,uint32_t ysize,int32_t max,int32_t min,WaveMemBlk *wmb);  //波显示，要通过波探针输入数据更新
void SOLGUI_Widget_Picture(uint32_t x0,uint32_t y0,uint32_t xsize,uint32_t ysize,const uint8_t *pic,uint32_t x_len,uint32_t y_len,uint8_t mode); //图片	

//---------------【附件】
void SOLGUI_Oscillogram_Probe(WaveMemBlk *wmb,int32_t value);											//波探针

#endif
