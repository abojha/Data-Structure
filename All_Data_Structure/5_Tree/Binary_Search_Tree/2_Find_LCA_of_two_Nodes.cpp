#include<iostream>
#include"1_Binary_Search_Tree.cpp"
using namespace std;

bst *create_a_node(int data)
{
    bst *node = new bst();
    node->data = data;
    node->left = node->right = NULL;
}
bst * LCA(bst *root, bst* a, bst *b)
{
    while(1)
    {
        if((root->data < a->data && root->data > b->data) || (root->data > a->data
            && root->data < b->data))
        return root;

        if(a->data < root->data)
        {
            root = root->left;
        }
        else
        root = root->right;
    }
}
int main()
{
    bst *root = NULL;
    bst *c1 = NULL;
    bst *c2 = NULL;
    root = create_a_node(12);
    c1 = create_a_node(24);
    c2 = create_a_node(35);

    c1->left = root;
    c1->right = c2;

    cout<<LCA(c1,root,c2)->data<<endl;

    
    return 0;
}