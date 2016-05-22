/*
题目：打印1到最大的n位数
输入数字n，按顺序打印出从1到最大的n位十进制数。
比如输入3，则打印出1, 2, 3一直到最大的3位数即999
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//==============solution1=============

/*
思路：
在字符串表达的数字上模拟加法
*/
int Increment(char *number)
{
    int i;
    int isMax = 0;
    int intNum;
    int len = strlen(number);
    for(i = len - 1;i >= 0;i--){
        //个位数加1
        if(i == len - 1){
            number[i]++; 
        } 
        intNum = number[i] - '0';
        //检查进位
        if(intNum >= 10){
            //当第0位产生进位时，则已经是最大的n位数
            if(i == 0){
                isMax = 1; 
            }else{
                intNum -= 10;
                number[i] = intNum + '0';
                //进位+1
                number[i - 1]++;
            } 
        }else{
            break; 
        }
    }
    return isMax;
}

void PrintNumber(char *number)
{
    while(*number == '0'){
        number++;
    }
    printf("%s ", number);
}

void Print1ToMaxOfNDigits_1(int n)
{

    if(n < 1){
        printf("Invalid input : n must be > 0.\n"); 
        exit(0);
    }
    char *number = malloc(sizeof(char) * (n + 1));
    memset(number, '0', n);
    number[n] = '\0';
    while(!Increment(number)){
        PrintNumber(number); 
    }
    free(number);
}

//===================solution2=====================
/*
递归法：
n位所有十进制数其实就是n个从0到9的全排列
*/
void Print1ToMaxOfNDigits_Recursively(char *number, int length, int index)
{
    int i;
    //最后位数字设置完，打印
    if(index == length - 1){
        PrintNumber(number); 
        return;
    }
    //对第index + 1位数字从0设置到9
    for(i = 0;i < 10;i++){
        //设置第index + 1位数字
        number[index + 1] = i + '0'; 
        //递归设置下一位数字
        Print1ToMaxOfNDigits_Recursively(number, length, index + 1);
    }
}

void Print1ToMaxOfNDigits_2(int n)
{
    if(n < 1){
        printf("Invalid input : n must be > 0.\n"); 
        exit(0);
    }
    int i;
    char *number = malloc(sizeof(char) * (n + 1));
    number[n] = '\0';
    for(i = 0;i < 10;i++){
        //设置第0位数字
        number[0] = i + '0'; 
        Print1ToMaxOfNDigits_Recursively(number, n, 0);
        
    }
}




// ====================测试代码====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);

    Print1ToMaxOfNDigits_1(n);
    Print1ToMaxOfNDigits_2(n);

    printf("Test for %d ends.\n", n);
}

int main()
{
    Test(1);
    Test(2);
    Test(3);
    Test(0);
    Test(-1);

    return 0;
}




