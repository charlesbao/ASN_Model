#include "DAC8563.h"
#include "delay.h"
//#include "intrins.h"

void DAC8563_GPIO_Init(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	CLR1_L;
	LDAC1_H;
	CLR2_L;
	LDAC2_H;
}

void DAC8563_Init(void)
{
	DAC8563_Write1(CMD_RESET_ALL_REG, DATA_RESET_ALL_REG);
	DAC8563_Write1(CMD_PWR_UP_A_B, DATA_PWR_UP_A_B);
	DAC8563_Write1(CMD_INTERNAL_REF_EN, DATA_INTERNAL_REF_EN);
	DAC8563_Write1(CMD_GAIN, DATA_GAIN_B2_A2);
	
	DAC8563_Write2(CMD_RESET_ALL_REG, DATA_RESET_ALL_REG);
	DAC8563_Write2(CMD_PWR_UP_A_B, DATA_PWR_UP_A_B);
	DAC8563_Write2(CMD_INTERNAL_REF_EN, DATA_INTERNAL_REF_EN);
	DAC8563_Write2(CMD_GAIN, DATA_GAIN_B2_A2);
}

void DAC8563_Write1(unsigned char cmd,unsigned int data)
{
	uint8_t s=0;
	
	SYNC1_H;
//	delay_us(4);
//	__nop();
	__nop();
	SYNC1_L;
	
	SCLK1_L;
	for(s=0;s<8;s++)
	{
		if((cmd&0x80)==0x80)
			DIN1_H;
		else
			DIN1_L;
//		delay_us(4);
//		__nop();
	  __nop();
		SCLK1_H;
//		delay_us(4);
//	__nop();
	__nop();
		cmd<<=1;
		SCLK1_L;
//		delay_us(4);
		__nop();
//	__nop();
	}
	for(s=0;s<16;s++)
	{
		if((data&0x8000)==0x8000)
			DIN1_H;
		else
			DIN1_L;
//		delay_us(4);
//	__nop();
	__nop();
		SCLK1_H;
//		delay_us(4);
//	__nop();
	__nop();
		data<<=1;
		SCLK1_L;
//		delay_us(4);
//	__nop();
	__nop();	
	}
}

void DAC8563_Write2(unsigned char cmd,unsigned int data)
{
	uint8_t s=0;
	
	SYNC2_H;
//	delay_us(4);
//	__nop();
	__nop();
	SYNC2_L;
	
	SCLK2_L;
	for(s=0;s<8;s++)
	{
		if((cmd&0x80)==0x80)
			DIN2_H;
		else
			DIN2_L;
//		delay_us(4);
	__nop();
//	__nop();		
		SCLK2_H;
//		delay_us(4);
//	__nop();
	__nop();
		cmd<<=1;
		SCLK2_L;
//		delay_us(4);
//	__nop();
	__nop();	
	}
	for(s=0;s<16;s++)
	{
		if((data&0x8000)==0x8000)
			DIN2_H;
		else
			DIN2_L;
//		delay_us(4);
//	__nop();
	__nop();
		SCLK2_H;
//		delay_us(4);
//	__nop();
	__nop();
		data<<=1;
		SCLK2_L;
//		delay_us(4);
//	__nop();
	__nop();	
	}
}

void DAC8563_Out1(unsigned int data_a, unsigned int data_b)
{
	DAC8563_Write1(CMD_SETA_UPDATEA, data_a);	
	DAC8563_Write1(CMD_SETB_UPDATEB, data_b);		
	LDAC1_L;
//	delay_us(4);
//	__nop();
	__nop();
	LDAC1_H;
}

void DAC8563_Out2(unsigned int data_a, unsigned int data_b)
{
	DAC8563_Write2(CMD_SETA_UPDATEA, data_a);	
	DAC8563_Write2(CMD_SETB_UPDATEB, data_b);		
	LDAC2_L;
//	delay_us(4);
//	__nop();
	__nop();
	LDAC2_H;
}
