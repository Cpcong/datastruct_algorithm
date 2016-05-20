/*
题目：斐波那契数列
写一个函数，输入n，求斐波那契(Fibonacci)数列的第n项.
*/
#include "stdio.h"

int Fibonicci(int n)
{
    int last = 0;
    int current = 1;
    int tmp;
    int i;
    if(n == 0){
        return 0; 
    }
    if(n == 1){
        return 1; 
    }
    for(i = 2;i <= n;i++){
        tmp = last + current;
        last = current;
        current = tmp; 
    }
    return current;
}

int main()
{
    int result = Fibonicci(5);
    printf("%d\n", result);
    result = Fibonicci(6);
    printf("%d\n", result);
    result = Fibonicci(7);
    printf("%d\n", result);
    result = Fibonicci(8);
    printf("%d\n", result);
    return 0;
}

