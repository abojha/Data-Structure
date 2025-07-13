#include<iostream>
using namespace std;

struct stack
{
    int top;
    int *arr;
};
struct Advanced_Stack
{
    struct stack *stack_element;
    struct stack *stack_min;
};
struct stack * creation()
{
    struct stack *s;
    s = new struct stack();
    s->arr = new int[10];
    s->top = -1;
    return s;
}
int isEmpty(struct stack *s)
{
    if(s->top == -1)
    {
        return 1;
    }
    return 0;
}
struct Advanced_Stack* creation_of_stack(struct Advanced_Stack *S)
{
    S = new struct Advanced_Stack();
    S->stack_element = creation();
    S->stack_min = creation();
    return S;
}
void push(struct stack *s, int data)
{
    s->arr[++s->top] = data;
}
int Top(struct stack *s)
{
    return s->arr[s->top];
}
void PUSH(struct Advanced_Stack *S,int data)
{
    push(S->stack_element,data);
   

    if(isEmpty(S->stack_min) ||Top(S->stack_min)>=data)
    {
        push(S->stack_min,data);
    }
}
int pop(struct stack *s)
{
    int a;
    a = s->arr[s->top--];
    return a;
}
int POP(struct Advanced_Stack *S)
{
    int item;
    item = pop(S->stack_element);

    if(item ==  Top(S->stack_min))
    {
        pop(S->stack_min);
    }
    return item;
}
int get_minimum(struct Advanced_Stack *s)
{
    return Top(s->stack_min);
}
int main()
{
    struct Advanced_Stack *ST;
    ST = creation_of_stack(ST);
    PUSH(ST,2);
    PUSH(ST,5);
    PUSH(ST,1);
    
   

    cout<<get_minimum(ST);
    
    return 0;
}