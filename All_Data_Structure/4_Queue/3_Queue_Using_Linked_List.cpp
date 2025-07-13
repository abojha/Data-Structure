#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

};
struct Node *f = NULL;
struct Node *r = NULL;
void Enq(int data)
{
    struct Node *n;
    n = new struct Node();
    if(n == NULL)
    {
        cout<<"Queue is Full\n";
        return;
    }
    n->data = data;
    n->next = NULL;
    if(f == NULL)
    {
        f = r = n;
    }
    else
    {
        r->next = n;
        r = n;
    }
}
int DeQ()
{
    if(f==NULL)
    {
        cout<<"queue is empty\n";
        return 0;
    }
    else
    {
        struct Node *ptr;
        int data;
        ptr = f;
        f = f->next;
        data = ptr->data;
        free(ptr);
        return data;
    }
}
void printing(struct Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<endl;
        head = head->next;
    }
}
int main()
{
    Enq(2);
    Enq(4);
    Enq(2);
    printing(f);
    DeQ();
     printing(f);

    return 0;
}