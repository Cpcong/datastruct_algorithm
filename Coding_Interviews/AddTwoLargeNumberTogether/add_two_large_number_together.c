/*
题目：大数相加
定义一个函数，在该函数中可以实现任意两个整数的加法
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char* MinusWithUnsignedNumber(char *number1, char *number2);
char* Add(char *number1, char *number2)
{
    int i;
    char *result;
    int a, b;
    int len1 = strlen(number1);
    int len2 = strlen(number2);
    int len = len1 > len2 ? len1 : len2;
    //一正一负，做减法操作
    if(number1[0] == '-' && number2[0] != '-'){
        result = MinusWithUnsignedNumber(number2, number1 + 1); 
    }else if(number1[0] != '-' && number2[0] == '-'){
        result = MinusWithUnsignedNumber(number1, number2 + 1); 
    }else{    
        result = malloc(sizeof(char) * (len + 3));//多分配3个位置，一个存放符号指示，一个存储进位，一个存储结束符'\0' 
        memset(result + 1, '0', len + 1);
        result[len + 2] = '\0';
        //都为正符号指示位为0，都为正符号指示位为'-'
        if(number1[0] == '-' && number2[0] == '-'){
            result[0] = '-'; 
            number1 = number1 + 1;
            len1--;
            number2 = number2 + 1;
            len2--;
        }else{
            result[0] = '0'; 
        }
        //number1和number2对应位相加
        for(i = len;i > 0;i--){
            //number不足的位用0代替
            a = len1 > 0 ? number1[len1 - 1] - '0' : 0; 
            b = len2 > 0 ? number2[len2 - 1] - '0' : 0; 
            len1--;
            len2--;
            result[i + 1] =  a + b + '0'; 
        }
        //对需要进行进位的位进行处理
        for(i = len + 1;i > 1;i--){
            if(result[i] >= ('0' + 10)){
                result[i] -= 10;
                result[i - 1] += 1; 
            } 
        }
    }
    return result;
}

//两个非负数相减,return number1 - number2
char* MinusWithUnsignedNumber(char *number1, char *number2)
{
    int i, j;
    char a, b;
    char sign;
    char isBorrow = 0;
    int len1 = strlen(number1);      
    int len2 = strlen(number2);      
    int maxLen = len1 > len2 ? len1 : len2;
    //取len1和len2最大数并加2，多出来的两个位置一个用来存放符号位'+(-)'，一个用来存放结束符'\0'
    char *result = malloc(sizeof(char) * (maxLen + 2));
    result[maxLen + 1] =  '\0';

    //判断结果是负数还是非负数
    if(len1 < len2){
        sign = '-'; 
    }else if(len1 > len2){
        sign = '+'; 
    }else{
        char cmpResult = strcmp(number1, number2); 
        //判断两个整数是否相等
        if(cmpResult == 0){
            memset(result,'0', maxLen + 1);
            return result; 
        }
        sign = cmpResult > 0 ? '+' : '-';
    } 
    //符号指示位为'0'或'-'
    result[0] = sign == '+' ? '0' : '-';
    for(i = maxLen - 1;i >= 0;i--){
        //当number长度不足的时候用'0'进行操作
        a = len1 > 0 ? number1[len1 - 1] : '0';
        b = len2 > 0 ? number2[len2 - 1] : '0';
        len1--;
        len2--;
        result[i + 1] = '0' + ((sign == '-') ? (b - a) : (a - b)); 
    }
    //对结果集进行操作，若有< '0'的位，则需要向前借位
    for(i = maxLen;i >= 1;i--){
        if(result[i] < '0'){
            result[i] += 10; 
            result[i - 1] -= 1;
        }
    }
    return result;
}

//=================测试代码==============
void Test(char *testName, char *number1, char *number2)
{
    if(testName != NULL){
        printf("%s begined.\n", testName); 
    } 
    printf("%s + %s = %s.\n", number1, number2, Add(number1, number2));
}

void Test1()
{
    char s1[100] = "123";
    char s2[100] = "400";
    Test("Test1", s1, s2);
}
void Test2()
{
    char s1[100] = "125";
    char s2[100] = "-400";
    Test("Test2", s1, s2);
}
void Test3()
{
    char s1[100] = "-125";
    char s2[100] = "400";
    Test("Test3", s1, s2);
}
void Test4()
{
    char s1[100] = "-123";
    char s2[100] = "-400";
    Test("Test4", s1, s2);
}
void Test5()
{
    char s1[100] = "123";
    char s2[100] = "-123";
    Test("Test4", s1, s2);
}
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    return 0;
    
}

