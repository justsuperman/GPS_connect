/******************串口1发送GPS控制信息，不要改了，要改复制出去测试。串口中断的波特率还是不知道怎么搞***********************************/
#include<12C5A60S2.h>
void GPS_init();
void Delay1000ms();
//#include<GPS_TEST_init.h>头文件一般都放一些串口定义

void UartInit(void)		//9600bps@11.0592MHz
{
	S2CON = 0x50;   //串口2工作在方式1  10位异步收发 S2REN=1允许接收
    BRT = 0xFD;	   //独立波特率发生器初值
    AUXR = 0x10;    //BRTR=1 独立波特率发生器开始计数，1T，一个机器周期的意思
	IE2 =0x01;	//开串口2中断  ES2=1
	EA = 1;                 //开总中断 ！！！这个一定要记住
}


void main()
{
	UartInit();
	Delay1000ms();
	GPS_init();
	GPS_init();
	GPS_init();//发三次，确保返回想要的值，防止有的数据被破坏了
	while(1)
	{
	  	
	}	   
}





