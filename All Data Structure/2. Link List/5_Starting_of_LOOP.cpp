#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void printing(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *starting_of_loop(struct Node *head)
{
    struct Node *fast_ptr;
    struct Node *slow_ptr;
    int loopExists = 0;
    fast_ptr = head;
    slow_ptr = head;
    while (slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if (slow_ptr == fast_ptr)
        {
            loopExists = 1;
            break;
        }
    }
    if (loopExists)
    {
        slow_ptr = head;
        while (slow_ptr != fast_ptr)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
      printf("%d",slow_ptr->data);
    }
    return 0;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head = (struct Node *)malloc(sizeof(struct Node *));
    second = (struct Node *)malloc(sizeof(struct Node *));
    third = (struct Node *)malloc(sizeof(struct Node *));
    fourth = (struct Node *)malloc(sizeof(struct Node *));
    fifth = (struct Node *)malloc(sizeof(struct Node *));

    head->data = 17;
    head->next = second;

    second->data = 19;
    second->next = third;

    third->data = 21;
    third->next = fourth;

    fourth->data = 23;
    fourth->next = fifth;

    fifth->data = 27;
    fifth->next = third;
    //printing(head);
    starting_of_loop(head);
    
    return 0;
}