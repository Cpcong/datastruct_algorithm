/*
题目：
一只青蛙一次可以跳上1级台阶，也可以跳上2级.求该青蛙跳上一个n级的台阶总共有多少种跳法
*/

/*
解决思路：
我们把n级台阶时的跳法看成是n的函数，记为f(n).
当n > 2时，第一次跳的时候就有两种不同的选择：一是跳1级，此时跳法数目等于后面剩下
的n - 1级台阶的跳法数目，即为f(n - 1);另外一种选择是第一次跳2级，此时跳法数目等于
后面剩下的n - 2级台阶的跳法数目，即为f(n - 2),因此n级台阶的不同跳法总数为
f(n) = f(n - 1) + f(n - 2),实际上就是斐波那契数列了.
*/

#include "stdio.h"
int FrogJumpStep(int n)
{
    int i;
    int last = 1;
    int current = 2;
    int tmp;
    if(n == 1){
        return 1; 
    }
    if(n == 2){
        return 2; 
    }
    for(i = 3;i <= n;i++){
        tmp = last + current; 
        last = current;
        current = tmp;
    }
    return current;
}

int main()
{
    int result = FrogJumpStep(3);
    printf("%d\n", result);
    result = FrogJumpStep(4);
    printf("%d\n", result);
    result = FrogJumpStep(5);
    printf("%d\n", result);
    result = FrogJumpStep(3);
    return 0;
}
