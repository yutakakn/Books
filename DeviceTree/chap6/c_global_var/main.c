/*
 * main.c
 *
 * cc main.c sub.c
 */ 
#include <stdio.h>

int g_sample;

void sub(void);

int main(void)
{
	printf("%d\n", g_sample);
	sub();
	printf("%d\n", g_sample);

	return 0;
}

