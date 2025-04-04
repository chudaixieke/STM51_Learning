#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

int Result=0;
void main()
{
	LCD_Init();
	LCD_ShowNum(1,1,Result,3);
	while(1)
	{
		Result++;
		Delay(10);
		LCD_ShowNum(1,1,Result,3);
	}
}
