#include<iostream>
#include"1_Binary_Search_Tree.cpp"
using namespace std;


bst * kth_smallest_element(bst *root, int k, int count)
{
    if(root == NULL)
    return NULL;

    bst *left = kth_smallest_element(root->left, k, count);

    if(left)
    {
        return left;
    }
    if(++count == k)
        return root;
    else
        return kth_smallest_element(root->right,k,count);
    
}
int main()
{
    bst *root = NULL;
    root = Insertion(root,12);
    root = Insertion(root,24);
    root = Insertion(root,22);

    cout<<kth_smallest_element(root,3,0)->data;
    return 0;
}