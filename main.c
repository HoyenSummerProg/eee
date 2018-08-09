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
    NVIC_Configuration();//���_����t�m
    GPIO_Configuration();//�}��t�m
    USART_Configuration();//UART�t�m
    USART_ITConfig(EVAL_COM1, USART_IT_RXNE, ENABLE);

		//�ҥ�USART2���_;���_���ͮɡA�����H�s��������
}

void GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure); 
  //�}��8����X-LED
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	//�}��9����X-LED
	
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	//�}��6����X
	
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_7;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	//�}��7����X
	
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	//�}��10����X
	
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	//�}��11����X
  
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//	GPIO_InitStructure.GPIO_OType  = GPIO_OType_PP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(GPIOA, &GPIO_InitStructure);
//  //�t�m�}��14��PP(TX)
//  
//  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
//	GPIO_InitStructure.GPIO_OType  = GPIO_OType_OD;
//  GPIO_Init(GPIOA, &GPIO_InitStructure);
//	//�t�m�}��15(RX)
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

