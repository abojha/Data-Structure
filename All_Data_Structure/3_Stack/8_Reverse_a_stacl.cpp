#include<iostream>
using namespace std;

struct stack
{
    int top;
    int *array;
    int size;
};
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
void Insert_at_Bottom(struct stack *s, int data)
{
    int temp;
    if(isEmpty(s))
    {
        push(s,data);
        return;
    }
    temp = pop(s);
    Insert_at_Bottom(s,data);
    push(s,temp);

}
void Recursive_stack(struct stack *s)
{
    int data;
    if(isEmpty(s))
    {
        return;
    }
    data = pop(s);
    
    Recursive_stack(s);
    Insert_at_Bottom(s,data);
    
}

void peek(stack *s, int p)
{
    int pos = p;
    int arrInd = s->top-pos+1;
    cout<<s->array[arrInd]<<endl;
}
int main()
{
    int pos;
    struct stack *s;
    s = new struct stack();
    s->top = -1;
    s->size = 3;
    s->array = new int(s->size);
    push(s,1);
    push(s,2);
    push(s,3);
    

    for(int i = 0; i < s->size; i++)
    {
        peek(s,i+1);
    }
    Recursive_stack(s);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    for(int i = 0; i < s->size; i++)
    {

        peek(s,i+1);
    }


    
    return 0;
}