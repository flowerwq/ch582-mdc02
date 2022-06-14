
#include <onewire.h>
#include "CH58x_common.h"

/*********************************************************************
 * @fn      main
 *
 * @brief   主函数
 *
 * @return  none
 */
int main()
{
	volatile int j,i=0;
//	unsigned char b[3];
//	unsigned char a[5];
//	uint8_t flag=0;
	float Cmin=0, Cmax=30;
    SetSysClock(CLK_SOURCE_PLL_60MHz);

    /* 配置串口1：先配置IO口模式，再配置串口 */
    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);      // RXD-配置上拉输入
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA); // TXD-配置推挽输出，注意先让IO口输出高电平
    UART1_DefInit();

	slave_init();
	
	onewire_find_alldevice();
	//	onewire_finddevic_fun();
//	mdc02_channel(CAP_CH1CH2_SEL);
//	dev_type_choose_function();
	while(1){
	    dev_type_choose_function();
//		read_cap();
		DelayMs(1000);
		__nop();
	}
}



