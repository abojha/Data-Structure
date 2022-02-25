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
int Print_all_anchestors(tree *root, tree* node)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == node || root->right ==  node || Print_all_anchestors(root->left, node) || Print_all_anchestors(root->right, node))
    {
        cout<<root->data<<" ";
        return 1;
    }
    return 0;
}
int main()
{
    tree *r;
    tree *c1;
    tree *c2;
    tree *c3;
    tree *c4;
    tree *c5;

    r = create_a_node(22);
    c1 = create_a_node(23);
    c2 = create_a_node(35);
    c3 = create_a_node(30);
    c4 = create_a_node(20);
    c5 = create_a_node(60);
    
    r->left = c1;
    r->right = c2;

    c1->left = c3;
    c1->right = c4;
    c4->left = c5;
   
    
   
   
    Print_all_anchestors(r,c5);
    return 0;
}