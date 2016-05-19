/*
题目：
对公司所有员工的年龄(0~100)进行排序,要求时间效率O(n), 空间效率为常量
*/
#include "stdio.h"

void SortAges(int ages[], int length)
{
    int i, j;
    int index = 0;
    int arr[100] = {0};
    for(i = 0;i < length;i++){
        arr[ages[i]]++; 
    } 

    for(i = 0;i < 100;i++){
        for(j = 0;j < arr[i];j++){
            ages[index++] = i; 
        } 
    }
}

//===================测试代码================
int main()
{
    int i;
    int ages[10] = {23, 32, 41, 18, 22, 33, 20, 22, 26, 36}; 
    SortAges(ages, 10);
    for(i = 0;i < 10;i++){
        printf("%d ", ages[i]); 
    }
    return 0;
}
