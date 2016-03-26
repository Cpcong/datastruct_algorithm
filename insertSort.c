#include "stdio.h"

//not a good solution
/*
void InsertSort(int a[], int n)
{
    int i, j;
    int t;
    for(i = 1;i < n;i++){
        for(j = i;j > 0;j--){
            if(a[j] < a[j - 1]){
                t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
            }else{
                break;
            }
        }
    }    
}
*/

//good solution
void InsertSort(int a[], int n)
{
    int i, j;
    int t;
    for(i = 1;i < n;i++){
        t = a[i];
        //error, when t < a[1 -1] is true, a[1] = a[0], but the a[0] = t is not work
        /*
        for(j = i;j > 0;j--){
            if(t < a[j - 1]){
                a[j] = a[j - 1];
            }else{
                a[j] = t; 
                break;
            }
        }
        */
        for(j = i;j > 0;j--){
            if(t < a[j - 1]){
                a[j] = a[j -1];
            }else{
                break;
            }
        }
        a[j] = t;
    }
}


int main()
{
    int a[] = {2, 4, 5, 3, 6, 1, 8}; 
    int len = sizeof(a)/sizeof(a[0]);
    int i;
    InsertSort(a, len); 
    for(i = 0;i < len;i++){
        printf("%d ", a[i]); 
    }
}
