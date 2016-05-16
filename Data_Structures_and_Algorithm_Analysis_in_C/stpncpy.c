#include "stdio.h"

char * stpncpy(char *dest, const char *src, size_t n)
{
    int i;
    for(i = 0;i < n;i++){
        if(*src != '\0'){
            dest[i] = *src;
            src++;
        }else{
            break; 
        }
    }
    for(;i < n;i++){
        dest[i] = '\0'; 
    }
    return dest;
}

int main()
{
    char *src = "hello";
    char dest[20];
    printf("%s\n", stpncpy(dest, src, 7));
}
