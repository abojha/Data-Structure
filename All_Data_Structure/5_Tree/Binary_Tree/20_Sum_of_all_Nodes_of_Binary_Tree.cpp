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
int sum_of_all_elements(tree *root)
{
    if(root == NULL)
    return 0;

    return (root->data + sum_of_all_elements(root->right) + sum_of_all_elements(root->left));
}
int sum_without_recursion(tree *Root)
{
    queue<tree*> q;
    tree *temp;
    q.push(Root);
    int sum = 0;

    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        sum+=temp->data;

        if(temp->right)
        {
            q.push(temp->right);
        }
        if(temp->left)
        {
            q.push(temp->left);
        }
    }
    return sum;
}
int main()
{
    tree *r;
    tree *r2;

    r = create_a_node(22);
    r2 = create_a_node(22);
    Insertion_in_tree(r,25);
    Insertion_in_tree(r,100);
    Insertion_in_tree(r,50);
    Insertion_in_tree(r2,25);
    Insertion_in_tree(r2,100);
    Insertion_in_tree(r2,50);

    preorder(r);

    cout<<sum_of_all_elements(r);
    cout<<sum_without_recursion(r);
    return 0;
}