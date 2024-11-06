#include<lpc214x.h>

void lcd_int(void);
void delay(int m);
void cmd(unsigned int a );
void Data(unsigned int b );
void name(unsigned char *ptr);


void lcd_int(void){
	cmd(0x02);            
	cmd(0x28);
	cmd(0x01);
	cmd(0x0F); 
	cmd(0x06);	
	cmd(0x80); 
	delay(1);
}

void cmd(unsigned int a ){
	 IOCLR1 = 0X00FF0000;          // 0.16 to 0.23 OUTPUT datalines RS=0.14 EN=0.15;
	 int b = a>>4;
	 IOSET1=(b<<16);
	 IOCLR1=(1<<20);  //0X00FF8000  //RS
	 IOSET1=(1<<21);  //0X00FF8000  //EN
	 delay(1);
	 IOCLR1=(1<<21);  //0X00FF8000
	 delay(1);
	
	 IOCLR1 = 0X007F0000;          // 0.16 to 0.23 OUTPUT datalines RS=0.14 EN=0.15;
	 IOSET1=(a<<16);
	 IOCLR1=(1<<20);  //0X00FF8000   //RS
	 IOSET1=(1<<21);  //0X00FF8000   //EN
	 delay(1);
	 IOCLR1=(1<<21);  //0X00FF8000
	 delay(1);
}

void Data(unsigned int b ){
	 IOCLR1 = 0X007F0000; 
	 int a = b>>4;                            //higher bits of a
	 IOSET1=(a<<16);
	 IOSET1=(1<<20);  //0X00FF8000
	 IOSET1=(1<<21);  //0X00FF8000
	 delay(1);
	 IOCLR1=(1<<21);  //0X00FF8000
	 delay(1);
	
	 IOCLR1 = 0X00fF0000;          // 0.16 to 0.23 OUTPUT datalines RS=0.14 EN=0.15;
	 IOSET1=(b<<16);
	 IOSET1=(1<<20);  //0X00FF8000
	 IOSET1=(1<<21);  //0X00FF8000
	 delay(1);
	 IOCLR1=(1<<21);  //0X00FF8000
	 delay(1);
	
	
}

void delay(int m){
int i;
for(i=0; i<12300*m; i++);
}

void name(unsigned char *ptr){
	unsigned int i;
	for(i=0; *ptr!='\0'; i++){
	  Data(*ptr++);
	}
}
