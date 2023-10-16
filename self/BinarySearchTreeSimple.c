#include <stdio.h>
#include <stdlib.h>

struct Tree
{
    struct Tree *left;
    int data;
    struct Tree *right;
} typedef Tree;

Tree *Root = NULL;

Tree *create_node(int ele);

Tree *insert(Tree *Root, Tree *node);

Tree *inOrderPredecessor(Tree *Root);

void inorder(Tree *Root);
void preorder(Tree *Root);
void postorder(Tree *Root);
int totalLeaf(Tree *Root);

Tree *deleteNode(Tree *Root, int ele)
{
    if (Root == NULL)
    {
        printf("Element is not present in the tree");
        return Root;
    }

    if (Root->data > ele)
    {
        Root->left = deleteNode(Root->left, ele);
    }
    else if (Root->data < ele)
    {
        Root->right = deleteNode(Root->right, ele);
    }
    else
    {
        // Case 1: Leaf node (no children)
        if (Root->left == NULL && Root->right == NULL)
        {
            free(Root);
            Root = NULL;
        }
        // Case 2: Node with only one child
        else if (Root->left == NULL)
        {
            Tree *temp = Root;
            Root = Root->right;
            free(temp);
        }
        else if (Root->right == NULL)
        {
            Tree *temp = Root;
            Root = Root->left;
            free(temp);
        }
        // Case 3: Node with two children
        else
        {
            // Find the in-order successor (or predecessor) to replace this node
            Tree *temp = inOrderPredecessor(Root->left); // You need to implement this function.
            Root->data = temp->data;
            // Delete the in-order successor node
            Root->right = deleteNode(Root->right, temp->data);
        }
    }

    return Root;
}

void main()
{
    Root = insert(Root, create_node(25));
    Root = insert(Root, create_node(15));
    Root = insert(Root, create_node(40));
    Root = insert(Root, create_node(10));
    Root = insert(Root, create_node(18));
    Root = insert(Root, create_node(35));
    Root = insert(Root, create_node(35));
    Root = insert(Root, create_node(45));
    Root = insert(Root, create_node(5));
    Root = insert(Root, create_node(19));
    Root = insert(Root, create_node(20));
    Root = insert(Root, create_node(44));
    Root = insert(Root, create_node(49));
    deleteNode(Root, 5);

    if (Root == NULL)
        printf("Tree is empty !!");
    else
    {
        inorder(Root);
        // printf("\n");
        // preorder(Root);
        // printf("\n");
        // postorder(Root);
        // printf("\n");
        // printf("Total leaf nodes are : %d", totalLeaf(Root));
        // printf("\n");
        // int inorder = inOrderPredecessor(Root->left)->data;
        // printf("Inorder predecessor of %d", inorder);
    }
}

Tree *create_node(int ele)
{
    Tree *temp = (Tree *)malloc(sizeof(Tree));
    temp->data = ele;
    temp->left = temp->right = NULL;
}

Tree *insert(Tree *Root, Tree *node)
{
    if (Root == NULL) // if tree is empty
        Root = node;

    if (Root->data > node->data) // if root is greater than node
        Root->left = insert(Root->left, node);
    if (Root->data < node->data) // if root is less than node
        Root->right = insert(Root->right, node);
    return Root;
}
void inorder(Tree *Root)
{
    if (Root == NULL)
        return;
    inorder(Root->left);
    printf("%d \t", Root->data);
    inorder(Root->right);
}

void preorder(Tree *Root)
{
    if (Root == NULL)
        return;
    printf("%d \t", Root->data);
    preorder(Root->left);
    preorder(Root->right);
}

void postorder(Tree *Root)
{
    if (Root == NULL)
        return;
    postorder(Root->left);
    postorder(Root->right);
    printf("%d \t", Root->data);
}

int totalLeaf(Tree *Root)
{
    if (Root == NULL)
        return 0;
    if (Root->left == NULL && Root->right == NULL)
        return 1;
    return totalLeaf(Root->left) + totalLeaf(Root->right);
}

Tree *inOrderPredecessor(Tree *Root)
{
    Tree *temp = Root;
    while (temp && temp->right != NULL)
        temp = temp->right;
    return temp;
}