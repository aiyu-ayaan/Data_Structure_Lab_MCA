#include <stdio.h>
#include <stdlib.h>

#define print(p) printf(p)
#define scan(d) scanf("%d", &d)
#define empty_tree printf("\nTree is empty !!")

struct bNode
{
    struct bNode *left;
    int data;
    struct bNode *right;
} typedef bNode;

bNode *ROOT = NULL;

bNode *create_node(int);

bNode *insert(bNode *, bNode *);

void inorder(bNode *);

void main()
{

    bNode *node1 = create_node(1);
    bNode *node2 = create_node(2);
    bNode *node3 = create_node(3);
    bNode *node4 = create_node(4);
    bNode *node5 = create_node(5);

    ROOT = insert(ROOT, node3);
    ROOT = insert(ROOT, node2);
    ROOT = insert(ROOT, node1);
    ROOT = insert(ROOT, node4);
    ROOT = insert(ROOT, node5);

    if (ROOT == NULL)
        empty_tree;
    else
        inorder(&ROOT);
}

bNode *create_node(int ele)
{
    bNode *temp = (bNode *)malloc(sizeof(bNode *));
    temp->data = ele;
    temp->left = temp->right = NULL;
    return temp;
}

bNode *insert(bNode *ROOT, bNode *node)
{
    if (ROOT == NULL)
    {
        ROOT = node;
        return ROOT;
    }
    else
    {
        if (node->data < ROOT->data)
        {
            ROOT->left = insert(ROOT->left, node);
        }
        else
        {
            ROOT->right = insert(ROOT->right, node);
        }
    }
    return ROOT;
}

// Inorder traversal of tree
void inorder(bNode *ROOT)
{
    if (ROOT == NULL)
    {
        return;
    }
    inorder(ROOT->left);
    printf("%d ", ROOT->data);
    inorder(ROOT->right);
}
