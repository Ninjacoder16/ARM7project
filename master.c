#include<lpc214x.h>
void send_data(char *p);
void delay(int a);

int main()
{
PINSEL0=0x00001500;                        //
	IODIR0=(1<<7);                           //
	IOSET0=(1<<7);													 //
	S0SPCCR=8;                               // Doubtfull Use we dont know
	S0SPCR=0x70;                             // Configuratopn register            
	
	{
  send_data("SPI WORKING");
	}
	while(1);
}

void send_data(char *p) {
    while (*p != '\0') {
        // Start SPI transmission by pulling CS low
        IOCLR0 = (1 << 7);

        // Send the current character
        S0SPDR = (*p++ & 0xFF);    // Mask to ensure only 8 bits are sent
        while ((S0SPSR & (1 << 7)) == 0);  // Wait for transmission to complete

        // Deactivate CS
        IOSET0 = (1 << 7);
        delay(12);                  // Short delay for stability
    }
		
}

void delay(int a){
int i;
for(i=0; i<=a*123005; i++);
}

/*  IOCLR0=(1<<7);
		S0SPDR=0X01;
		while((S0SPSR &(1<<7))==0);
		IOSET0=(1<<7);
		delay(12);
		IOCLR0=(1<<7);
		S0SPDR=0X0F<<4;
		while((S0SPSR &(1<<7))==0);
		IOSET0=(1<<7);*/