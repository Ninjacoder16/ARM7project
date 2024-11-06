#include<lpc214x.h>
#include"slavelcd.h"
void delay(int a);

int main()
{
PINSEL0=0x00005500;
PINSEL2=0x00000000;
IODIR1=0x00FF0000;
S0SPCR=0x50;
lcd_int();
while(1)
{
while(!(S0SPSR & (1<<7)));
Data(S0SPDR);
}
}

/*void delay(int a){
int i;
for(i=0; i<=a*123005; i++);
}*/