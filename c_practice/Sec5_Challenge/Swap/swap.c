#include <stdio.h>

int main(){

    double a, b;

    printf("Enter in a number: ");
        scanf("%lf", &a);
    printf("Enter in another number: ");
        scanf("%lf", &b);
    printf("Before: A: %lf B: %lf\n", a, b);
    b += a;
    a = b - a;
    b -= a;
    printf("After: A: %lf B: %lf\n", a, b);
}