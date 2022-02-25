#include<iostream>
using namespace std;

typedef struct avltree
{
    int value;
    struct avltree *left;
    struct avltree *right;
    int height;
} tree;

tree *create_a_node(int data)
{
    tree *root = new tree();
    if(!root)
    {
        cout<<"Memory Error\n";
    }
    root->value = data;
    root->left = root->right = NULL;
    root->height = 1;
}

int height(tree *node)
{
    if(!node)
    return 0;
    return node->height;
}
int balancefactor(tree *node)
{
    if(!node)
    return 0;

    return (height(node->left) - height(node->right));
}
int max(int a, int b)
{
    return ((a>b) ? a : b);
}

tree *rotate_left(tree *x)
{
    tree* y = x->left;
    tree *T = y->right;

    y->right = x;
    x->left = T;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(y->right)) + 1;
    return y;
}
tree *rotate_right(tree *y)
{
    tree *x = y->right;
    tree *T = x->left;

    x->left = y;
    y->right = T;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(y->right)) + 1;
    return x;
}

tree *Insertion(tree *root, int val)
{
    if(root == NULL)
    {
        return create_a_node(val);
    }
    else if(val < root->value)
    {
        root->left = Insertion(root->left,val);
    }
    else if(val > root->value)
        root->right = Insertion(root->right,val);
        return root;
    
    root->height = 1 + max(height(root->left), height(root->right));
    int bf = balancefactor(root);
    if(bf > 1 && val < root->left->value)
    {
        rotate_right(root);
    }
    if(bf < -1 && val > root->right->value)
    {
        rotate_left(root);
    }
    if(bf > 1 && val > root->left->value)
    {
        root->left = rotate_left(root->left);
        rotate_right(root);
    }
    if(bf < -1 && val < root->right->value)
    {
        root->right = rotate_right(root->right);
        rotate_left(root);
    }
    return root;
}
void Inorder(tree *root)
{
    if(root != NULL)
    {
        Inorder(root->left);
        cout<<root->value<<" "<<root->height<<endl;
        Inorder(root->right);
    }
}
int main()
{
    tree *root = NULL;

    root = Insertion(root,45);
    root = Insertion(root,43);
    root = Insertion(root,20);
    root = Insertion(root,23);
    root = Insertion(root,12);
    root = Insertion(root,46);
    Inorder(root);
    return 0;
}