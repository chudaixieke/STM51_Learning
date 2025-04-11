#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "Timer0.h"

unsigned char Sec = 55, Min = 59, Hour = 23;

void main()
{
    LCD_Init();
    Timer0Init();
    
    LCD_ShowString(1, 1, "Clock:");  // �ϵ���ʾ��̬�ַ���
    LCD_ShowString(2, 1, "  :  :");
    
    while (1)
    {
        LCD_ShowNum(2, 1, Hour, 2);  // ��ʾʱ����
        LCD_ShowNum(2, 4, Min, 2);
        LCD_ShowNum(2, 7, Sec, 2);
    }
}

void Timer0Init()
{
    TMOD = 0x01;  // ���ö�ʱ��ģʽ
    TL0 = 0x18;   // ���ö�ʱ��ֵ
    TH0 = 0xE0;   // ���ö�ʱ��ֵ
    ET0 = 1;      // ������ʱ�� 0 �ж�
    EA = 1;       // ����ȫ���ж�
}

void Timer0_Routine() interrupt 1
{
    static unsigned int T0Count;
    TL0 = 0x18;   // ���ö�ʱ��ֵ
    TH0 = 0xE0;   // ���ö�ʱ��ֵ
    T0Count++;
    if (T0Count >= 1000)  // ��ʱ����Ƶ��1s
    {
        T0Count = 0;
        Sec++;            // 1�뵽��Sec����
        if (Sec >= 60)
        {
            Sec = 0;      // 60�뵽��Sec��0��Min����
            Min++;
            if (Min >= 60)
            {
                Min = 0;  // 60���ӵ���Min��0��Hour����
                Hour++;
                if (Hour >= 24)
                {
                    Hour = 0;  // 24Сʱ����Hour��0
                }
            }
        }
    }
}