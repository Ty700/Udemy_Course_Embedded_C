/*
 * main.c
 *
 *  Created on: Dec 4, 2023
 *      Author: tyler
 */

#include <stdio.h>
#include <stdint.h>

int main(void){
	char var = 100;

	printf("%c\n", var);
	printf("Address: %p\n", &var);

	char* p_var = &var;
	*p_var = 65;

	printf("%c\n", var);
}
