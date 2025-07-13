#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node * Creating_a_linked_list(int &n)
{
    Node *head = NULL, *temp = NULL, *ptr = NULL;

    for(int i = 0; i < n; i++)
    {
        temp = new Node();
        int x;
        cout<<"Enter the data for "<<i+1<<" Node "<<endl;
        cin>>x;
        temp->data = x;
        temp->next = temp;

        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            ptr = head;
            while(ptr->next!=head)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->next = head;
        }
    }
    return head;
}
void Print_a_Linked_list(Node *head)
{   Node *ptr = head;
    cout<<ptr->data<<" ";
    ptr = ptr->next;
   do{
       cout<<ptr->data<<" ";
       ptr = ptr->next;
   }while(ptr!=head);
}

void Two_CL_from_one_CL(Node *head)
{
    struct Node *head1,*head2;
    Node *slwptr = head, *fstptr = head;
    while(fstptr->next!=head && fstptr->next->next!=head)
    {
        slwptr = slwptr->next;
        fstptr = fstptr->next->next;
    }
    if(fstptr->next->next==head)
    {
        fstptr = fstptr->next;
    }
    head1 = head;
    if(head->next!=NULL)
    {
        head2 = slwptr->next;
    }
    fstptr->next = head2;
    slwptr->next = head1;

   Print_a_Linked_list(head1);
   cout<<endl;
   Print_a_Linked_list(head2);
}
int main()
{
    int n;
    cout<<"What is the size of your Linked List:\n";
    cin>>n;
    Node *Head;
    Head = Creating_a_linked_list(n);
    Print_a_Linked_list(Head);
    cout<<endl;
    Two_CL_from_one_CL(Head);
    

    
    return 0;
}