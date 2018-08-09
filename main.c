#include "main.h"



//#define car_run 0x0480
//#define car_back 0x0840
//#define car_stop 0x0000
//#define car_right 0x0440
//#define car_left 0x0880

int i;

void NVIC_Configuration(void);
void GPIO_Configuration(void);
void USART_Configuration(void);
void USART2_IRQHandler(void);
void usart_rxtx(void);
  
int main(void)
{
		usart_rxtx();
		//GPIOC->BSRR=led_both;
    while(1)
    {
    }
}
 
void usart_rxtx(void)
{
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA|RCC_AHBPeriph_GPIOC, ENABLE);
    NVIC_Configuration();//中斷控制配置
    GPIO_Configuration();//腳位配置
    USART_Configuration();//UART配置
    USART_ITConfig(EVAL_COM1, USART_IT_RXNE, ENABLE);

		//啟用USART2當中斷;中斷產生時，接收寄存器不為空
}

void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure); 
  //腳位8為輸出-LED
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	//腳位9為輸出-LED
	
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	//腳位6為輸出
	
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	//腳位7為輸出
	
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	//腳位10為輸出
	
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	//腳位11為輸出
  
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOA, &GPIO_InitStructure);
//  //配置腳位14為PP(TX)
//  
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//	GPIO_InitStructure.GPIO_OType  = GPIO_OType_OD;
//  GPIO_Init(GPIOA, &GPIO_InitStructure);
//	//配置腳位15(RX)
}
  
void USART_Configuration(void)
{
  USART_InitTypeDef USART_InitStructure;
  
  USART_InitStructure.USART_BaudRate = 9600;
	// Baud Rate
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  STM_EVAL_COMInit(COM1, &USART_InitStructure);
  USART_Init(USART2, &USART_InitStructure); 
  USART_Cmd(USART2, ENABLE);
	/* Enable USART2 */
}

void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;  
  NVIC_InitStructure.NVIC_IRQChannel = EVAL_COM1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

