/*
 ============================================================================
 Name        : helloworld.c
 Author      : lph
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



static uint16_t TransmitCrc(uint8_t *bytes, uint32_t len) {
	int crc = 0;
	int i, j;
	for (i = 0; i < len; i++) {
		crc = crc ^ bytes[i] << 8;
		for (j = 0; j < 8; j++) {
			if ((crc & ((int) 0x8000)) != 0)
				crc = crc << 1 ^ 0x1021;
			else
				crc = crc << 1;
		}
	}
	return crc & 0xFFFF;
}

int main(void) {
	uint8_t buf[9]={0x80,0x11,0x01,0x01};
	uint8_t i ,m=10;

	printf("crc:%04x\r\n",TransmitCrc(buf,4));
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	for(i=0;i<20;i++)
	{
		switch(m)
		{
		case 1:
			break;
		case 2:
			break;
		default:
			if(m==i)
			{
				printf("m=%d\r\n",m);
				break;
			}
			break;
		}
		printf("i=%d\r\n",i);
	}

	printf("hello github\r\n");
	printf("hello github1\r\n");
	printf("hello github2\r\n");

	printf("desp say:hello\r\n");
	printf("lph sya :hello\r\n");


	return EXIT_SUCCESS;
}
