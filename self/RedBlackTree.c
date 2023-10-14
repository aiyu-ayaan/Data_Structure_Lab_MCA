
#include <stdio.h>
#include <stdlib.h>

// Defining the colors of the nodes and messages to be displayed
#define RED 1
#define BLACK 0
#define welcome_message printf("\n\nWelcome to the Red-Black Tree Program.")
#define display_message printf("\n\nPress 1 to insert a node\nPress 2 to display a node\nPress 3 to search a node\nPress 4 to delete a node\nPress 5 to exit\nEnter your choice: ")

// Structure to represent each
// node in a red-black tree
struct node
{
    int d;          // data
    int c;          // RED, BLACK
    struct node *p; // parent
    struct node *r; // right-child
    struct node *l; // left child
} typedef node;

// global root for the entire tree
node *root = NULL;

/*This function creates a node for a red-black tree.It returns a pointer to the node that it creates,
with the node's data set to the value of the argument passed to the function. The pointer to the node's
parent, left child, and right child are all set to NULL.
The node's color is set to red, and the node's count is set to RED.
*/

node *create(int ele)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->r = NULL;
    temp->l = NULL;
    temp->p = NULL;
    temp->d = ele;
    temp->c = RED;
    return temp;
}

// function to perform BST insertion of a node
node *bst(struct node *trav,
          struct node *temp)
{
    // If the tree is empty,
    // return a new node
    if (trav == NULL)
        return temp;

    // Otherwise recur down the tree
    if (temp->d < trav->d)
    {
        trav->l = bst(trav->l, temp);
        trav->l->p = trav;
    }
    else if (temp->d > trav->d)
    {
        trav->r = bst(trav->r, temp);
        trav->r->p = trav;
    }

    // Return the (unchanged) node pointer
    return trav;
}

// Function performing right rotation
// of the passed node
void rightrotate(node *temp)
{
    node *left = temp->l;
    temp->l = left->r;
    if (temp->l)
        temp->l->p = temp;
    left->p = temp->p;
    if (!temp->p)
        root = left;
    else if (temp == temp->p->l)
        temp->p->l = left;
    else
        temp->p->r = left;
    left->r = temp;
    temp->p = left;
}

// Function performing left rotation
// of the passed node
void leftrotate(node *temp)
{
    node *right = temp->r;
    temp->r = right->l;
    if (temp->r)
        temp->r->p = temp;
    right->p = temp->p;
    if (!temp->p)
        root = right;
    else if (temp == temp->p->l)
        temp->p->l = right;
    else
        temp->p->r = right;
    right->l = temp;
    temp->p = right;
}

// This function fixes violations
// caused by BST insertion
void fixup(node *root, node *pt)
{
    node *parent_pt = NULL;
    node *grand_parent_pt = NULL;

    while ((pt != root) && (pt->c != BLACK) && (pt->p->c == RED))
    {
        parent_pt = pt->p;
        grand_parent_pt = pt->p->p;

        /* Case : A
            Parent of pt is left child
            of Grand-parent of
        pt */
        if (parent_pt == grand_parent_pt->l)
        {

            struct node *uncle_pt = grand_parent_pt->r;

            /* Case : RED
                The uncle of pt is also red
                Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->c == RED)
            {
                grand_parent_pt->c = RED;
                parent_pt->c = BLACK;
                uncle_pt->c = BLACK;
                pt = grand_parent_pt;
            }

            else
            {

                /* Case : 2
                    pt is right child of its parent
                    Left-rotation required */
                if (pt == parent_pt->r)
                {
                    leftrotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->p;
                }

                /* Case : 3
                    pt is left child of its parent
                    Right-rotation required */
                rightrotate(grand_parent_pt);
                int t = parent_pt->c;
                parent_pt->c = grand_parent_pt->c;
                grand_parent_pt->c = t;
                pt = parent_pt;
            }
        }

        /* Case : B
            Parent of pt is right
            child of Grand-parent of
        pt */
        else
        {
            struct node *uncle_pt = grand_parent_pt->l;

            /* Case : RED
                The uncle of pt is also red
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->c == RED))
            {
                grand_parent_pt->c = RED;
                parent_pt->c = BLACK;
                uncle_pt->c = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                /* Case : 2
                pt is left child of its parent
                Right-rotation required */
                if (pt == parent_pt->l)
                {
                    rightrotate(parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->p;
                }

                /* Case : 3
                    pt is right child of its parent
                    Left-rotation required */
                leftrotate(grand_parent_pt);
                int t = parent_pt->c;
                parent_pt->c = grand_parent_pt->c;
                grand_parent_pt->c = t;
                pt = parent_pt;
            }
        }
    }
}

// Function to print inorder traversal
// of the fixated tree
void inorder(node *trav)
{
    if (trav == NULL)
        return;
    inorder(trav->l);
    printf("%d ", trav->d);
    inorder(trav->r);
}

void search(node *trav, int ele)
{
    if (trav == NULL)
    {
        printf("\nElement not found\n");
        return;
    }
    if (trav->d == ele)
    {
        printf("\nElement found\n");
        return;
    }
    if (trav->d > ele)
        search(trav->l, ele);
    else
        search(trav->r, ele);
}

// this function finds the minimum node in a binary search tree.
// it uses recursion to traverse the left side of the tree until it reaches the end
// and then returns the last node that it visited.

node *findMinNode(node *x)
{
    while (x->l != NULL)
        x = x->l;
    return x;
}

// Function to delete a node from the Red-Black Tree
node *deleteNode(node *root, int key)
{
    if (root == NULL)
        return root;

    // Perform a standard BST delete
    if (key < root->d)
        root->l = deleteNode(root->l, key);
    else if (key > root->d)
        root->r = deleteNode(root->r, key);
    else
    {
        // Node with only one child or no child
        if (root->l == NULL)
        {
            struct node *temp = root->r;
            free(root);
            return temp;
        }
        else if (root->r == NULL)
        {
            struct node *temp = root->l;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct node *temp = findMinNode(root->r);

        // Copy the inorder successor's content to this node
        root->d = temp->d;

        // Delete the inorder successor
        root->r = deleteNode(root->r, temp->d);
    }

    // Perform fixup after deletion
    if (root != NULL)
    {
        fixup(root, root);
    }

    return root;
}

// driver code
void main()
{
    welcome_message;
    while (1)
    {
        display_message;
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int ele;
            printf("\nEnter the element to be inserted:");
            scanf("%d", &ele);
            node *temp = create(ele);
            root = bst(root, temp);
            fixup(root, temp);
            root->c = BLACK;
            printf("\nElement inserted successfully\n");
            break;
        }
        case 2:
        {
            printf("\nInorder traversal of the tree is: ");
            inorder(root);
            break;
        }
        case 3:
        {
            int ele;
            printf("\nEnter the element to be searched:");
            scanf("%d", &ele);
            search(root, ele);
            break;
        }
        case 4:
        {
            int ele;
            printf("\nEnter the element to be deleted:");
            scanf("%d", &ele);
            root = deleteNode(root, ele);
            printf("\nElement deleted successfully\n");
            break;
        }
        case 5:
        {
            exit(0);
        }
        default:
        {
            printf("\nInvalid choice\n");
            break;
        }
        }
    }
}
