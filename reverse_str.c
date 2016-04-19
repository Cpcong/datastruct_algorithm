#include "stdio.h"
#include "string.h"
int main()
{
    char str[20];
    int len;
    int left, right;
    char c;
    gets(str);
    len = strlen(str);
    left = 0;
    right = len - 1;
    while(left < right){
        c = str[left]; 
        str[left] = str[right];
        str[right] = c; 
        left++;
        right--;
    }
    printf("%s\n", str);
    return 0;
}
