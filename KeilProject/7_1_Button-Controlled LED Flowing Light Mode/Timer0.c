#include <REGX52.H>
void Timer0_Init()
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时

	//TMOD=0x01;//0000 0001
	TMOD&=0xF0;//把TMOD的低四位清零，高四位保持不变
	TMOD|=0x01;//把TMOD的最低位置1，高四位保持不变
	TF0=0;
	TR0=1;
	ET0=1;
	EA=1;
	PT0=0;
}