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

int max_level(tree *root)
{
    queue<tree*> q;
    tree *temp;
    int level = 0, curren_sum = 0, max_sum = 0,max_levell = 0;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        
        if(temp == NULL)
        {
            if(curren_sum>max_sum)
            {
                max_sum = curren_sum;
                max_levell = level;

            }
            curren_sum = 0;

            if(!q.empty())
                q.push(NULL);
            level++;
        }
        else
        {
            curren_sum += temp->data;
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
    return max_levell;
}
int main()
{
    tree *r;
    tree *r2;

    r = create_a_node(22);
    Insertion_in_tree(r,25);
    Insertion_in_tree(r,100);
    Insertion_in_tree(r,200);

    preorder(r);
    cout<<max_level(r);

    
    return 0;
}