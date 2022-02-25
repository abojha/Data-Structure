#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
} n;

int count_Loop(struct Node *head)
{
    int count = 0, loop_exists = 0;
    
    n *slowptr;
    n *fastptr;

    slowptr = head;
    fastptr = head;
    while (slowptr->next != NULL)
    {
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if (slowptr == fastptr)
        {
            loop_exists = 1;
            break;
        }
    }
    if (loop_exists==1)
    {
        slowptr = slowptr->next;
        while (slowptr != fastptr)
        {
            count++;
            slowptr = slowptr->next;
        }
        return count;
    }
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

    head->data = 2;
    head->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = fourth;

    fourth->data = 5;
    fourth->next = second;

    count_Loop(head);
    int sum = count_Loop(head);
    cout << sum;

    return 0;
}