#include "stdio.h"
#include "stdlib.h"

void Merge(int a[], int tmpArr[], int lPos, int rPos, int rEnd)
{
    int tPos = lPos;
    int lEnd = rPos - 1;
    int i;
    int len = rEnd - lPos + 1;

    while(1){
        if(a[lPos] < a[rPos]){
            tmpArr[tPos++] = a[lPos++]; 
        }else{
            tmpArr[tPos++] = a[rPos++]; 
        }
        if(lPos > lEnd || rPos > rEnd){
            break;
        }
    }
    while(lPos <= lEnd){
        tmpArr[tPos++] = a[lPos++];
    }
    while(rPos <= rEnd){
        tmpArr[tPos++] = a[rPos++];
    }
    for(i = len;i > 0;i--){
        a[rEnd] = tmpArr[rEnd];
        rEnd--;
    }
}

void MSort(int a[], int tmpArr[], int left, int right)
{
    int center;
    if(left >= right){
        return; 
    } 
    center = (left + right)/2;
    MSort(a, tmpArr, left, center);
    MSort(a, tmpArr, center + 1, right);
    Merge(a, tmpArr, left, center + 1, right);
}

void MergeSort(int a[], int n)
{
    int *tmpArr;
    tmpArr = malloc(sizeof(int) * n);
    if(tmpArr == NULL){
        printf("malloc tmpArr failed, out of space\n");
        exit(0);
    }
    MSort(a, tmpArr, 0, n -1);
}

int main()
{
    int i;
    int len;
    int a[] = {1,3, 5, 7, 2, 4, 6, 8, 12, 15, 25, 22, 11, 9, 0};
    len = sizeof(a)/sizeof(a[0]); 
    MergeSort(a, len);
    for(i = 0;i < len;i++){
        printf("%d ", a[i]);
    }

    return 0;
}
