#include<iostream>
using namespace std;
class Stack
{
    int *array;
    int top;
    int size;
        Stack()
        {
            top = -1;
            size = 5;
            array = new int[size];
        }
    public:
        int isEmpty();
        int isFull();
        void Push(int data);
        int Pop();
        void printing();
        friend class Queue;
};
int Stack :: isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    return 0;
}
int Stack :: isFull()
{
    if(top == size-1)
    {
        return 1;
    }
    return 0;
}
void Stack :: Push(int data)
{
    if(isFull())
    {
        cout<<"Stack Overflow\n";
    }
    else
    {
        top++;
        array[top] = data;
    }
}
int Stack :: Pop()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow\n";
    }
    else
    {
        int x;
        x = array[top];
        top--;
        return x;
    }
}
void Stack :: printing()
{
    for(int i = size; i >=1; i--)
    {
        cout<<array[top-i+1]<<" ";
    }
}
class Queue
{
    public:
    Stack s1 ,s2;
    public:
    
        void Enqueue(int data);
        int Dequeue();
        void print()
        {
            s1.printing();
        }

};
void Queue :: Enqueue(int data)
{
    s1.Push(data);
}
int Queue :: Dequeue()
{
    if(!s2.isEmpty())
    {
        return s2.Pop();
    }
    else
    {
        int data;
        while(!s1.isEmpty())
        {
            s2.Push(s1.Pop());
        }
        data = s2.Pop();
        while(!s2.isEmpty())
        {
            s1.Push(s2.Pop());
            cout<<"hi";
        }
    }
}
int main()
{

   Queue *Q;
   Q = new Queue();
   Q->Enqueue(5);
   Q->Enqueue(4);
   Q->Enqueue(3);
   Q->Enqueue(2);
   Q->Enqueue(1);
   Q->print();
   Q->Dequeue();
   
   Q->print();

   

    return 0;
}