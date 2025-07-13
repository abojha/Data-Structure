#include<iostream>
using namespace std;

typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} tree;

tree *create_a_node(int key)
{
    tree *root = new tree();
    root->data = key;
    root->right = NULL;
    root->left = NULL;
    return root;
}
void preorder(tree *root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    tree *r;
    tree *c1;
    tree *c2;

    r = create_a_node(22);
    c1 = create_a_node(23);
    c2 = create_a_node(35);
    
    r->left = c1;
    r->right = c2;

    preorder(r);
    return 0;
}