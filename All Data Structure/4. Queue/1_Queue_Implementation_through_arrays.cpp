#include <iostream>
using namespace std;

struct queue
{
    int *array;
    int size;
    int front;
    int rear;
};
struct queue *creation_of_queue(int n)
{
    struct queue *q;
    q = new struct queue();
    q->size = n;
    q->front = -1;
    q->rear = -1;
    q->array = new int(q->size);

    cout << "Queue Created Successfully\n";
    return q;
}
int isEmpty(struct queue *q)
{
    if (q->front == -1)
    {
        return 1;
    }

    return 0;
}
int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int ENQ(struct queue *q, int data)
{
    if (isFull(q))
    {
        cout << "Queue Overflow, can't insert an element\n";
    }
    else
    {
        q->rear++;
        q->array[q->rear] = data;
        if (q->front == -1)
        {
            q->front = 0;
        }
        cout << q->array[q->rear] << " Insert Successfully\n";
    }
}
int DEQ(struct queue *q)
{
    if (isEmpty(q))
    {
        cout << "Queue Underflow, Nothing to Delete\n";
    }
    else
    {
        int data;

        data = q->array[q->front];
        cout << data << " Delete Successfully\n";
        if (q->front == q->rear) // check whether queue is empty or not
        {
            cout << "Reset" << endl;
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front++;
        }
    }
}
int Rear_Most(struct queue *q)
{
    return q->array[q->rear];
}
int Front_Most(struct queue *q)
{
    return q->array[q->front];
}
int Delete_The_Queue(struct queue *q)
{
    delete[] q;
    cout << "Queue get deleted\n";
}
int main()
{
    int n;
    cout << "Enter the size of queue:\n";
    cin >> n;
    struct queue *Q;
    Q = creation_of_queue(n);
    ENQ(Q, 2);
    ENQ(Q, 5);
    ENQ(Q, 6);
    ENQ(Q, 100);
    cout << Rear_Most(Q) << endl;
    cout << Front_Most(Q) << endl;

    DEQ(Q);
    cout << Rear_Most(Q) << endl;
    cout << Front_Most(Q) << endl;

    Delete_The_Queue(Q);
    ENQ(Q, 5);
    DEQ(Q);

    return 0;
}