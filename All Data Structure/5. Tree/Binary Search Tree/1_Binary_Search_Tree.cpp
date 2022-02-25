#include <iostream>
#include<cstdlib>
using namespace std;

typedef struct tree_node
{
    int data;
    tree_node *left;
    tree_node *right;
} bst;

bst *Insertion(bst *root, int data)
{
    if (root == NULL)
    {

        root = new bst();
        if (root == NULL)
        {
            cout << "Memory Eroor\n";
        }
        else
        {
            root->data = data;
            root->left = root->right = NULL;
        }
    }
    else
    {
        if (root->data > data)
        {
            root->left = Insertion(root->left, data);
        }
        if (root->data < data)
        {
            root->right = Insertion(root->right, data);
        }
        if(root->data == data)
        {
            cout<<"It is already present\n";
            
        }
    }
    return root;
}
void Inorder_Traversal(bst *root)
{
    if (root)
    {
        Inorder_Traversal(root->left);
        cout << root->data << " ";
        Inorder_Traversal(root->right);
    }
}
bst* Find_min(bst *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    else if (root->left == NULL)
    {
        return root;
    }
    else
        Find_min(root->left);
}
bst *Find_max(bst *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->right == NULL)
    {
        return root;
    }
    else return Find_max(root->right);
}
bst *delete_node(bst *root, int data)
{
    bst *temp;
    if (root == NULL)
    {
        cout << "No data is available\n";
    }
    else if(root->right == NULL && root->left == NULL)
    {
        free(root);
        return NULL;
    }

    else if (root->data > data)
    {
        root->left = delete_node(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = delete_node(root->right, data);
    }
    else
    {       
        temp = Find_max(root->left);
        root->data = temp->data;
        root->left = delete_node(root->left, root->data);
    }
    
    
}
int Search_in_Binary_tree(bst *root, int data)
{
    if(root == NULL)
        return 0;
    
    else if(data > root->data)
        Search_in_Binary_tree(root->right,data);
    else if(data < root->data)
        Search_in_Binary_tree(root->left,data);
    else
    return 1;


}
// int main()
// {
//     bst *root = NULL;

//     root = Insertion(root, 24);
//     root = Insertion(root, 35);
//     root = Insertion(root, 12);

//     // Inorder_Traversal(root);
//     // root = delete_node(root, 24);
//     // Inorder_Traversal(root);
//     // Find_min(root);
//     // Find_max(root);
//     if(Search_in_Binary_tree(root,3))
//     cout<<"found\n";
//     else
//     cout<<"not found\n";

//     return 0;
// }