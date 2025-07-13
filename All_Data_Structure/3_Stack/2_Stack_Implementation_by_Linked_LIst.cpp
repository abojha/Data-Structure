#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct stack
{
    int data;
    struct stack *next; 
} stack;

int isEmpty(stack *ptr)
{
    if(ptr == NULL)
    {
        return 1;
    }
    return 0;
}
int isFull(stack *ptr)
{
    stack *n = (stack*)malloc(sizeof(stack));
    if(n == NULL)
    {
        return 1;
    }
    return 0;
}
stack* push(stack *top, int x)
{
    if(isFull(top))
    {
        cout<<x<<" can't push because of stack overflow\n";
    }
    else{
    stack *node = (stack *)malloc(sizeof(stack));
    node->data = x;
    node->next = top;
    top = node;
    cout<<x<<" pushed successfully\n";
    return top;
    }
}
int pop(stack **top)
{
    if(isEmpty(*top))
    {
        cout<<"Can't pop because of stack underflow\n";
    }
    else
    {
        int x;
        struct stack *node;
        node = *top;
        x = node->data;
        *top = (*top)->next;
        free(node);
        cout<<x<<" Popped Successfully\n";
        return x;
    }
}
void peek(stack *top)
{
    int pos;
    stack*node;
    node = top;
    cout<<"\nEnter the Position of Element\n";
    cin>>pos;
    for(int i = 0; i < pos-1 && node!=NULL;i++)
    {
        node = node->next;
    }
    cout<<node->data<<" Require Element at "<<pos<<" positon"<<endl;

}
void stack_top(stack *top)
{
    cout<<"The top most element of stack is "<<top->data<<endl;
}
void stack_bottom(stack *top)
{
    stack *node;
    node = top;
    while(node->next!=NULL)
    {
        node = node->next;
    }
    cout<<"The Bottom most element of stack is "<<node->data<<endl;
}
int main()
{
    stack *top;
    top = NULL;     

    top = push(top,2);
    top = push(top,26);
    top = push(top,29);
    
    
    // pop(&top);
    // pop(&top);
    // pop(&top);
    // pop(&top);
    peek(top);
    stack_top(top);
    stack_bottom(top);
    pop(&top);
    stack_top(top);
    stack_bottom(top);
    return 0;
}