#include <stdio.h>

int main(){

    int g1, g2, g3;

    printf("Enter grade1: ");
        scanf("%d", &g1);
    printf("Enter grade2: ");
        scanf("%d", &g2);
    printf("Enter grade3: ");
        scanf("%d", &g3);

    double avg = (double)(g1 + g2 + g3) / 3;

    printf("%.2f\n", avg);
} 