
#include <htc.h>
#include <stdio.h>
#include "usart.h"

void 
putch(unsigned char byte) 
{
	// envia um byte 
	while(!TXIF)	// n�vel l�gico alto quando o registrador est� vazio
		continue;
	TXREG = byte;
}

unsigned char 
getch() {
	// recebe um byte 
	while(!RCIF)	//n�vel l�gico alto quando o registrador n�o est� vazio 
		continue;
	return RCREG;	
}

unsigned char
getche(void)
{
	unsigned char c;
	putch(c = getch());
	return c;
}

