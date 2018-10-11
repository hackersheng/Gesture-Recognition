#ifndef SOLGUI_INCLUDE_H
#define SOLGUI_INCLUDE_H

//#########################【SOLGUI版本信息】############################
#define SOLGUI_VERSION "2.0"

//##########################【SOLGUI源文件】############################
//-----------【移植设置】
#include"SOLGUI_Type.h"
#include"SOLGUI_Config.h"

//-----------【中间层】
#include"SOLGUI_Common.h"
#include"SOLGUI_Printf.h"
#include"SOLGUI_GBasic.h"
#include"SOLGUI_Picture.h"
//-----------【应用层】
#include"SOLGUI_Menu.h"
#include"SOLGUI_Widget.h"

/*##########################【使用说明】##########################
【1】字符串的格式化输出:
SOLGUI_printf(21,26,F8X10,"helloworld!");

此处的SOLGUI_printf功能是PC上printf的一个子集
因此格式用法和PC的prinf一样：

0x01:格式符：
	%s,%S:字符串
	%c,%C:单个字符

	%f,%F:double浮点数（每个格式化字符串只能带有一个，默认留3位小数）

	%b,%B:整型二进制
	%o,%O:整型八进制
	%d,%D:整型十进制（可有正负）
	%u,%U:整型十进制（可有正负）
	%x,%X:整型十六进制

0x02:参数（只有这三种）
	%07d：补零（数字最小显示长读7格，不足则用0在前面补齐）
	%-7d：左对齐（数字最小显示长度7格，不足则用空格在后面补齐）
	%.4f: 保留小数位数（保留4位小数，最多保留7位）

【2】页面框架部署:

	SOLGUI_Init(&index);			//初始化

	while(1)
	{
		kv=pixelC_HW_Key_GetValue();	//键值获取
		SOLGUI_InputKey(kv);			//键值输入
		SOLGUI_Menu_PageStage();	 	//前台
		SOLGUI_Refresh();				//更新屏幕
	}


【3】页面创建:
MENU_PAGE index;						//页面声明
 __M_PAGE(index,"test",PAGE_NULL,{		//宏方式创建页面
	////////////////////////////
});

【3】添加控件:
//---------------【页面控制】
SOLGUI_Cursor(uint8_t rowBorder_Top,uint8_t rowBorder_Bottom,uint8_t option_num);					//光标（上边界行，下边界行，选项个数）
//---------------【选项式控件】
SOLGUI_Widget_GotoPage(uint8_t USN,MENU_PAGE *page);										//页面跳转
SOLGUI_Widget_Spin(uint8_t USN,const uint8_t *name,uint8_t type,double max,double min,void* value);//数字旋钮
SOLGUI_Widget_OptionText(uint8_t USN,const uint8_t* str,...);									//选项文本（太长的文字str会遮盖滚动条）
SOLGUI_Widget_Button(uint8_t USN,const uint8_t *name,void (*func)(void));						//按键
SOLGUI_Widget_Switch(uint8_t USN,const uint8_t *name,uint32_t *mem_value,uint8_t L_shift);				//变量开关（mem_value是一个外部申请的非易失性存储器变量）
SOLGUI_Widget_Edit(uint8_t USN,const uint8_t *name,u16 char_num,uint8_t *buf);						//文本编辑器（char_num可修改长度）
//---------------【自由式控件】
SOLGUI_Widget_Text(uint32_t x0,uint32_t y0,uint8_t mode,const uint8_t* str,...);										//文字（在该层应尽量避免调用printf）
SOLGUI_Widget_Bar(uint32_t x0,uint32_t y0,uint32_t xsize,uint32_t ysize,int32_t max,int32_t min,int32_t value,uint8_t mode);				//条
SOLGUI_Widget_Spectrum(uint32_t x0,uint32_t y0,uint32_t xsize,uint32_t ysize,int32_t max,int32_t min,u16 val_num,int32_t value[]);	//谱
SOLGUI_Widget_Oscillogram(uint32_t x0,uint32_t y0,uint32_t xsize,uint32_t ysize,int32_t max,int32_t min,WaveMemBlk *wmb);  		//波显示，要通过波探针输入数据更新
SOLGUI_Widget_Picture(uint32_t x0,uint32_t y0,uint32_t xsize,uint32_t ysize,const uint8_t *pic,uint32_t x_len,uint32_t y_len,uint8_t mode); //图片	
//---------------【附件】
SOLGUI_Oscillogram_Probe(WaveMemBlk *wmb,int32_t value);												//波探针





-------------------------------------------------------------------*/

#endif
