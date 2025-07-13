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
int size_of_tree(tree *root)
{
    tree *temp;
    int count = 0;
    queue<tree*> cq;
    
    cq.push(root);
    while(!cq.empty())
    {
        temp = cq.front();
        cq.pop();
        count++;

        if(temp->left)
        {
            cq.push(temp->left);
        }
        if(temp->right)
        {
            cq.push(temp->right);
        }
    }
    return count;
}
int main()
{
    tree *r;
    r = create_a_node(44);
    Insertion_in_tree(r,25);
    Insertion_in_tree(r,26);
    Insertion_in_tree(r,20);
    Insertion_in_tree(r,400);

    preorder(r);
    cout<<size_of_tree(r);
    return 0;
}
