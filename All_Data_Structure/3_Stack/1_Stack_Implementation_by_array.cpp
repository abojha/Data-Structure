#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct stack
{
    int *array;
    int top;
    int size;
}stack;
int isEmpty(stack *st) // check if stack is empty 
{
    if(st->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(stack *st)   // check whether stack is full or not
{
    if(st->top == st->size-1)
    {
        return 1;
    }
    return 0;
}
void push(stack *s, int x)
{
    if(isFull(s))
    {
        cout<<x<<" can't pushed because of stack overflow!"<<endl;
    }
    else
    {
        s->array[++s->top] = x;
        cout<<x<<" Pushed successfully"<<endl;
    }
}
int pop(stack *s)
{
    int x;
    x = s->array[s->top--];
    cout<<x<<" Popped successfully!"<<endl;
    return x;
}
void peek(stack *s)
{
    int pos;
    cout<<"Enter the position of stack which you want to get:\n";
    cin>>pos;
    int arrInd = s->top-pos+1;
    cout<<s->array[arrInd]<<" is at the "<<"Position "<<pos<<" Required element\n";
}
int stack_top(stack *s)
{
    return s->array[s->top];
}
int stack_Bottom(stack *s)
{
    return s->array[0];
}
int main()
{  
    stack *s;
    s = (stack *)malloc(sizeof(stack));
    s->size = 10;
    s->top = -1;
    s->array = (int *)malloc(s->size * sizeof(int)); 

    // printf("%d ",isEmpty(s));
    // printf("%d ",isFull(s));
    push(s,2);
    push(s,5);
    push(s,7);
    push(s,9);
    push(s,12);
    push(s,15);
    push(s,20);
    push(s,200);
    push(s,21);
    push(s,26);

    // // pop(s);
    // // push(s,5);
    // peek(s);

    cout<<"The top Most element of Stack is "<<stack_top(s)<<endl;
    cout<<"The bottom Most element of Stack is "<<stack_Bottom(s)<<endl;
    


    return 0;
}