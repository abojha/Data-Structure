#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
void printing(struct Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}
void *delete_the_give_node(struct Node *node)
{
    struct Node *temp;
    temp = node->next;

    node->data = node->next->data;
    node->next = temp->next;
    free(temp);
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = new struct Node();
    second = new struct Node();
    third = new struct Node();
    fourth = new struct Node();

    head->data = 24;
    head->next = second;

    second->data = 25;
    second->next = third;

    third->data = 45;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = NULL;

    printing(head);
    delete_the_give_node(third);
    cout<<endl;
    printing(head);
    return 0;
}