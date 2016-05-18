/*
题目：
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
*/

#include "stdio.h"
#include "stdlib.h"
//=====================二叉树操作API================
struct BinaryTreeNode{
    int value;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

typedef struct BinaryTreeNode *pBinaryTreeNode;

pBinaryTreeNode CreateBinaryNode(int value)
{
    pBinaryTreeNode pBTN = malloc(sizeof(struct BinaryTreeNode));
    pBTN->value = value;
    pBTN->left = NULL;
    pBTN->right = NULL;
    return pBTN;
}

void PrintTreeNode(pBinaryTreeNode pNode)
{
    if(pNode != NULL)
    {
        printf("value of this node is: %d\n", pNode->value);

        if(pNode->left != NULL)
            printf("value of its left child is: %d.\n", pNode->left->value);
        else
            printf("left child is null.\n");

        if(pNode->right != NULL)
            printf("value of its right child is: %d.\n", pNode->right->value);
        else
            printf("right child is null.\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}
void PrintTree(pBinaryTreeNode pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != NULL)
    {
        if(pRoot->left != NULL)
            PrintTree(pRoot->left);

        if(pRoot->right != NULL)
            PrintTree(pRoot->right);
    }
}
//=====================实现代码===================
pBinaryTreeNode ConstructCore(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder)
{
    //前序遍历序列的第一个数字是根节点的值
    int rootValue = startPreOrder[0]; 
    pBinaryTreeNode root = CreateBinaryNode(rootValue);
    //当前序序列只剩下一个数字时，该数字为叶子结点
    if(startPreOrder == endPreOrder){
        if((startInOrder == endInOrder) && (*startPreOrder == *startInOrder)){
           return root;  
        }else{
            printf("Invalid input.\n"); 
            exit(0);
        } 
    }
    //在中序遍历中找到根结点的值
    int *rootInOrder = startInOrder;
    while((rootInOrder <= endInOrder) && (*rootInOrder != rootValue)){
        rootInOrder++; 
    }
    //在中序遍历中找不到根节点的值
    if((rootInOrder == endInOrder) && (*rootInOrder != rootValue)){
        printf("Invalid input.\n"); 
    }

    //根节点左子树的长度
    int leftLength = rootInOrder - startInOrder;

    //得到左子树前序序列尾指针
    int *leftPreOrderEnd = startPreOrder + leftLength;

    //中序序列根结点左子树长度大于0
    if(leftLength > 0){
        //构建左子树
        root->left = ConstructCore(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1); 
    }
    //中序序列中根节点左边序列的长度小于前序序列的长度,所以存在右子树，且差值为右子树长度
    if(leftLength < endPreOrder - startPreOrder){
        //构建右子树
        root->right = ConstructCore(leftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder); 
    }
    return root;
}

pBinaryTreeNode Construct(int *preOrder, int *inOrder, int length)
{
    if(preOrder == NULL || inOrder == NULL || length < 0){
        return NULL; 
    }
    return ConstructCore(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}
//=========================测试代码=================
void Test(char* testName, int* preOrder, int* inOrder, int length)
{
    int i;
    pBinaryTreeNode root;
    if(testName != NULL){
        printf("%s begins:\n", testName); 
    }
    printf("The preOrder sequence is:");
    for(i = 0; i < length;i++){
        printf("%d ", preOrder[i]); 
    }
    printf("The inOrder sequence is:");
    for(i = 0; i < length;i++){
        printf("%d ", inOrder[i]); 
    }
    printf("\n");
    root = Construct(preOrder, inOrder, length);
    PrintTree(root);
}
// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[8] = {4, 7, 2, 1, 5, 3, 8, 6};

    Test("Test1", preorder, inorder, length);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[5] = {1, 2, 3, 4, 5};
    int inorder[5] = {5, 4, 3, 2, 1};

    Test("Test2", preorder, inorder, length);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[5] = {1, 2, 3, 4, 5};
    int inorder[5] = {1, 2, 3, 4, 5};

    Test("Test3", preorder, inorder, length);
}

// 树中只有一个结点
void Test4()
{
    const int length = 1;
    int preorder[1] = {1};
    int inorder[1] = {1};

    Test("Test4", preorder, inorder, length);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[7] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[7] = {4, 2, 5, 1, 6, 3, 7};

    Test("Test5", preorder, inorder, length);
}

// 输入空指针
void Test6()
{
    Test("Test6", NULL, NULL, 0);
}

// 输入的两个序列不匹配
void Test7()
{
    const int length = 7;
    int preorder[7] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[7] = {4, 2, 8, 1, 6, 3, 7};

    Test("Test7: for unmatched input", preorder, inorder, length);
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

