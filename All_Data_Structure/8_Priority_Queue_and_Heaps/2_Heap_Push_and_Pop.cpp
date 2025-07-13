#include <iostream>
using namespace std;
#define SIZE 100
int heapsize;
int heap[SIZE];

int Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heap_push(int val)
{
    if (heapsize >= SIZE)
    {
        cout << "Overflow" << endl;
        return;
    }
    heap[heapsize] = val;
    int curr = heapsize;

    while (curr > 0 and heap[(curr - 1) / 2] < heap[curr])
    {
        int temp = heap[curr];
            heap[curr] = heap[(curr - 1) / 2];
            heap[(curr - 1) / 2] = temp;
        curr = (curr - 1) / 2;
    }
    heapsize++;
}

int heap_pop()
{
    if (heapsize <= 0)
    {
        cout << "Underflow\n";
        return -1;
    }
    int curr = 0;
    int popped = heap[0];
    heap[0] = heap[heapsize - 1];
    heapsize--;

    while ((2 * curr + 1) < heapsize) // while we don't reach a leaf node
    {
        int child;
        if ((2 * curr + 2) == heapsize) // if we have only left child
        {
            child = 2 * curr + 1;
        }
        else // if both child are present then find which is maximum
        {
            if (heap[2 * curr + 1] > heap[2 * curr + 2])
                child = 2 * curr + 1;
            else
                child = 2 * curr + 2;
        }
        if (heap[curr] < heap[child])
        {
            int temp = heap[curr];
            heap[curr] = heap[child];
            heap[child] = temp;
            curr = child;
        }
    }
}
    void show_heap()
    {
        for (int i = 0; i < heapsize; i++)
        {
            cout << heap[i] << " " << endl;
        }
    }
    void init()
    {
        heapsize = 0;
    }

    int main()
    {
        init();
        while (1)
        {
            cout << "1.Push.... 2.Pop.... 3.Show_Heap.... 4.Terminate\n";
            int option;
            int element;
            cin >> option;
            switch (option)
            {
            case 1:
                cout << "Enter the element\n";
                cin >> element;
                heap_push(element);
                break;
            case 2:
                cout << "Popped " << heap_pop() << endl;
                break;
            case 3:
                show_heap();
                break;
            default:
                return 0;
            }
        }

        return 0;
    }