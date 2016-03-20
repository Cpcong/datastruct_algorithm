//基数排序
#include "stdio.h"

#define BASE 10
#define MAX 20

void RadixSort(int a[], int n);


int main()
{
    int n, i;
    int a[MAX];
    printf("请输入数目\n");
    scanf("%d", &n);

    n = n > MAX ? MAX : n;

    printf("按顺序输入数据\n");
    for(i = 0;i < n;i++){
         scanf("%d", &a[i]);
    }
    RadixSort(a, n);
    for(i = 0;i < n;i++){
        printf("%d ", a[i]);
    }
    return 0;
}


void RadixSort(int a[], int n)
{
    //数组b存放的是每次排序完的数据
    int b[MAX], max, exp = 1;;
    int i;
    max = a[0];

    for(i = 1;i < n;i++){
        if(max < a[i]){
            max = a[i];
        }
    }

    while(max/exp > 0){
        int bucket[BASE] = {0};
        for(i = 0;i < n;i++){
            bucket[a[i] / exp % BASE]++;
        }
        for(i = 1;i < BASE;i++){
            //每个桶中的最后一个数据在数组b中的位置
            bucket[i] = bucket[i] + bucket[i - 1];
        }

        for(i = n - 1;i >= 0;i--){
            b[--(bucket[a[i] / exp % BASE])] = a[i];
        }

        for(i = 0;i < n;i++){
            a[i] = b[i];
        }
        exp *= BASE;
    }
}
