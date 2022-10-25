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


#define CMD_SETA_UPDATEA	0x18	// 写入DAC-A输入寄存器并更新DAC-A +16位数据
#define CMD_SETB_UPDATEB	0x19	// 写入DAC-B输入寄存器并更新DAC-B +16位数据
#define CMD_UPDATE_ALL_DACS	0x0F	// 更新所有DAC, 后16位只需时钟即可

#define CMD_RESET_ALL_REG	0x28	// Software reset
#define DATA_RESET_ALL_REG	0x0001	// 复位所有寄存器并更新所有DAC
#define DATA_RESET_DAC_REG	0x0000	// 复位DAC-A和DAC-B输入寄存器并更新所有DAC

#define CMD_PWR_UP_A_B		0x20	// 设置DAC上电或掉电模式
#define DATA_PWR_UP_A		0x0001	// 上电DAC-A 
#define DATA_PWR_UP_B		0x0002	// 上电DAC-B
#define DATA_PWR_UP_A_B		0x0003	// 上电DAC-A和DAC-B
#define DATA_PWR_DOWN1_A	0x0041	// 关断DAC-A; 1kΩ至GND
#define DATA_PWR_DOWN1_B	0x0042	// 关断DAC-B; 1kΩ至GND
#define DATA_PWR_DOWN1_A_B	0x0043	// 关断DAC-A和DAC-B; 1kΩ至GND
#define DATA_PWR_DOWN2_A	0x0081	// 关断DAC-A; 100kΩ至GND
#define DATA_PWR_DOWN2_B	0x0082	// 关断DAC-B; 100kΩ至GND
#define DATA_PWR_DOWN2_A_B	0x0083	// 关断DAC-A和DAC-B; 100kΩ至GND
#define DATA_PWR_DOWN3_A	0x00C1	// 关断DAC-A; 高阻
#define DATA_PWR_DOWN3_B	0x00C2	// 关断DAC-B; 高阻
#define DATA_PWR_DOWN3_A_B	0x00C3	// 关断DAC-A和DAC-B;高阻

#define CMD_INTERNAL_REF_DIS	0x38	// Disable internal reference and reset DACs to gain = 1
#define CMD_INTERNAL_REF_EN		0x38	// Enable internal reference and reset DACs to gain = 2
#define DATA_INTERNAL_REF_DIS	0x0000	// 禁用内部参考和复位DAC以获得增益 = 1
#define DATA_INTERNAL_REF_EN	0x0001	// 启用内部参考和复位DAC以获得增益 = 2

#define CMD_GAIN			0x02	// default with internal Vref
#define DATA_GAIN_B2_A2		0x00	// 增益：DAC-B增益= 2, DAC-A增益= 2
#define DATA_GAIN_B2_A1		0x01	// 增益：DAC-B增益= 2, DAC-A增益= 1
#define DATA_GAIN_B1_A2		0x02	// 增益：DAC-B增益= 1, DAC-A增益= 2
#define DATA_GAIN_B1_A1		0x03	// 增益：DAC-B增益= 1, DAC-A增益= 1

#define CMD_LDAC_DIS	0x30	// 设置LDAC寄存器
#define DATA_LDAC_AB	0x0000	// LDAC引脚有效于DAC-B和DAC-A
#define DATA_LDAC_B		0x0001	// LDAC引脚有效于DAC-B; 无效于DAC-A
#define DATA_LDAC_A		0x0002	// LDAC引脚无效于DAC-B; 有效于DAC-A
#define DATA_LDAC_NAB	0x0003	// LDAC引脚无效于DAC-B和DAC-A


void DAC8563_GPIO_Init(void);
void DAC8563_Init(void);
void DAC8563_Write1(unsigned char cmd,unsigned int data);
void DAC8563_Write2(unsigned char cmd,unsigned int data);
void DAC8563_Out1(unsigned int data_a, unsigned int data_b);
void DAC8563_Out2(unsigned int data_a, unsigned int data_b);

#endif
