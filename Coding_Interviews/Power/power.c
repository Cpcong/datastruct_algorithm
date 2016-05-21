/*
题目：数值的整数次方
实现函数double Power(double base, int exponent),求base的exponent次方。不得使用库函数，同时不需要考虑大数问题
*/

/*
注意点：
1. 输入指数为负数情况
2. 输入底数为0，指数为负数情况(属于错误输入)
3. 输入底数为0，指数也为0情况(无意义，协商返回0或1)
4. double类型的判断(不可直接用==)
*/
#include "stdio.h"
#include "stdlib.h" 

int g_InvalidInput = 0;

int Equal(double n1, double n2)
{
    if((n1 - n2 > -0.0000001) && (n1 - n2 < 0.0000001)){
        return 1; 
    }else{
        return 0; 
    }

}
/*
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    int i;
    double result = 1;
    for(i = 0;i < exponent;i++){
        result *= base; 
    }
    return result;
}
*/

//高效解法，求2^16，相当于先求4的8次方，再求16的4次方,再求256的平方,
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if(exponent == 0){
        return 1; 
    }
    if(exponent == 1){
        return base; 
    }
    if(exponent & 0x01){
        return base * PowerWithUnsignedExponent(base * base, (exponent - 1) >> 1);
    }else{
        return PowerWithUnsignedExponent(base * base, exponent >> 1);
    }
}

double Power(double base, int exponent)
{
    int i;
    unsigned int absExponent;
    double result = 1;
    if(Equal(base, 0.0) && exponent < 0){
        g_InvalidInput = 1;
        return 0.0; 
    }
    absExponent = (unsigned int)exponent;
    if(exponent < 0){
        absExponent = (unsigned int)-exponent;
    } 
    result = PowerWithUnsignedExponent(base,absExponent);
    if(exponent < 0){
        result = 1.0 / result; 
    }
    return result;
}

//=================测试代码====================
void Test(double base, int exponent, double expectedResult, int expectedFlag)
{
    double actualResult = Power(base, exponent);
    if( ((actualResult - expectedResult) > -0.0000001) && ((actualResult - expectedResult) < 0.0000001) && (expectedFlag == g_InvalidInput)){
        printf("Test passed.\n"); 
    }else{
        printf("Test failed.\n"); 
    }
}


int main()
{
    // 底数、指数都为正数
    printf("Test1 begins.\n");
    Test(2, 3, 8, 0);

    // 底数为负数、指数为正数
    printf("Test2 begins.\n");
    Test(-2, 3, -8, 0);

    // 指数为负数
    printf("Test3 begins.\n");
    Test(2, -3, 0.125, 0);

    // 指数为0
    printf("Test4 begins.\n");
    Test(2, 0, 1, 0);

    // 底数、指数都为0
    printf("Test5 begins.\n");
    Test(0, 0, 1, 0);

    // 底数为0、指数为正数
    printf("Test6 begins.\n");
    Test(0, 4, 0, 0);

    // 底数为0、指数为负数
    printf("Test7 begins.\n");
    Test(0, -4, 0, 1);

    return 0;
}



