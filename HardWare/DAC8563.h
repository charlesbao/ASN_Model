#ifndef __DAC8563_H_
#define __DAC8563_H_
#include "sys.h"

#define	DIN1	PAout(0)
#define LDAC1	PAout(1)
#define CLR1	PAout(2)
#define SYNC1	PAout(3)
#define SCLK1	PAout(4)
 
#define	DIN2	PDout(0)
#define LDAC2	PDout(1)
#define CLR2	PDout(2)
#define SYNC2	PDout(3)
#define SCLK2	PDout(4)

#define SCLK1_H	SCLK1 = 1
#define SYNC1_H	SYNC1 = 1
#define CLR1_H	CLR1  = 1
#define LDAC1_H	LDAC1 = 1
#define DIN1_H	DIN1  = 1

#define SCLK1_L	SCLK1 = 0
#define SYNC1_L	SYNC1 = 0
#define CLR1_L	CLR1  = 0
#define LDAC1_L	LDAC1 = 0
#define DIN1_L	DIN1  = 0

#define SCLK2_H	SCLK2 = 1
#define SYNC2_H	SYNC2 = 1
#define CLR2_H	CLR2  = 1
#define LDAC2_H	LDAC2 = 1
#define DIN2_H	DIN2  = 1

#define SCLK2_L	SCLK2 = 0
#define SYNC2_L	SYNC2 = 0
#define CLR2_L	CLR2  = 0
#define LDAC2_L	LDAC2 = 0
#define DIN2_L	DIN2  = 0


#define CMD_SETA_UPDATEA	0x18	// д��DAC-A����Ĵ���������DAC-A +16λ����
#define CMD_SETB_UPDATEB	0x19	// д��DAC-B����Ĵ���������DAC-B +16λ����
#define CMD_UPDATE_ALL_DACS	0x0F	// ��������DAC, ��16λֻ��ʱ�Ӽ���

#define CMD_RESET_ALL_REG	0x28	// Software reset
#define DATA_RESET_ALL_REG	0x0001	// ��λ���мĴ�������������DAC
#define DATA_RESET_DAC_REG	0x0000	// ��λDAC-A��DAC-B����Ĵ�������������DAC

#define CMD_PWR_UP_A_B		0x20	// ����DAC�ϵ�����ģʽ
#define DATA_PWR_UP_A		0x0001	// �ϵ�DAC-A 
#define DATA_PWR_UP_B		0x0002	// �ϵ�DAC-B
#define DATA_PWR_UP_A_B		0x0003	// �ϵ�DAC-A��DAC-B
#define DATA_PWR_DOWN1_A	0x0041	// �ض�DAC-A; 1k����GND
#define DATA_PWR_DOWN1_B	0x0042	// �ض�DAC-B; 1k����GND
#define DATA_PWR_DOWN1_A_B	0x0043	// �ض�DAC-A��DAC-B; 1k����GND
#define DATA_PWR_DOWN2_A	0x0081	// �ض�DAC-A; 100k����GND
#define DATA_PWR_DOWN2_B	0x0082	// �ض�DAC-B; 100k����GND
#define DATA_PWR_DOWN2_A_B	0x0083	// �ض�DAC-A��DAC-B; 100k����GND
#define DATA_PWR_DOWN3_A	0x00C1	// �ض�DAC-A; ����
#define DATA_PWR_DOWN3_B	0x00C2	// �ض�DAC-B; ����
#define DATA_PWR_DOWN3_A_B	0x00C3	// �ض�DAC-A��DAC-B;����

#define CMD_INTERNAL_REF_DIS	0x38	// Disable internal reference and reset DACs to gain = 1
#define CMD_INTERNAL_REF_EN		0x38	// Enable internal reference and reset DACs to gain = 2
#define DATA_INTERNAL_REF_DIS	0x0000	// �����ڲ��ο��͸�λDAC�Ի������ = 1
#define DATA_INTERNAL_REF_EN	0x0001	// �����ڲ��ο��͸�λDAC�Ի������ = 2

#define CMD_GAIN			0x02	// default with internal Vref
#define DATA_GAIN_B2_A2		0x00	// ���棺DAC-B����= 2, DAC-A����= 2
#define DATA_GAIN_B2_A1		0x01	// ���棺DAC-B����= 2, DAC-A����= 1
#define DATA_GAIN_B1_A2		0x02	// ���棺DAC-B����= 1, DAC-A����= 2
#define DATA_GAIN_B1_A1		0x03	// ���棺DAC-B����= 1, DAC-A����= 1

#define CMD_LDAC_DIS	0x30	// ����LDAC�Ĵ���
#define DATA_LDAC_AB	0x0000	// LDAC������Ч��DAC-B��DAC-A
#define DATA_LDAC_B		0x0001	// LDAC������Ч��DAC-B; ��Ч��DAC-A
#define DATA_LDAC_A		0x0002	// LDAC������Ч��DAC-B; ��Ч��DAC-A
#define DATA_LDAC_NAB	0x0003	// LDAC������Ч��DAC-B��DAC-A


void DAC8563_GPIO_Init(void);
void DAC8563_Init(void);
void DAC8563_Write1(unsigned char cmd,unsigned int data);
void DAC8563_Write2(unsigned char cmd,unsigned int data);
void DAC8563_Out1(unsigned int data_a, unsigned int data_b);
void DAC8563_Out2(unsigned int data_a, unsigned int data_b);

#endif
