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
tree *Mirror_tree(tree *root)
{
    static tree *temp;
    if(root)
    {
        Mirror_tree(root->left);
        Mirror_tree(root->right);
        
        temp = root->left;
        root->left = root->right;
        root->right = temp;

    }
    return root;
}
int main()
{
    tree *r;
    tree*mr;
   
    r = create_a_node(22);
   
    
   
    Insertion_in_tree(r,25);
    Insertion_in_tree(r,100);
   
    preorder(r);
    mr = Mirror_tree(r);
    preorder(mr);
   
    cout<<mr->left->data<<endl;
    cout<<r->left->data<<endl;
    return 0;
}