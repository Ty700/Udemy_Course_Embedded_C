/*
 * If anyone is actually reading this, I know it may seem that I am "restarting" my learning for C, but really I am doing simply projects in
 * a completely new IDE. Thus, I am making simple programs that I know work, just to get use to the new IDE (STMCUBEIDE)
 */

#include <stdint.h>
#include <stdio.h>

int main(void){
	uint32_t age = 0;

	printf("Enter your age: ");
		scanf("%d", &age);

	if(age >= 18){
		printf("You can vote!\n");
	} else {
		printf("Come back in %d years to be eligble!\n", 18 - age);
	}
}
