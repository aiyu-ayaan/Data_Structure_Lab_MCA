/**
 * @author aiyu
 * @brief Program for the creation of binary tree, provide insertion & deletion in c.
 * Program for pre-order, post-order, and in-order binary search tree (BST) traversals.
 * Program to count the leaves of BST.
 */

#include <stdio.h>
#include <stdlib.h>

struct tNode
{
    struct tNode *left;
    int data;
    struct tNode *right;
} typedef tNode;

tNode *Root = NULL;

tNode *createNode(int ele)
{
    tNode *newNode = (tNode *)malloc(sizeof(tNode));
    newNode->data = ele;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

tNode *insertNode(tNode *Root, tNode *newNode)
{
    if (Root == NULL)
    {
        Root = newNode;
        return Root;
    }
    if (newNode->data < Root->data)
        Root->left = insertNode(Root->left, newNode);
    else
        Root->right = insertNode(Root->right, newNode);
    return Root;
}

tNode *inorder_predecessor(tNode *Root)
{
    tNode *temp = Root->left;
    while (temp->right != NULL)
        temp = temp->right;
    return temp;
}

tNode *deleteNode(tNode *Root, int ele)
{
    if (Root == NULL)
    {
        printf("Element not found\n");
        return Root;
    }
    if (ele < Root->data)
        Root->left = deleteNode(Root->left, ele);
    else if (ele > Root->data)
        Root->right = deleteNode(Root->right, ele);
    else
    {
        if (Root->left == NULL && Root->right == NULL)
        {
            free(Root);
            Root = NULL;
        }
        else if (Root->left == NULL)
        {
            tNode *temp = Root;
            Root = Root->right;
            free(temp);
        }
        else if (Root->right == NULL)
        {
            tNode *temp = Root;
            Root = Root->left;
            free(temp);
        }
        else
        {
            tNode *temp = inorder_predecessor(Root);
            Root->data = temp->data;
            Root->left = deleteNode(Root->left, temp->data);
        }
    }
    return Root;
}

void inorder(tNode *Root)
{
    if (Root == NULL)
        return;
    inorder(Root->left);
    printf("%d \t", Root->data);
    inorder(Root->right);
}

void preorder(tNode *Root)
{
    if (Root == NULL)
        return;
    printf("%d \t", Root->data);
    preorder(Root->left);
    preorder(Root->right);
}

void postorder(tNode *Root)
{
    if (Root == NULL)
        return;
    postorder(Root->left);
    postorder(Root->right);
    printf("%d \t", Root->data);
}

int countLeap(tNode *Root)
{
    if (Root == NULL)
        return 0;
    if (Root->left == NULL && Root->right == NULL)
        return 1;
    return countLeap(Root->left) + countLeap(Root->right);
}

void main()
{
    Root = insertNode(Root, createNode(5));
    Root = insertNode(Root, createNode(3));
    Root = insertNode(Root, createNode(7));
    Root = insertNode(Root, createNode(2));
    Root = insertNode(Root, createNode(4));
    Root = insertNode(Root, createNode(6));
    Root = insertNode(Root, createNode(8));
    inorder(Root);
    printf("\n");
    Root = deleteNode(Root, 5);
    inorder(Root);
    printf("\n");
    preorder(Root);
    printf("\n");
    postorder(Root);
    printf("\n");
    printf("Number of leaves in the BST: %d\n", countLeap(Root));
}
