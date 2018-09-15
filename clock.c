#include <REGX51.H>
sbit s1=P3^0;
sbit s2=P3^1;
sbit s3=P3^2;
sbit s4=P3^3;
sbit s5=P3^4;
sbit s6=P3^5;
sbit led=P3^6;
sbit sw1=P1^0;
sbit sw2=P1^1;
sbit sw3=P1^2;
void delay (int);
void stop();
unsigned char A[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int k,h,m,s;
void main()
{

s1=s2=s3=s4=s5=s6=1;
P2=0x00;
led=1;
while(1)
{
	for(h=0;h<24;h++)
	{
		for(m=0;m<60;m++)
		{
			for(s=0;s<60;s++)
			{
			for(k=0;k<15;k++)
			{
				P2=A[s%10];s1=0;delay(1);s1=1;
				P2=A[s/10];s2=0;delay(1);s2=1;
				
		    P2=A[m%10];s3=0;delay(1);s3=1;
				P2=A[m/10];s4=0;delay(1);s4=1;
				
			  P2=A[h%10];s5=0;delay(1);s5=1;
				P2=A[h/10];s6=0;delay(1);s6=1;
			}
			led=0;
			delay(10);
			led=1;
			if(sw1==0)
			{
				stop();
			//return from stop
			}
			
			}
		}
	}
}
}
void stop()
{
	/*********stop and auto hr mode*********/
	while(sw1==0);
	while(sw1==1)
	{
				P2=A[s%10];s1=0;delay(1);s1=1;
				P2=A[s/10];s2=0;delay(1);s2=1;
				
		    P2=A[m%10];s3=0;delay(1);s3=1;
				P2=A[m/10];s4=0;delay(1);s4=1;
				
			  P2=A[h%10];s5=0;delay(1);s5=1;
				P2=A[h/10];s6=0;delay(1);s6=1;
		if(sw2==0)
					{
						while(sw2==0);
						if(h<23)
						{
							h++;
						}
						else
						{
							h=0;
						}
					}
					else if(sw3==0)
					{
						while(sw3==0);
						if(h>0)
						{
							h--;
						}
						else
						{
							h=23;
						}
					}
	}
	/***********min mode*************/
	while(sw1==0);
	while(sw1==1)
	{
				P2=A[s%10];s1=0;delay(1);s1=1;
				P2=A[s/10];s2=0;delay(1);s2=1;
				
		    P2=A[m%10];s3=0;delay(1);s3=1;
				P2=A[m/10];s4=0;delay(1);s4=1;
				
			  P2=A[h%10];s5=0;delay(1);s5=1;
				P2=A[h/10];s6=0;delay(1);s6=1;
		if(sw2==0)
					{
						while(sw2==0);
						if(m<59)
						{
							m++;
						}
						else
						{
							m=0;
						}
					}
					else if(sw3==0)
					{
						while(sw3==0);
						if(m>0)
						{
							m--;
						}
						else
						{
							m=59;
						}
					}
	}
		/***********sec mode*************/
	while(sw1==0);
	while(sw1==1)
	{
				P2=A[s%10];s1=0;delay(1);s1=1;
				P2=A[s/10];s2=0;delay(1);s2=1;
				
		    P2=A[m%10];s3=0;delay(1);s3=1;
				P2=A[m/10];s4=0;delay(1);s4=1;
				
			  P2=A[h%10];s5=0;delay(1);s5=1;
				P2=A[h/10];s6=0;delay(1);s6=1;
		if(sw2==0)
					{
						while(sw2==0);
						if(s<59)
						{
							s++;
						}
						else
						{
							s=0;
						}
					}
					else if(sw3==0)
					{
						while(sw3==0);
						if(s>0)
						{
							s--;
						}
						else
						{
							s=59;
						}
					}
	}
	while(sw1==0);
	//start hr
}
void delay(int m)
{
	int i,j;
	for(i=0;i<m;i++)
	for(j=0;j<1275;j++);
}