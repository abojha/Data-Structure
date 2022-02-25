#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

void printing(struct Node *ptr)
{   while(ptr!=NULL){
    printf("%d\n",ptr->data);
    ptr = ptr->next;
}
}
int does_printer_has_LOOP(struct Node *head)
{
    struct Node *fast_ptr;
    struct Node *slow_ptr;
    fast_ptr = head;
    slow_ptr = head;
    while(slow_ptr&&fast_ptr&&fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
        if(slow_ptr == fast_ptr)
        {
            return 1;
            
        }
       
    }
     return 0;
    
}
int main()
{
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node *  fourth;
    struct Node * fifth;

    head = (struct Node *)malloc(sizeof(struct Node*));
    second = (struct Node *)malloc(sizeof(struct Node*));
    third = (struct Node *)malloc(sizeof(struct Node*));
    fourth = (struct Node *)malloc(sizeof(struct Node*));
    fifth = (struct Node *)malloc(sizeof(struct Node*));

    head->data = 17;
    head->next = second;
    
    second->data= 19;
    second->next = third;

    third->data = 21;
    third->next = fourth;

    fourth->data = 23;
    fourth->next = fifth;

    fifth->data = 27;
    fifth->next = NULL;
    //printing(head);
    if(does_printer_has_LOOP(head) == 1)
    {
        printf("it has loop\n");
    }
    else
    {
        printf("It has no loop\n");
    }
    
    return 0;
}