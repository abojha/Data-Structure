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
void Zig_Zag_Traversal(tree *root)
{
    tree *temp;
    stack<tree*> current_level;
    stack<tree*> next_level;
    int leftTORight = 0;

    current_level.push(root);

    while(!current_level.empty())
    {
        temp = current_level.top();
        current_level.pop();

        if(temp)
        {
            cout<<temp->data<<" ";
            if(leftTORight)
            {
                next_level.push(temp->left);
                next_level.push(temp->right);
            }
            else
            {
                next_level.push(temp->right);
                next_level.push(temp->left);
            }
        }
        if(current_level.empty())
        {
            leftTORight = 1 - leftTORight;
            swap(current_level,next_level);
        }
    }
}
int main()
{
    tree *r;
    tree *c1;
    tree *c2;
    tree*c3;
    tree *c4;
    tree *c5;
    tree *c6;

    r = create_a_node(35);
    c1 = create_a_node(25);
    c2 = create_a_node(33);
    c3 = create_a_node(40);
    c4 = create_a_node(45);
    c5 = create_a_node(12);
    c6 = create_a_node(70);

    r->left = c1;
    r->right = c2;

    c1->left = c3;
    c1->right = c4;

    c2->left = c5;
    c2->right = c6;

    Zig_Zag_Traversal(r);
    return 0;
}