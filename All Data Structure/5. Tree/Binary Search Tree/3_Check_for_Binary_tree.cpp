#include<iostream>
#include"1_Binary_Search_Tree.cpp"
#include<limits.h>
using namespace std;

int Check_for_binary_tree(bst *root)
{
    if(root == NULL)
        return 1;
    
    if(root->left != NULL && Find_max(root->left)->data >= root->data)
        return 0;
    
    if(root->right != NULL && Find_min(root->right)->data <= root->data)
        return 0;
    
    if(!Check_for_binary_tree(root->left) || !Check_for_binary_tree(root->right))
        return 0;
    
        return 1;
}
int isBST(bst *root)
{
    static bst *prev = NULL;

    if(root!=NULL)
    {
        if(!isBST(root->left))
        return 0;

        if(prev != NULL && prev->data >= root->data)
            return 0;
        
        prev = root;

        return isBST(root->right);
    }
    else
    return 1;
}
//  Best checker for binary tree

int check_BSt(bst *root, int min, int max)
{
    if(root==NULL)
        return 1;

    return (root->data > min && root->data < max && check_BSt(root->left,min,max) && check_BSt(
            root->right,min,max));
}
int main()
{
    bst *root = NULL;
    root = Insertion(root,12);
    root = Insertion(root,22);
    root = Insertion(root,0);
    root = Insertion(root,12);
    root = Insertion(root,35);
    root = Insertion(root,34);
    Inorder_Traversal(root);

    if(Check_for_binary_tree(root))
    {
        cout<<"It is a binary search tree\n";
    }
    else
    {
        cout<<"It is not a binary search tree\n";
    }
    if(isBST(root))
    {
        cout<<"it is\n";
    }
    else
    {
        cout<<"not";
    }

    cout<<check_BSt(root,INT_MIN, INT_MAX);
    return 0;
}