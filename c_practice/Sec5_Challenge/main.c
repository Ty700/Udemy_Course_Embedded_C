#include <stdio.h>
#include "main.h"

int main(){
    int result1 = add_nums(1,1,1);
    int result2 = sub_nums(1, 1, 1);
    long long int result3 = multi_nums(10, 10, 1);
    float result4 = divide_nums(100, 5, 3);

    printf("%d, %d, %lld, %f\n",result1,result2,result3,result4);
}