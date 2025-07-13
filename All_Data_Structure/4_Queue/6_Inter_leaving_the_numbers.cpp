#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    int *array;
    int f;
    int r;
    int size;

public:
    Queue(int n);
    int isEmpty();
    int isFull();
    void Enqueue(int n);
    int Dequeue();
    void print_all_elements();
    int Size();
   
};
int Queue ::Size()
{
    int count = 0;
    for(int i = f; i <= r; i++)
    {
        count++;
    }
    return count;
}
class Stack
{
    int *array;
    int top;
    int size;
        Stack()
        {
            top = -1;
            size = 10;
            array = new int[size];
        }
    public:
        int isEmpty();
        int isFull();
        void Push(int data);
        int Pop();
        void printing();
        friend class Queue;
        friend void Inter_leaving(Queue Q);
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
Queue ::Queue(int n)
{
    f = -1;
    r = -1;
    size = n;
    array = new int[size];
}
int Queue ::isEmpty()
{
    if (f == -1)
    {
        return 1;
    }
    return 0;
}
int Queue ::isFull()
{
    if (r == size - 1)
    {
        return 1;
    }
    return 0;
}
void Queue ::Enqueue(int n)
{
    if (isFull())
    {
        cout << "Can't Insert Element\n";
    }
    else
    {
        r++;
        array[r] = n;
        if (f == -1)
        {
            f = 0;
        }
        cout << "Enqueue Successful\n";
    }
}
int Queue ::Dequeue()
{
    if (isEmpty())
    {
        cout << "Can't Delete\n";
    }
    else
    {
        int data;
        data = array[f];
        if (f == r)
        {
            f = r = -1;
        }
        else
            f++;
        cout << "DEqueue Successful\n";
        return data;
    }
}
void Queue ::print_all_elements()
{
    for (int i = f; i <= r; i++)
    {
        cout << array[i] << endl;
    }
}
void Inter_leaving(Queue q)
{
    Stack s;
    int half = (q.Size())/2;
    for(int i = 0; i < half; i++)
    {
        s.Push(q.Dequeue());
    }
    while(!s.isEmpty())
    q.Enqueue(s.Pop());

    for(int i = 0; i < half; i++)
        q.Enqueue(q.Dequeue());
    
    for(int i = 0; i < half; i++)
        s.Push(q.Dequeue());
    
    while(!s.isEmpty())
    {
        q.Enqueue(s.Pop());
        q.Enqueue(q.Dequeue());
    }
    q.print_all_elements();
}
int main()
{
    
    Queue q(20);
    Queue q2(10);

    q.Enqueue(11);
    q.Enqueue(12);
    q.Enqueue(13);
    q.Enqueue(14);
    q.Enqueue(15);
    q.Enqueue(16);
    q.print_all_elements();

    Inter_leaving(q);
    
  
    
    return 0;
}