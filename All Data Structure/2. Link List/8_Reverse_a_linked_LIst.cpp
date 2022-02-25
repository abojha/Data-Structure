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
n *Revers_a_list(n *head)
{
    n*current = head;
    n*prev = NULL;
    n*next = NULL;

    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct Node *Recursive_approach(struct Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next == NULL)
    {
        return head;
    }
    struct Node *secondElement = head->next;
    head->next = NULL;

    struct Node *reverserest = Recursive_approach(secondElement);
    secondElement->next = head;
    return reverserest;
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
    //head= Revers_a_list(head);
    head = Recursive_approach(head);
    display(head);
   

    return 0;
}