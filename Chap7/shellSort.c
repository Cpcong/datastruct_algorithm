#include "stdio.h"

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

int main()
{
    int a[] = {2, 4, 5, 3, 6, 1, 8, 9, 13, 11, 12};
    int len = sizeof(a)/sizeof(a[0]);
    int i;
    ShellSort(a, len);
    for(i = 0;i < len;i++){
        printf("%d ", a[i]);
    }
}
