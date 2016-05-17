/*
有两个排序的数组A1和A2，内存在A1的末尾有足够多的空余空间容纳A2.
请实现一个函数，把A2中的所有数字插入到A1中并且所有的数字是排序的
*/

/*
时间复杂度O(n)
*/
#include "stdio.h"
void MergeSortedArray(int A1[], int len1, int A2[], int len2)
{
    int len = len1 + len2; 
    int indexOfA1 = len1 - 1;
    int indexOfA2 = len2 - 1;
    int tail = len - 1;
    while(indexOfA1 >= 0 && indexOfA2 >=0){
        if(A1[indexOfA1] < A2[indexOfA2]){
            A1[tail--] = A2[indexOfA2--];
        }else{
            A1[tail--] = A1[indexOfA1--]; 
        } 
    }
    while(indexOfA1 >= 0){
        A1[tail--] = A1[indexOfA1--];
    }
    while(indexOfA2 >= 0){
        A1[tail--] = A2[indexOfA2--];
    }
}


int main()
{
    int i;
    int A1[100] = {1, 3, 5, 5, 6, 7}; 
    int A2[5] = {2, 4, 8, 10, 11};
    MergeSortedArray(A1, 6, A2, 5);
    for(i = 0;i < 11;i++){
        printf("%d ", A1[i]);       
    }
    printf("\n");
    return 0;
}
