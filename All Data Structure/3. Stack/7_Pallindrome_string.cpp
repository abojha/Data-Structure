#include<iostream>
using namespace std;

struct stack 
{
    int top;
    char *array;
    int size;
};
struct stack *create()
{
    struct stack *s;
    s = new struct stack();
    s->top = -1;
    s->size = 100;
    s->array  = new char[100];
    return s;
}
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
void push(stack *s, char x)
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
char pop(stack *s)
{
    char x;
    x = s->array[s->top--];
    cout<<x<<" Popped successfully!"<<endl;
    return x;
}
int isPallindrome(char *expression)
{
    struct stack *s;
    s = create();
    int i = 0;
    while(expression[i] != 'X')
    {
        push(s,expression[i]);
        i++;
    }
    i++;
    while(expression[i])
    {
         if(isEmpty(s) || expression[i] != pop(s))
        {
            return 0;
        }
        i++;
    }
    return 1;
   
}
int main()
{
    char expression[] = "abcXcba";
    if(isPallindrome(expression))
    {
        cout<<"great";
    }

    return 0;
}