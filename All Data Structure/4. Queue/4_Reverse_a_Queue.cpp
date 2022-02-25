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
    friend Queue reverse_the_queue(Queue q);
};
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
Queue reverse_the_queue(Queue q)
{
    stack<int> s;
    while (!q.isEmpty())
    {
        s.push(q.Dequeue());
    }
    while (!s.empty())
    {
        q.Enqueue(s.top());
        s.pop();
    }
    return q;
}
int main()
{
    Queue q(2);
    q.Enqueue(500);
    q.Enqueue(1000);
    q.print_all_elements();

    q = reverse_the_queue(q);
    q.print_all_elements();

    return 0;
}