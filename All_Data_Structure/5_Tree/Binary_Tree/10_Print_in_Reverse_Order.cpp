#include<iostream>
#include<queue>
#include<stack>
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
void Insertion_in_tree(tree *root, int key)
{
    tree *temp;
    tree *new_node;
    queue<tree*> q;
    new_node = new tree();
    new_node->data = key;
    new_node->left = new_node->right = NULL;

    if(!new_node)
    {
        cout<<"Memory Error!!";
    }
    if(!root)
    {
        root = new_node;
        return;
    }
    q.push(root);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->left)
        {
            q.push(temp->left);
        }
        else
        {
            temp->left = new_node;
            return;
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
        else
        {
            temp->right = new_node;
            return;
        }
    }

}
void printf_in_reverse_order(tree *root)
{
    tree *temp;
    queue<tree*> cq;
    stack<int> s;
    cq.push(root);

    while(!cq.empty())
    {
        temp = cq.front();
        cq.pop();

        if(temp->left)
        {
            cq.push(temp->left);
        }
        if(temp->right)
        {
            cq.push(temp->right);
        }
        s.push(temp->data);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
}
int main()
{
    tree *r;
    tree *c1;
    tree *c2;
    tree *a;
    tree *b;
    tree *c;
    r = create_a_node(35);
    Insertion_in_tree(r,25);
    Insertion_in_tree(r,100);
    Insertion_in_tree(r,50);
    
    preorder(r);
    printf_in_reverse_order(r);
    return 0;
}