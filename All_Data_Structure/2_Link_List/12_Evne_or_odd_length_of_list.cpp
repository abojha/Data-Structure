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
int Even_or_odd(struct Node *head)
{
    while(head&&head->next)
    {
        head = head->next->next;
    }
        if(head!=NULL)
        {
            return 0;
        }
       return 1;
    
}
int main()
{
    int n;
    struct Node *head;
    cin>>n;
    head = Create_a_Linked_List(n);
    printing(head);
    cout<<endl;
    int check = Even_or_odd(head);
    if(check == 1)
    {
        cout<<"Linked list is in even:\n";
    }
    else{
        cout<<"Not even:\n";
    }

    
    
    return 0;
}