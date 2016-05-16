/**
* 后缀表达式构造表达式树
* 我们一次一个符号地读入表达式，如果符号是操作数，我们就建立一个单结点并将它
的指针推入栈中，如果符号是操作符，那么我们就从栈中弹出指向两棵树T1和T2的那两个
指针并形成一棵新的树,该树的根就是操作符,它的左，右儿子分别指向T1， T2，并将新生成的树的指针入栈 
* 
*/
#include "stdio.h"
#include "stdlib.h"
#include "stack.h"

typedef struct TreeNode *pTreeNode;
typedef pTreeNode Tree;

struct TreeNode{
    char c;
    Tree left;
    Tree right; 
};

pTreeNode CreateTreeNode(char c)
{
    pTreeNode pTN;
    pTN = malloc(sizeof(struct TreeNode)); 
    if(pTN == NULL){
        printf("CreateTreeNode failed, out of space\n");
        exit(0);
    }
    pTN->c = c;
    pTN->left = NULL;
    pTN->right = NULL;
    return pTN;
}

//中序遍历
void InOrderTraversal(Tree tree)
{
    if(tree == NULL){
        return ;
    }
    InOrderTraversal(tree->left);
    printf("%c ", tree->c);//打印出来的是中序遍历的逆序
    InOrderTraversal(tree->right);
}
int main()
{
    int i, n;
    Tree tree;
    pTreeNode pTN, pTN1, pTN2;
    char exp[100];
    Stack s = CreateStack();
    gets(exp); 
    n = strlen(exp); 
    for(i = 0;i < n;i++){
        switch(exp[i]){
            case '+' : 
            case '*' :
                pTN1 = TopAndPop(s); 
                pTN2 = TopAndPop(s);
                pTN = CreateTreeNode(exp[i]); 
                pTN->left = pTN1;
                pTN->right = pTN2;
                Push(pTN, s);
                break;
            default :
                pTN = CreateTreeNode(exp[i]);
                Push(pTN, s);
                break;
        }
    }
    tree = TopAndPop(s);
    InOrderTraversal(tree);
    return 0;
}
