#include <stdio.h>
#include <stdlib.h>

typedef struct Bst Node;
struct Bst{
    int data;
    Node *left, *right;
};

void insert(Node **root, int val);
int search(Node *root, int val);
void preOrder(Node *root);

int main()
{
    Node *root = NULL;

    insert(&root, 8);
    insert(&root, 4);
    insert(&root, 15);
    insert(&root, 6);

    /* Searching */
    int result = search(root, 4);
    (result == 1) ? printf("SUCESS : NODE FOUND\n"):
                    printf("FAILED : NODE NOT FOUND\n");

    printf("OUTPUT : \n");
    preOrder(root);
}

void insert(Node **root, int val)
{
    Node *tmp = NULL;

    if(!(*root))
    {
        /* Creating a new node */
        tmp = (Node *)malloc(sizeof(*tmp));
        tmp->left = tmp->right = NULL;
        tmp->data = val;
        *root = tmp;

        return;
    }
    if(val < (*root)->data)
        insert(&(*root)->left, val);
    else if(val > (*root)->data)
        insert(&(*root)->right, val);
}

int search(Node *root, int val)
{
    if(!(root))
        exit(EXIT_FAILURE);
    if(val == root->data)
        return 1;
    else if(val < root->data)
        search(root->left, val);
    else
        search(root->right, val);
}

void deleteBST(Node *root)
{
    if(root)
    {
        deleteBST(root->left);
        deleteBST(root->right);
        free(root);
    }
    return;

}

void preOrder(Node *root)
{
    if(root)
    {
        printf("%d\n", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    return;
}