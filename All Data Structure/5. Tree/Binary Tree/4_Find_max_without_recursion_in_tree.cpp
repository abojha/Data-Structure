#include<iostream>
#include<queue>
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
int find_without_recursion(tree *root)
{
    tree *temp;
    int max = INT8_MIN;
    queue<tree*> q;
    q.push(root);

    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(max < temp->data)
        {
            max = temp->data;
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        if(temp->left)
        {
            q.push(temp->left);
        }
    }
    return max;


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
    cout<<find_without_recursion(r);
    return 0;
}