#include "stdio.h"

static void Swap(int *n1, int *n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int Partition(int arr[], int start, int end, int length)
{
    int i;
    int small = start - 1;
    //选取最后一个元素作为主元
    int x = arr[end];
    for(i = start;i < end;i++){
        //小于主元的依次放在前面
        if(arr[i] < x){
            small++;
            Swap(&arr[small], &arr[i]);
        } 
    }
    small++;
    //交换主元位置，主元已排好序
    Swap(&arr[small], &arr[end]);
    return small;

}

void QuickSort(int arr[], int start, int end, int length)
{
    int index = Partition(arr, start, end, length);
    if(index > start){
        QuickSort(arr, start, index - 1, length);
    }
    if(index < end){
        QuickSort(arr, index + 1, end, length);
    }
}

//=================测试代码================

int main()
{
    int i;
    int arr[9] = {5, 3, 7, 1, 6, 8, 2, 4, 9};
    //int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    QuickSort(arr, 0, 8, 9);
    for(i = 0;i < 9;i++){
        printf("%d ", arr[i]); 
    }
    return 0;
}

