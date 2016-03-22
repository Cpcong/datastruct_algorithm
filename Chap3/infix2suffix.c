//中缀到后缀的转换，支持'*', '+', '('和')'
//Stack存放操作符

/*处理过程
 *读到一个操作数时，立即把它放到输出中
 *如果见到一个右括号，那么就将Stack元素弹出,直到遇到相应的'('但
这个左括号只被弹出，并不输出
 *如果见到任何其他符号'+', '*'和'(',那么从栈中弹出栈元素直到发现优先级更低
 的元素为止，例外：除非在处理')'时，否则绝不从栈中移走'('
 */
#include "stdio.h"
#include "stack.h"
#include "stdlib.h"

int GetPriority(char c);
void HandleOperator(char c, Stack s);

int main()
{
    size_t len;
    int i;
    char c;
    char recStr[20];
    Stack s = CreateStack();
    fgets(recStr, 20, stdin);
    len = strlen(recStr);

    for(i = 0;i < len -1;i++){
        switch(recStr[i]){
            case '+' :
                HandleOperator(recStr[i], s);
                break;
            case '*' :
                HandleOperator(recStr[i], s);
                break;
            case '(' :
                HandleOperator(recStr[i], s);
                break;
            case ')' :
                while((c = TopAndPop(s)) != '('){
                    putchar(c);
                }
                break;
            default :
                putchar(recStr[i]);
                break;
        }
    }
    while(!IsEmpty(s)){
        putchar(TopAndPop(s));
    }

    return 0;
}

int GetPriority(char c)
{
    int priority = 0;
    switch(c){
        case '+' :
            priority = 1;
            break;
        case '*' :
            priority = 2;
            break;
        case '(' :
            priority = 3;
            break;
        default :
            printf("operator error");
            exit(0);
            break;
    }
    return priority;
}

void HandleOperator(char c, Stack s)
{
    char t;
    for(;;){
        if(IsEmpty(s)){
            Push(c, s);
            break;
        }else if((t = Top(s)) != '('  && GetPriority(c) <= GetPriority(t)){
            putchar(TopAndPop(s));
        }else{
            Push(c, s);
            break;
        }
    }
}

