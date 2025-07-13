#include<iostream>
using namespace std;

class BST
{
    int data;
    public:
    BST *left, *right;
    BST (int key)
    {
        this->data = key;
        this->left = NULL;
        this->right = NULL;
    }
    
    BST *insert(BST *root, int key)
    {
        if(root == NULL)
        {
            root = new BST(key);
            return root;
        }
        if(root->data > key)
        {
            root->left = insert(root->left, key);
        }
        if(root->data < key)
        {
            root->right = insert(root->right, key);
        }
        return root;
    }
    void insert(int data)
    {
        insert(this,data);   
    }
    void Inorder();
    void Preorder();
    int Search_in_BST(int key);
    BST *ipred()
    {
        BST *root;
        root = this->left;
        while(root->right != NULL)
        {
            root = root->right;
        }
        return root;
    }
    BST *Delete(int key)
    {
        if(this == NULL)
        {
            return NULL;
        }
        BST *iprep = NULL;
        if(this->left == NULL && this->right == NULL)
        {
            free(this);
            return NULL;
        }
        if(this->data > key)
        {
            this->left = this->left->Delete(key);
        }
        else if(this->data < key)
        {
            this->right = this->right->Delete(key);
        }
        else
        {
            iprep = this->ipred();
            this->data = iprep->data;
            this->left->Delete(iprep->data);
        }
    }
};
void BST :: Inorder()
{
    if(this->left != NULL)
    this->left->Inorder();
    cout<<this->data<<" ";
    if(this->right != NULL)
    this->right->Inorder();
}
void BST :: Preorder()
{
    cout<<this->data<<" ";
    if(this->left != NULL)
    this->left->Inorder();
    if(this->right != NULL)
    this->right->Inorder();

}
int BST ::Search_in_BST(int key)
{
    if(this == NULL)
    {
        cout<<" not Found ";
    }
    if(this->data == key)
    {
        return 1;
    }
    else if(this->data > key)
    {
        this->left->Search_in_BST(key);
    }
    else if(this->data < key)
    {
        this->right->Search_in_BST(key);
    }
    
}

int main()
{
    BST *root;
    root = new BST(25);
    root->insert(22);
    root->insert(50);

    root->Inorder();
    root->Preorder();
    cout<<root->Search_in_BST(22);
    root->Delete(50);
    root->Inorder();
    cout<<root->Search_in_BST(22);

    return 0;
}