#include "stdio.h"
#include "stdlib.h"

int arr[] = {2, 5, 7, 1, 3, 9, 4, 6, 0, 8};
int len = sizeof(arr)/sizeof(arr[0]);

void sort(int a[], int len);
void FindKBigValue(int a[], int k);
int main(int argc, char **argv)
{
    int i;
    int k = atoi(argv[1]);
    /*
    sort(arr, len);
    printf("第%d大:%d\n", k, arr[k - 1]);
    */

    FindKBigValue(arr, k);

    printf("%d", arr[k - 1]);
    return 0;
}

void sort(int a[], int len)
{
    int i, j;
    int t;
    for(i = 0;i < len;i++){
        for(j = 0;j < (len - i - 1); j++){
            if(a[j] < a[j + 1]){
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}
//找出數組第k大的值
/*
先將前k個元素讀入數組並對其排序，接着將剩下的數組再逐個讀入，
小於第k個元素則忽略，否則放在數組中正確位置上
*/
void FindKBigValue(int a[], int k)
{
    int i, j, l;
     sort(a, k);
     for(i = k;i < len;i++){
         if(a[i] <= a[k - 1]){
            continue;
         }else{
             for(j = 0;j < k;j++){
                 if(a[i] > a[j]){
                     for(l = k - 1;l >= j;l--){
                        a[l] = a[l - 1];
                     }
                     a[j] = a[i];
                     break;
                 }
             }
         }
     }

}
