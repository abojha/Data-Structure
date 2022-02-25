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
int compare_two_trees(tree *root1, tree *root2)
{
    if(root1 == NULL && root2 == NULL)
    return 1;
    if(root1 == NULL || root2 == NULL)
    return 0;

    return (root1->data == root2->data && compare_two_trees(root1->left, root2->left)
            && compare_two_trees(root1->right, root2->right));
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

    if(compare_two_trees(r,r2))
    {
        cout<<"Both trees are identical";

    }
    else
    {
        cout<<"!!!!!!!!!!!!!!!!!!";
    }
    return 0;
}