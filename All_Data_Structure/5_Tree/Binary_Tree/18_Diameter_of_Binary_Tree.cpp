#include<algorithm>
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
int height(tree *root)
{
    int l,r;
    if(root == NULL)
    return 0;
    else
    {
        l = height(root->left);
        r = height(root->right);
    }
    

    if(l>r)
    {
        return (l+1);
    }
    else
    {
        return (r+1);
    }


}
int Diameter_of_Tree(tree *root)
{
    if(root == NULL)
    return 0;
    int lHeight, lDiameter, rHeight, rDiameter;
    lHeight = height(root->left);
    rHeight = height(root->right);

    lDiameter = Diameter_of_Tree(root->left);
    rDiameter = Diameter_of_Tree(root->right);

    return max(lHeight+rHeight +1, max(lDiameter,rDiameter));
}

int main()
{
    tree *r;

    r = create_a_node(22);
    Insertion_in_tree(r,25);
    Insertion_in_tree(r,100);
    Insertion_in_tree(r,50);

    preorder(r);
    cout<<Diameter_of_Tree(r);
    return 0;
}