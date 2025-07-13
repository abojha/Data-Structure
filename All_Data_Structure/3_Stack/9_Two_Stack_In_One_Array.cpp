#include<iostream>
using namespace std;

struct stack
{
    int *array;
    int top1;
    int top2;
    int size;
};
int isEmpty1(struct stack *s)
{
    if(s->top1 == -1)
    {
        return 1;
    }
    return 0;
}
int isEmpty2(struct stack *s)
{
    if(s->top2 == s->size)
    {
        return 1;
    }
    return 0;
}
void push1(struct stack *s, int data)
{
    s->top1++;
    s->array[s->top1] = data;
}

int main()
{
    struct stack *s;
    s = new struct stack();
    s->size = 10;
    s->top1 = -1;
    s->top2 = s->size;
    s->array = new int(s->size);
    push1(s,2);
    cout<<isEmpty1(s)<<endl;
    cout<<isEmpty2(s)<<endl;
    return 0;
}