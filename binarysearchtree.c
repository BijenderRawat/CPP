#include<stdlib.h>
#include<stdio.h>
struct binarytree {
int data;
binarytree * right, * left;
};
typedef struct binarytree node;
void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}
void preorder(node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}
void inorder(node * tree)
{
    if (tree)
    {
        inorder(tree->left);
        printf("%d\n",tree->data);
        inorder(tree->right);
    }
}
void postorder(node * tree)
{
    if (tree)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\n",tree->data);
    }
}
void deletetree(node * tree)
{
    if (tree)
    {
        deletetree(tree->left);
        deletetree(tree->right);
        free(tree);
    }
}
node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}
int main()
{
    node *root;
    node *tmp;
    root = NULL;
	int n, d;
	printf("how many nodes you want to insert\n");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &d);
		insert(&root, d);
	}
    printf("Pre Order Display\n");
    preorder(root);
    printf("In Order Display\n");
    inorder(root);
    printf("Post Order Display\n");
    postorder(root);
    tmp = search(&root, 4);
    if (tmp)
    {
        printf("Searched node = %d\n", tmp->data);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }
    deletetree(root);
	return 0;
}