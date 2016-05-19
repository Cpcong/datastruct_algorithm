/*
题目：旋转数组的最小数字
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如数组{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1
Hint:二分查找
*/
#include "stdio.h"
#include "stdlib.h"

int MinInOrder(int *numbers, int left, int right)
{
    int i;
    int min = numbers[left];
    for(i = left + 1;i < right;i++){
        if(min > numbers[i]){
            min = numbers[i]; 
        }
    }
    return min;
}

int Min(int arr[], int length)
{
    int left = 0;
    int right = length - 1;
    //mid初始为left，一旦数组本身是有序的(翻转0个),直接return arr[mid]
    int mid = left;
    if(arr == NULL || length <= 0){
        printf("Invalid parameters.\n");    
        exit(0);
    }
    while(arr[left] >= arr[right]){
        // 如果left和right指向相邻的两个数，
        // 则left指向第一个递增子数组的最后一个数字，
        // right指向第二个子数组的第一个数字，也就是数组中的最小数
        if((right - left) == 1){
            mid = right; 
            break;
        }
        mid = (left + right)/2;  
        //如果下标为left，right，mid指向的三个数字相等，只能顺序查找
        if((arr[left] == arr[right]) && (arr[mid] == arr[right])){
            return MinInOrder(arr, left, right); 
        }
        //缩小查找范围
        if(arr[left] <= arr[mid]){
            left = mid; 
        }else if(arr[mid] <= arr[right]){
            right = mid; 
        }
    }
    return arr[mid];
}

//==================测试代码================
void Test(int arr[], int length, int expected)
{
    int i;
    int result = Min(arr, length);
    for(i = 0;i < length;i++){
        printf("%d ", arr[i]); 
    }
    if(result != expected){
        printf("Test Failed.\n");  
    }else{
        printf("Test Passed.\n"); 
    }

}

int main()
{
  // 典型输入，单调升序的数组的一个旋转
    int array1[] = {3, 4, 5, 1, 2};
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = {3, 4, 5, 1, 1, 2};
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = {3, 4, 5, 1, 2, 2};
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = {1, 0, 1, 1, 1};
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = {1, 2, 3, 4, 5};
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = {2};
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // 输入NULL
    Test(NULL, 0, 0);

    return 0;
}
