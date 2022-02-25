#include<iostream>
#include"1_Binary_Search_Tree.cpp"
#include<queue>
using namespace std;

void Print_in_K1_K2_form(bst *root, int k1, int k2)
{
    if(!root)
    {
        return;
    }
    if(root->data >= k1)
    {
        Print_in_K1_K2_form(root->left, k1, k2);
    }
    if(root->data >= k1 && root->data <= k2)
    {
        cout<<root->data<<" ";
    }
    if(root->data <= k2)
    {
        Print_in_K1_K2_form(root->right, k1, k2);
    }
}

void Print_in_range(bst *root, int a, int b)
{
    bst *temp;
    queue<bst*> q;
    q.push(root);

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->data >= a && temp->data <= b)
        {
            cout<<temp->data<<endl;
        }
        if(temp->left && temp->data >= a)
        {
            q.push(temp->left);
        }
        if(temp->right && temp->data <= b)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    bst *root = NULL;
    bst *tau;
    root = Insertion(root, 24);
    root = Insertion(root, 25);
    root = Insertion(root, 19);
    root = Insertion(root, 22);

    // Inorder_Traversal(root);

    Print_in_K1_K2_form(root,19,24);
    Print_in_range(root,19,24);
    
    
    return 0;
}
