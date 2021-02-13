/*
 * LCD_8bit.c
 *
 * Created: 13-02-2021 12:10:41
 * Author : Amit Singh
 */ 

#include <avr/io.h>
#include <util/delay.h>

int com_lcd(int cmd)
{
	PORTB=cmd; // sending command to d0-d7
	PORTC&=~(1<<0); //rs=0     command mode
	PORTC&=~(1<<1); // rw=0    write
	PORTC|=(1<<2);  // e=1,   enable pulse
	_delay_ms(2);
	PORTC&=~(1<<2); // e=0,   enable pulse
	
	
}


int data_lcd(int data)
{
	PORTB=data; // sending data to d0-d7
	PORTC|=(1<<0); //rs=1    data mode
	PORTC&=~(1<<1); // rw=0    write
	PORTC|=(1<<2);  // e=1,   enable pulse
	_delay_ms(2);
	PORTC&=~(1<<2); // e=0,   enable pulse
	
	
}

int lcd_print (char *s)
{
	int index=0;
	
	while (s[index]!=0)
	{
		data_lcd(s[index]);
		index++;
	}
	
	
}
int init_lcd()
{
	com_lcd(0x38);
	com_lcd(0x0e);
	com_lcd(0x01);
	com_lcd(0x06);
	com_lcd(0xc0);
	
}


int main(void)
{
	DDRB=0xff;
    DDRC=0xff;
	
	init_lcd();
	
	//data_lcd('a');
	//data_lcd('b');
	
	lcd_print("hello hi how r u 1234567890");
}

