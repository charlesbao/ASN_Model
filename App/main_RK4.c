#include "sys.h"
#include "delay.h"
#include "math.h"
#include "DAC8563.h"
#define dim 2 
#define pi 3.1416

double *sys(double *y,double t)
{
	static double dy[dim];
  double B=2,g=2,c=1.4;

	
  dy[0]=-y[0]+B*sin(g*y[0])*B*sin(g*y[1])+sin(2*pi*t);
//	dy[1]=-c*y[1]+c*B*B*sin(g*y[0])*sin(g*y[0]);
	dy[1]=-c*y[1]+c*B*B*pow(sin(g*y[0]),2);	

	return dy;
}
//系统方程
double *matrix_mul(double n, double *x)
{
	static double mat_mul[dim];
	int i;

	for(i=0;i<dim;i++)
		mat_mul[i]=n*x[i];

	return mat_mul;
}
//定义了矩阵的乘法
double *matrix_sum(double *x, double *y)
{
	static double mat_sum[dim];
	int i;

	for(i=0;i<dim;i++)
		mat_sum[i]=x[i]+y[i];

	return mat_sum;
}
//定义了矩阵的加法
int main(void)
{
	unsigned long int i,num;
	double i_Time;
	double h=0.01,y0[dim],*k1,*k2,*k3,*k4,K1[dim],K2[dim],K3[dim],K4[dim];
	double x_last,y_last,x_now,y_now;
	unsigned int Out[2]={0};
	  
 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	
	DAC8563_GPIO_Init();
	DAC8563_Init();
	
				   i_Time=0;
	//
	while(1)
	{
		x_last=0.1;y_last=1;
		
		y0[0]=x_last;
		y0[1]=y_last;
		
 
		//系统初值
	for(num=0;num<3000000;num++)
		
//		while(1)
		{	

			//--------RK4--------//
			k1=sys(y0,i_Time);
			for(i=0;i<dim;i++) K1[i]=k1[i];
			k2=sys(matrix_sum(y0,matrix_mul(h/2,K1)),i_Time+h/2);
			for(i=0;i<dim;i++) K2[i]=k2[i];
			k3=sys(matrix_sum(y0,matrix_mul(h/2,K2)),i_Time+h/2);
			for(i=0;i<dim;i++) K3[i]=k3[i];
			k4=sys(matrix_sum(y0,matrix_mul(h,K3)),i_Time+h);
			for(i=0;i<dim;i++) K4[i]=k4[i];
	
//			k1=sys(y0,num*h);
//			for(i=0;i<dim;i++) K1[i]=k1[i];
//			k2=sys(matrix_sum(y0,matrix_mul(h/2,K1)),num*h);
//			for(i=0;i<dim;i++) K2[i]=k2[i];
//			k3=sys(matrix_sum(y0,matrix_mul(h/2,K2)),num*h);
//			for(i=0;i<dim;i++) K3[i]=k3[i];
//			k4=sys(matrix_sum(y0,matrix_mul(h,K3)),num*h);
//			for(i=0;i<dim;i++) K4[i]=k4[i];
			
			x_now=x_last+h*(K1[0]+2*K2[0]+2*K3[0]+K4[0])/6;
			y_now=y_last+h*(K1[1]+2*K2[1]+2*K3[1]+K4[1])/6;
			
			i_Time = i_Time + h;
		  
			//--------------------//算法
			
			Out[0]=(unsigned int)((x_now+10)*65535/20);
			//--------------------//P3duiying1hao 
			Out[1]=(unsigned int)((y_now+10)*65535/20);
			//DAC 模块输出范围（-10，10）如果超过需要缩放量程
			
			//--------------------//P3duiying1hao
			DAC8563_Out1(Out[1],Out[0]);
			x_last=x_now;
			y_last=y_now;
		 
			
			y0[0]=x_last;
			y0[1]=y_last;
		
			
        }
	}
}

