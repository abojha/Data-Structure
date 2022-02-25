#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *address_of_next_node;
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
        temp->address_of_next_node = NULL;

        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            ptr = head;
            while(ptr->address_of_next_node!=NULL)
            {
                ptr = ptr->address_of_next_node;
            }
            ptr->address_of_next_node = temp;
        }
    }
    return head;
}
void Print_a_Linked_list(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->address_of_next_node;
    }
}
Node *Reverse_in_pair(Node *head)
{
    Node *curr = head, *temp1 = NULL, *temp2 = NULL;
  
    while(curr!=NULL && curr->address_of_next_node != NULL)
    {
        if(temp1!=NULL)
        {
            temp1->address_of_next_node->address_of_next_node = curr->address_of_next_node;
        }
        temp1 = curr->address_of_next_node;
        curr->address_of_next_node = curr->address_of_next_node->address_of_next_node;
        temp1->address_of_next_node = curr;
        if(temp2 == NULL)
        {
            temp2 = temp1;
        }
        curr = curr->address_of_next_node;
    }
    return temp2;
}
Node * Recursive_Reverse_in_pair(Node *head)
{
    Node *temp;
    if(head == NULL || head->address_of_next_node == NULL)
    {
        return head; // base case for empty list and one element list
    }
    else{
        temp = head->address_of_next_node;
        head->address_of_next_node = temp->address_of_next_node;
        temp->address_of_next_node = head;
        head = temp;

        head->address_of_next_node->address_of_next_node = Recursive_Reverse_in_pair(head->address_of_next_node->address_of_next_node);
        return head;
    }
}
int main()
{
    int n;
    cout<<"What is the size of your Linked List:\n";
    cin>>n;
    Node *Head;
    Node *NewList;
    Node *NewList2;
    Head = Creating_a_linked_list(n);
    Print_a_Linked_list(Head);
    cout<<endl;
    // NewList = Reverse_in_pair(Head);
    // Print_a_Linked_list(NewList);
    // cout<<endl;
    NewList2 = Recursive_Reverse_in_pair(Head);
    Print_a_Linked_list(NewList2);


    
    return 0;
}