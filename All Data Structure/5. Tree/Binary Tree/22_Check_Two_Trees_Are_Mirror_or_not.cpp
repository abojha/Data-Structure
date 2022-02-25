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

int Are_mirror_or_not(tree *root1, tree *root2)
{
    if(root1 == NULL && root2 == NULL)
        return 1;
    if(root1 == NULL || root2 == NULL)
        return 0;
    if(root1->data != root2->data)
        return 0;
    
    else return Are_mirror_or_not(root1->left, root2->right) && Are_mirror_or_not(root1->right, root2->left);
}
int main()
{
    tree *r;
    tree*mr;
   
    r = create_a_node(22);
    Insertion_in_tree(r,25);
    Insertion_in_tree(r,100);
    mr = create_a_node(22);
    Insertion_in_tree(mr,100);
    Insertion_in_tree(mr,25);
   

    preorder(r);
    
    preorder(mr);

    if(Are_mirror_or_not(r,mr))
    {
        cout<<"both trees are mirror to each other\n";
    }
    else
    {
        cout<<"No they are not mirrors";
    }
    // cout<<endl;
    // cout<<r->data<<endl;
    // cout<<mr->data<<endl;
    // cout<<r->left->data<<endl;
    // cout<<mr->left->data<<endl;
    // cout<<r->right->data<<endl;
    // cout<<mr->right->data<<endl;
    return 0;
}