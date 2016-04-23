/**
********************************************************

  ******************************************************************************
  */
  
#include "bsp_gpio.h"   

 /**
  * @brief  初始化GPIO
  * @param  无
  * @retval 无
  */
  
void LED_GPIO_Config(void)
{		
    GPIO_InitTypeDef GPIO_InitStructure;/*定义一个GPIO_InitTypeDef类型的结构体*/

    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE ); /*开启GPIOA的外设时钟*/
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOD, ENABLE ); /*开启GPIOD的外设时钟*/
													   
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;/*选择要控制的GPIO引脚*/	
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;/*设置引脚模式为通用推挽输出*/   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; /*设置引脚速率为50MHz */  
    GPIO_Init( GPIOA, &GPIO_InitStructure );/*调用库函数，初始化GPIO*/

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    
    GPIO_ResetBits(GPIOA, GPIO_Pin_8);
    GPIO_ResetBits(GPIOD, GPIO_Pin_2);
}





void GPIO_Config( void )
{		
    /*定义一个GPIO_InitTypeDef类型的结构体*/
    GPIO_InitTypeDef GPIO_InitStructure;


    /*开启GPIOA的外设时钟*/
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE ); 

    /* 配置WiFi模块的片选（CH）引脚	复位重启（RST）引脚*/
    /*选择要控制的GPIOA0（CH）引脚和GPIOA1（RST）引脚*/															   
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;	

    /*设置引脚模式为通用推挽输出*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

    /*设置引脚速率为50MHz */   
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

    /*调用库函数，初始化GPIOA*/
    GPIO_Init( GPIOA, &GPIO_InitStructure );	 


    /*	*/
    GPIO_ResetBits( GPIOA, GPIO_Pin_1 );// 拉低WiFi模块的复位重启引脚	
    
    /* DC <--> PB0   RST <--> PB10 */
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_10 ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
}
/*********************************************END OF FILE**********************/
