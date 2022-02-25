#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct stack
{
    int size;
    int top;
    char *array;
};
int isEmpty(struct stack *s)
{
    if(s->top == -1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *s, char a)
{
   
        s->array[++s->top] = a;
    
}
char pop(struct stack *s)
{
    char element;
    if(!isEmpty(s))
    {
        element = s->array[s->top--];
        return element;
    }
}
int matching(char a, char b)
{
    if(a=='(' && b == ')')
        return 1;
    if(a=='{' && b == '}')
        return 1;
    if(a=='[' && b == ']')
        return 1;
    return 0;
}
int  Parenthesis_Matching(char * expression)
{
    struct stack *s;
    s->top  = -1;
    s->array = new char(strlen(expression));
    char element;

    for(int i = 0; expression[i]!='\0'; i++)
    {
        if(expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
        {
            push(s,expression[i]);
        }

        else if(expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
        {
            if(isEmpty(s))
            {
                return 0;
            }
            element = pop(s);
            if(!matching(element,expression[i]))
            {
                return 0;
            }
        
        }
    }
    if(isEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char expression[] = "(a+b)-{34]";
    
    if(Parenthesis_Matching(expression))
    {
        cout<<"Balanced";
    }
    else
    {
        cout<<"Unbalanced";
    }
    
    return 0;
}