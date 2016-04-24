#include "stdio.h"

#define LEFT_CHILD(i) (2 * i + 1)

static Swap(int *n1, int *n2)
{
    int t;
    t = *n1;
    *n1 = *n2;
    *n2 = t;
}

void PercolateDown(int *arr, int i, int n)
{
    int child;
    int tmp;
    for(tmp = arr[i];LEFT_CHILD(i) < n;i = child){
        child = LEFT_CHILD(i); 
        if(child != n - 1 && (arr[child] < arr[child + 1])){
            child++; 
        }
        if(arr[child] > tmp){
            arr[i] = arr[child];
        }else{
            break; 
        }
    }
    arr[i] = tmp;
}


void HeapSort(int *arr, int n)
{
    int i;
    for(i = n / 2;i >= 0;i--){
        PercolateDown(arr, i, n); 
    } 
    for(i = n - 1;i > 0;i--){
        Swap(&arr[0], &arr[i]);
        PercolateDown(arr, 0, i);
    }
}
int main()
{
    int arr[6] = {2, 6, 4, 1, 7, 5};
    int i;
    HeapSort(arr, 6);
    for(i = 0;i < 6;i++){
        printf("%d\n", arr[i]); 
    }
}
