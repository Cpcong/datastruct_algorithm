/*
题目：调整数组顺序使奇数位于偶数前面
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位位于数组的前半部分，所有偶数位于数组的后半部分
*/

/*
解决思路：
维护两个指针，第一个指针初始化时指向数字第一个数字，它只向后移动.
第二个指针初始化时指向数组的最后一个数字，它只向前移动.
如果第一个指针指向的数字是偶数，并且第二个指针指向的数字的奇数，
我们就交换着两个数字,直到两个指针相遇
*/
#include "stdio.h"

void Swap(int *n1, int *n2)
{
    int t;
    t = *n1;
    *n1 = *n2;
    *n2 = t;
}


void RecorderOddEven(int arr[], unsigned int length, int (* func)(int))
{
    int left = 0;
    int right = length - 1;
    if(arr == NULL || length < 1){
        return ; 
    }
    while(left < right){
        while((left < length) && func(arr[left])){
            left++; 
        }
        while((right > 0) && !func(arr[right])){
            right--; 
        }
        if(left < right){
            Swap(&arr[left], &arr[right]);  
        }
    }
}

int isEven(int num)
{
    return (num & 0x01 == 1) ? 1 : 0;
}


//=================测试代码=======================
void Test(char *testName, int arr[], unsigned int length)
{
    int i;
    if(testName != NULL){
        printf("%s begined.\n", testName); 
    }
    for(i = 0;i < length;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    RecorderOddEven(arr, length, isEven);
    for(i = 0;i < length;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//功能测试
void Test1()
{
    int numbers[] = {1, 2, 3, 4, 5};
    Test("Test1", numbers, sizeof(numbers)/sizeof(numbers[0]));
}

//全为奇数
void Test2()
{
    int numbers[] = {1, 3, 5, 7, 9};
    Test("Test2", numbers, sizeof(numbers)/sizeof(numbers[0]));
}

//全为偶数
void Test3()
{
    int numbers[] = {2, 4, 6, 8, 10};
    Test("Test3", numbers, sizeof(numbers)/sizeof(numbers[0]));
}

//前面为奇数后面为偶数
void Test4()
{
    int numbers[] = {1, 3, 5, 2, 4, 6};
    Test("Test4", numbers, sizeof(numbers)/sizeof(numbers[0]));
}

//前面为偶数后面为奇数
void Test5()
{
    int numbers[] = {2, 4, 6, 1, 3, 5};
    Test("Test5", numbers, sizeof(numbers)/sizeof(numbers[0]));
}

//只有一个奇数
void Test6()
{
    int numbers[] = {1};
    Test("Test6", numbers, sizeof(numbers)/sizeof(numbers[0]));
}

//只有一个偶数
void Test7()
{
    int numbers[] = {2};
    Test("Test7", numbers, sizeof(numbers)/sizeof(numbers[0]));
}

//空输入
void Test8()
{
    Test("Test8", NULL, 0);
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
    
    return 0;
}
