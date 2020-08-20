/*
 * macos.c
 *
 *  Created on: Apr 14, 2020
 *      Author: Mauro
 */
#include <stdio.h>
#include <stdlib.h>

void macos_clear(void)
{
	int i;
	for(i = 0; i < 100; i++ )
		printf("\n");
}

void macos_pause(void)
{
	char buffer[2];
	fpurge(stdin);
	fgets(buffer,2,stdin);
}

void macos_fflush(void)
{
	fpurge(stdin);
}
