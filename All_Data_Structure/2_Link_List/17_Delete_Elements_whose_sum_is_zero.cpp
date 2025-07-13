#include<iostream>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
};
struct Node * Creating_a_Linked_List(int n)
{
    struct Node *head = NULL;
    struct Node *p;
    struct Node *temp;
    for(int i = 0; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        int x;
        cout<<"Enter the data";
        cin>>x;
        temp->data = x;
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            p = head;
            while(p->next!=NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
    return head;
}
void printing(struct Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}
int main()
{
    struct Node *Head;
    int size;
    cout<<"Enter the size of Linked List\n";
    cin>>size;
    Head = Creating_a_Linked_List(size);
    printing(Head);
    return 0;
}