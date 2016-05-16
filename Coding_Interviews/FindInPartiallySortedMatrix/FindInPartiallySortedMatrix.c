/*
题目：
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从
上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整
数，判断数组中是否含有该整数
*/
#include "stdio.h"
#include "stdlib.h"
int Find(int* matrix, int rows, int columns, int number)
{
    int row = 0;
    int column = columns - 1;
    int isFound = 0;

    if(matrix == NULL){
        return 0; 
    }
    while((row < rows) && (column >= 0)){
        if(matrix[row * columns + column] > number){
            --column; 
        }else if(matrix[row * columns + column] < number){
            ++row; 
        }else{
            isFound = 1;  
            break;
        }
    }
    return isFound;
}

//=========测试代码=========

void Test(char* testName, int* matrix, int rows, int columns, int number, int expected)
{
    if(testName != NULL){
        printf("%s begins:", testName);  
    }
    int result = Find(matrix, rows, columns, number);
    if(result != expected){
        printf("Failed.\n"); 
    }else{
        printf("Pass.\n"); 
    }
}



//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test1", (int*)matrix, 4, 4, 7, 1);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test2", (int*)matrix, 4, 4, 5, 0);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最小的数字
void Test3()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test3", (int*)matrix, 4, 4, 1, 1);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最大的数字
void Test4()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test4", (int*)matrix, 4, 4, 15, 1);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最小的数字还小
void Test5()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test5", (int*)matrix, 4, 4, 0, 0);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最大的数字还大
void Test6()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test6", (int*)matrix, 4, 4, 16, 0);
}

// 鲁棒性测试，输入空指针
void Test7()
{
    Test("Test7", NULL, 0, 0, 16, 0);
}



int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    return 0; 
}


