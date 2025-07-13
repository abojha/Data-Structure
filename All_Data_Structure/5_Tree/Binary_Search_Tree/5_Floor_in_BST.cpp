#include<iostream>
#include"1_Binary_Search_Tree.cpp"
#include<limits.h>
using namespace std;


int  FloorInBST(bst *root,int data)
{
   if(root == NULL)
    return INT_MAX;

     if(root->data == data)
   return root->data;

   if(root->data > data)
   {
       return FloorInBST(root->left,data);
   }
   
   int floor = FloorInBST(root->right, data);
   return (floor <= data) ? floor :root->data;

                                   
}
int ceil(bst *root, int value)
{
    if(root == NULL)
    return INT_MIN;

    if(root->data < value)
    {
        return ceil(root->right,value);
    }
    int c = ceil(root->left, value);
    return (c >= value) ? c : root->data;
}

// bst *fbst(bst *root, int data)
// {
//     bst *prev = NULL;
//     return FloorInBST(root,prev,data);
// }

int main()
{
    bst *root = NULL;
    bst *tau;
    root = Insertion(root, 24);
    root = Insertion(root, 25);
    root = Insertion(root, 19);
    root = Insertion(root, 22);

   
    
    // tau  = fbst(root,24);
    // cout<<tau->data<<endl;
    cout<<FloorInBST(root,23);
    cout<<ceil(root,23);
 
    return 0;
}
