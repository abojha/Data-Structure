#include <iostream>
using namespace std;

struct queue
{
    int f, r;
    int size;
    int *array;
};
struct queue *construct(int n)
{
    struct queue *q;
    q = new struct queue();
    if (!q)
        return NULL;
    else
    {
        q->f = q->r = -1;
        q->size = n;
        q->array = new int[q->size];
        cout << "Queue Created Successfully\n";
        return q;
    }
}
int isEmpty(struct queue *q)
{
    if (q->f == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct queue *q)
{
    if ((q->r + 1) % q->size == q->f)
    {
        return 1;
    }
    return 0;
}
int Enqueue(struct queue *q, int data)
{

    if (isFull(q))
    {
        cout << "queue Overflow\n";
    }
    else
    {
        q->r = (q->r + 1) % q->size;
        q->array[q->r] = data;
        if (q->f == -1)
            q->f++;
    }
}
int Dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        cout << "queue Underflow\n";
    }
    else
    {
        int data;
        data = q->array[q->f];
        if (q->f == q->r)
        {
            q->f = q->r = -1;
        }
        else
            q->f = (q->f + 1) % q->size;
        return data;
    }
}
void Delete_aqueue(struct queue *q)
{
    if (q)
    {
        if (q->array)
            free(q->array);
        free(q);
        cout << "queue deleted Successfully\n";
    }
}
int main()
{
    return 0;
}