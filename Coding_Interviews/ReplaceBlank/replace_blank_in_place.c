/*
题目：替换空格

请实现一个函数，把字符串中的每个空格替换成“%20”.例如输入“We are happy.”.
则输出“We%20are%20happy.”.

在原来的字符串上做替换，并且保证输入的字符串后面有足够多的空余内存
*/

/*
时间复杂度O(n)
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define STRING_LENGTH 100

void ReplaceBlank(char str[], int length)
{
    int originalLen = 0;
    int resultLen;
    int numOfBlank = 0;
    int indexOfOrigin;
    int indexOfNew;
    if(str == NULL || length <= 0){
        return; 
    }
    while(str[originalLen] != '\0'){
        if(str[originalLen] == ' '){
            ++numOfBlank;
        }
        ++originalLen;
    }
    resultLen = originalLen + numOfBlank * 2;
    if(resultLen > length){
        return; 
    }
    indexOfOrigin = originalLen;
    indexOfNew = resultLen;
    while(indexOfOrigin >= 0 && indexOfNew == indexOfNew){
        if(str[indexOfOrigin] == ' '){
            str[indexOfNew--] = '0'; 
            str[indexOfNew--] = '2'; 
            str[indexOfNew--] = '%'; 
        }else{
            str[indexOfNew--] = str[indexOfOrigin]; 
        } 
        indexOfOrigin--;
    }
}

void Test(char* testName, char str[], int length, char expected[])
{
    if(testName != NULL){
        printf("%s begins: ", testName); 
    }
    ReplaceBlank(str, length);
    if(expected == NULL && str == NULL){
        printf("passed.\n"); 
    }else if(expected == NULL && str != NULL){
        printf("failed.\n"); 
    }else if(strcmp(str, expected) == 0){
        printf("passed.\n"); 
    }else{
        printf("failed.\n"); 
    }
}

// 空格在句子中间
void Test1()
{
    char string[STRING_LENGTH] = "hello world";
    Test("Test1", string, STRING_LENGTH, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    char string[STRING_LENGTH] = " helloworld";
    Test("Test2", string, STRING_LENGTH, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    char string[STRING_LENGTH] = "helloworld ";
    Test("Test3", string, STRING_LENGTH, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    char string[STRING_LENGTH] = "hello  world";
    Test("Test4", string, STRING_LENGTH, "hello%20%20world");
}

// 传入NULL
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// 传入内容为空的字符串
void Test6()
{
    char string[STRING_LENGTH] = "";
    Test("Test6", string, STRING_LENGTH, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    char string[STRING_LENGTH] = " ";
    Test("Test7", string, STRING_LENGTH, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    char string[STRING_LENGTH] = "helloworld";
    Test("Test8", string, STRING_LENGTH, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    char string[STRING_LENGTH] = "   "; 
    Test("Test9", string, STRING_LENGTH, "%20%20%20");
}


int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    return 0;
}
