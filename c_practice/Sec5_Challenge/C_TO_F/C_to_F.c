#include <stdio.h>


//C => F Constants
#define C_CONST 32
#define F_TO_C_MULTI 1.8

int main(){

    double tempToConvert = 0;
    printf("Enter a temp in C: ");
        scanf("%lf", &tempToConvert);

    printf("%.2lf C = %.2lf F\n", tempToConvert, (tempToConvert * F_TO_C_MULTI + C_CONST));

    printf("Enter a temp in F: ");
        scanf("%lf", &tempToConvert);
    printf("%.2lf F = %.2lf C\n", tempToConvert, ((double)(tempToConvert - C_CONST) / F_TO_C_MULTI));

}