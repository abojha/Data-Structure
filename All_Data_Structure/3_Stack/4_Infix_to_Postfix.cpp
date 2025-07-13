#include<iostream>
#include<string.h>
using namespace std;

struct stack
{
    int top;
    int size;
    char *arr;
};
struct stack * create_stacks(int size)
{
    struct stack *s;
    s = new struct stack();
    s->top = -1;
    s->size = size;
    s->arr = new char[s->size];

    return s;

}
int Operator(char a)
{
    if(a == '+' || a == '-' || a == '*' || a == '/')
    return 1;

    return 0;
}
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
   
    s->arr[++s->top] = a;
}
char pop(struct stack *s)
{
    char b;
    b = s->arr[s->top--];
    return b;
}
char Top(struct stack *s)
{
    return s->arr[s->top];
}
int prec(char a)
{
    if(a == '+' || a == '-')
    return 2;
    else if(a == '*' || a == '/' )
    return 3;

    return 0;
}
char * Infix_to_Postfix(char * infix)
{
    struct stack *s;
    s = create_stacks(strlen(infix));
    char * Postfix;
    Postfix = new char[strlen(infix)];
    int i = 0;
    int j = 0;
    while(infix[i] !='\0')
    {
        if(!Operator(infix[i]))
        {
            Postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            
            if(prec(infix[i]) > prec(Top(s)))
            {
                push(s,infix[i]);
                i++;
            }
            else
            {
                
                Postfix[j] = pop(s);
                j++;
            }
           
        }
    }
    while(!isEmpty(s))
    {
        Postfix[j] = pop(s);
        j++;

    }
    Postfix[j] = '\0';
    return Postfix;
    
}
int main()
{
    char expression[] = "x-y/z-k*d";
    cout<<Infix_to_Postfix(expression);
    
    return 0;
}