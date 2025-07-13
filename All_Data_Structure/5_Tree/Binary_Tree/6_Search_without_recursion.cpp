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
int search(tree *root, int key)
{
    queue<tree*> q;
    tree *temp;
    q.push(root);

    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->data == key)
        {
            return 1;
        }
        else
        {
            if(temp->right)
            {
                q.push(temp->right);
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
        }
    }
    if(q.empty())
    {
        return 0;
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
    if(search(r,233))
    {
        cout<<"Great, its found there";
    }
    else
    {
        cout<<"Bad, Luck";
    }
    return 0;
}