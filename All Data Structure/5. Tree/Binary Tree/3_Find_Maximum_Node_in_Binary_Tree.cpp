#include <iostream>
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
    if (root)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
int find_max(tree *root)
{
    int root_val, left, right, max = INT8_MIN;
    if (root != NULL)
    {
        root_val = root->data;
        left = find_max(root->left);
        right = find_max(root->right);

        if (left > right)
        {
            max = left;
        }
        else
        {
            max = right;
        }
        if (max < root_val)
        {
            max = root_val;
        }
    }
    return max;
}
int main()
{
    tree *r;
    tree *c1;
    tree *c2;
    tree *c3;

    r = create_a_node(200);
    c1 = create_a_node(23);
    c2 = create_a_node(350);
    c3 = create_a_node(20);

    r->left = c1;
    r->right = c2;
    c2->left = c3;

    preorder(r);

    cout << find_max(r);
    return 0;
}