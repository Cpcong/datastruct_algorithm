//有两个栈，其中一个栈为空，反转另一个栈中的元素
#include "stdio.h"
#include "stack.h"

void ReverseStack(Stack s)
{
    Stack s2 = CreateStack();
    int tmp;
    int i;
    int len = Size(s);
    for(i = 0;i < len - 1;i++){
        tmp = TopAndPop(s);
        while(Size(s) > i){
            Push(TopAndPop(s), s2); 
        }   
        Push(tmp, s);
        while(!IsEmpty(s2)){
            Push(TopAndPop(s2), s); 
        }
    }

}

int main()
{
    int i1 = 1, i2 = 2, i3 = 3, i4 = 4;
    Stack s = CreateStack();
    Push(i1, s);
    Push(i2, s);
    Push(i3, s);
    Push(i4, s);
    ReverseStack(s);
    while(!IsEmpty(s)){
        printf("%d\n", TopAndPop(s)); 
    } 
    return 0;
}
