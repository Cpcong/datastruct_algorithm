#include "stdio.h"
#include "math.h"
#include "stdlib.h"

//shell increment(1, 2, 4, ..)
/*
void ShellSort(int a[], int n)
{
    int increment;
    int i, j;
    int t;
    for(increment = n/2;increment > 0;increment /= 2){
        for(i = increment;i < n;i++){
            t = a[i]; 
            for(j = i;j >= increment;j -= increment){
                if(t < a[j - increment]){
                    a[j] = a[j - increment]; 
                }else{
                    break;
                }
            }
            a[j] = t;
        }
    }    
    
}
*/

static int InitIncSeqLen(n)
{
    int i = 1;;
    int increment = 2;
    while(increment - 1 < sqrt((double)n)){
        i++;
        increment *= 2;
    }
    return i - 1;
}
static void SetIncrementArr(int a[], int n)
{
    int i;
    int increment = 1;
    for(i = 0;i < n;i++){
        increment *= 2;
        a[i] = increment - 1;
    } 
}
//Hibbard increment(1, 3, 7.... 2^k -1)
//limit: increment < sqrt(n)
void ShellSort(int a[], int n)
{
    int increment;
    int len;
    int i, j;
    int t;
    int *incrementArr;
    len = InitIncSeqLen(n);
    incrementArr = malloc(sizeof(int) * len);
    SetIncrementArr(incrementArr, len); 
    for(len = len -1;len >= 0;len--){
        increment = incrementArr[len];
        for(i = increment;i < n;i++){
            t = a[i]; 
            for(j = i;j >= increment;j -= increment){
                if(t < a[j - increment]){
                    a[j] = a[j - increment]; 
                }else{
                    break;
                }
            }
            a[j] = t;
        }
    }
}

int main()
{
    int i;
    int a[100];
    int len = sizeof(a)/sizeof(a[0]);
    for(i = 0;i < 100;i++){
        a[i] = rand()%100;
    }
    ShellSort(a, len);
    for(i = 0;i < len;i++){
        printf("%d ", a[i]);
    }
}
