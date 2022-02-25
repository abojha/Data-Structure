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
            size = 15;
            array = new int[size];
        }
    public:
        int isEmpty();
        int isFull();
        void Push(int data);
        int Pop();
        void printing();
        friend class Queue;
        friend void Reverse(Queue Q, int k);
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
    if ((r+1)%size == f)
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
        r = (r+1)%size;
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
            f = (f+1)%size;
        cout << "DEqueue Successful\n";
        return data;
    }
}
void Queue ::print_all_elements()
{
    for (int i = ((f+1)%size)-1; i <= r; i++)
    {
        cout << array[i] << " ";
    }
    cout<<endl;
}
void Reverse(Queue q, int k)
{
    if(k > q.Size() || q.isEmpty())
    {
        return;
    }
    else
    {
        Stack s;
        for(int i = 0; i < k; i++)
        {
            s.Push(q.Dequeue());
        }   
        while(!s.isEmpty())
        {
            q.Enqueue(s.Pop());
        }
        for(int i = 0; i < q.Size() - k; i++)
        {
            q.Enqueue(q.Dequeue());
        }
    }
    q.print_all_elements();
}

int main()
{
    Queue q(20);
    q.Enqueue(20);
    q.Enqueue(34);
    q.Enqueue(6);
    q.Enqueue(12);
    q.Enqueue(19);
    q.Enqueue(3);
    q.print_all_elements();
  
    Reverse(q,5);
    return 0;
}