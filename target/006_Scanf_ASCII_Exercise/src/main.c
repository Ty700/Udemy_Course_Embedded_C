/*
 * main.c
 *
 *  Created on: Dec 4, 2023
 *      Author: tyler
 */
#include <stdio.h>

#define NUMBER_OF_INPUTS 5

int main(void){

	char in1, in2, in3, in4, in5;
	printf("Enter %d characters of your choice: ", NUMBER_OF_INPUTS);
		scanf("%c %c %c %c %c ", &in1, &in2, &in3, &in4, &in5);

	printf("%d %d %d %d %d", in1, in2, in3, in4, in5);

	return 0;
}
