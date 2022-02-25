#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
} n;

void display(n *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"\t";
        head = head->next;
    }
}
n *Insertion_in_sorted_linked_list(n *head, int data)
{
    n *newNode;
    n *current,*temp;
    current = head;
    newNode->data = data;

    while(current!= NULL && current->data<newNode->data)
    {
        temp = current;
        current = current->next;
    }

    newNode->next = current;
    temp->next = newNode;
    return head;

}
int main()
{
    n *head;
    n *second;
    n *third;
    n *fourth;
    head = new n;
    second = new n;
    third = new n;
    fourth = new n;

    head->data = 29;
    head->next = second;

    second->data = 31;
    second->next = third;

    third->data = 35;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;
    display(head);
   head = Insertion_in_sorted_linked_list(head,32);
   display(head);
   

    return 0;
}