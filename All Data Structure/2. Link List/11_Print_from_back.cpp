#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
    int data; 
    struct Node *next;
};

Node * Create_a_Linked_List(int &n)
{
    struct Node *temp = NULL;
    struct Node *head = NULL;
    struct Node *p = NULL;
    
    

    for(int i = 0; i < n; i++)
    {
        temp = new struct Node();
        cout<<"Enter the data:";
        cin>>temp->data;  
        temp->next = NULL;

        if(head==NULL)
        {
            head = temp;
        }
        else{
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
        cout<<head->data;
        head = head->next;
    }
}
void Print_from_back(struct Node *head)
{
    if(head==NULL)
    {
        return;
    }
    Print_from_back(head->next);
    cout<<head->data;
}
int main()
{
    int n;
    struct Node *head;
    cin>>n;
    head = Create_a_Linked_List(n);
    printing(head);
    cout<<endl;
    Print_from_back(head);

    
    
    return 0;
}