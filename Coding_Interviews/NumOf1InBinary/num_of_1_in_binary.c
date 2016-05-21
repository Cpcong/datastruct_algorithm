/*
题目：二进制中1的个数
请实现一个函数，输入一个整数，输出该数二进制中1的个数。
例如把9表示成二进制是1001有2位是1。因此如果输入9，该函数输出2
*/
#include "stdio.h"
//O(n) Solution.(n为整数的位数)
int NumOf1InBinary_Solution1(int n)
{
    int bit = 1;
    int count = 0;
    while(bit){
        if(n & bit){
            count++; 
        } 
        bit <<= 1;
    }
    return count;
}

//比第一种方法更快，输入整数1有多少位就循环多少次
/*
解决思路，把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0
那么一个整数的二进制表示中有多少个1，就可以进行多少次这样的操作
*/
int NumOf1InBinary_Solution2(int n)
{
    int count = 0;
    while(n){
        n = n & (n - 1); 
        count++;
    }
    return count;
}

//==================测试代码=======================
void Test(int n, unsigned int expected)
{
    int actual = NumOf1InBinary_Solution1(n);
    if(actual == expected){
        printf("Solution1: Test for %d passed.\n", n); 
    }else{
        printf("Solution1: Test for %d failed.\n", n); 
    }

    actual = NumOf1InBinary_Solution2(n);
    if(actual == expected){
        printf("Solution2: Test for %d passed.\n", n); 
    }else{
        printf("Solution2: Test for %d failed.\n", n); 
    }
    printf("\n");
}

int main()
{
    // 输入0，期待的输出是0
    Test(0, 0);

    // 输入1，期待的输出是1
    Test(1, 1);

    // 输入10，期待的输出是2
    Test(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    Test(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test(0xFFFFFFFF, 32);

    // 输入0x80000000（负数），期待的输出是1
    Test(0x80000000, 1);

    return 0;
}
