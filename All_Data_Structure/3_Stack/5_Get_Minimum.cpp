#include<iostream>
#include<stdlib.h>
using namespace std;

struct stack
{
    int size;
    int *array;
    int top;
};
struct Advanced_stack
{
    struct stack *stack_element;
    struct stack *stack_min;
};
struct stack * create_stack()
{
    struct stack *s;
    s = new struct stack();
    s->top = -1;
    s->size = 10;
    s->array = new int(s->size);
    return s;
}
struct Advanced_stack * Creation_Advance_stack()
{
    struct Advanced_stack *S;
    S = new struct Advanced_stack();
    
    
        S->stack_element = create_stack();
        S->stack_min = create_stack();
    
    return S;
}
int isEmpty(struct stack *s)
{
     
    if(s->top == -1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *s, int x)
{
   
    s->array[++s->top] = x;
}
int Top(struct stack *s)
{
    return s->array[s->top];
}
int pop(struct stack *s)
{
    int a;
    a = s->array[s->top--];
}
void PUSH(struct Advanced_stack *S,int data)
{
    
    push(S->stack_element,data);
    
    if(isEmpty(S->stack_min) || Top(S->stack_min)>=data)
    {
        
        push(S->stack_min,data);
    }
    else
    {
        push(S->stack_min,Top(S->stack_min));
    }
}
int POP(struct Advanced_stack *S)
{
    int temp;
    temp = pop(S->stack_element);
    pop(S->stack_min);
    return temp;
    
}
int Get_minimum(struct Advanced_stack *s)
{
    return Top(s->stack_min);
}
int main()
{
    struct Advanced_stack *s;
    s = Creation_Advance_stack();

    PUSH(s,2);
    PUSH(s,6);
    PUSH(s,4);
    PUSH(s,1);
    PUSH(s,5);

    POP(s);
    POP(s);
    
    
    cout<<Get_minimum(s);


    return 0;
}