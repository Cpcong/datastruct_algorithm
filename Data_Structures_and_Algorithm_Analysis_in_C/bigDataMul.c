//两个最多1000位的大数相乘，并打印出结果
#include "stdio.h"
#include "string.h"

#define N 1000

#define RESULT_LEN (N + N)
int main()
{
    int result[RESULT_LEN];
    char num1[N];
    char num2[N]; 
    int len1, len2;
    int i, j;
    int flag = 0;
    printf("input first num\n");
    gets(num1); 
    printf("input second num\n");
    gets(num2);
    len1 = strlen(num1);
    len2 = strlen(num2);
    for(i = 0;i < RESULT_LEN;i++){
        result[i] = 0;
    }
    for(i = 0;i < len1;i++){
        for(j = 0;j < len2;j++){
            result[j + i] += (num1[len1 - 1 - i] - '0') * (num2[len2 - 1 - j] - '0');//num1[0]为最高位，因此len1 - 1最低位开始
            //printf("result[%d]:%d\n", i + j, result[i + j]);
        } 
    }
    for(i = 1;i < RESULT_LEN;i++){
        result[i] += result[i - 1]/10; 
        result[i - 1] = result[i - 1]%10;
    }
    for(i = RESULT_LEN;i > 0;i--){
        if(result[i - 1] == 0 && flag == 0){
            continue;
        }
        flag = 1;
        printf("%d", result[i - 1]);
    }
}
