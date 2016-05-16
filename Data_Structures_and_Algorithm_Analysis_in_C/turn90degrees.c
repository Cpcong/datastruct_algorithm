//一个n×n的二维数组，原地(不申请其他空间)顺时针旋转90度
#include "stdio.h"
#define N 4 
void Swap(int *num1, int *num2)
{
    int t;
    t = *num1;
    *num1 = *num2;
    *num2 = t;
}
//按主对角线翻转，在按垂直中线翻转
void Turn90Degrees(int (*arr)[N], int n)
{
    int i, j;
    for(i = 0;i < n;i++){
        for(j = i + 1; j < n;j++){
            Swap(&arr[i][j], &arr[j][i]); 
        } 
    }
    for(i = 0;i < N/2;i++){
        for(j = 0;j < N;j++){
            Swap(&arr[j][i], &arr[j][N - 1 - i]); 
        } 
    }
}
int main()
{
    int i, j;
    int a[N][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Turn90Degrees(a, N);
    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
