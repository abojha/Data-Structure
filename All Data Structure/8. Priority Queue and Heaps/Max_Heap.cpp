#include<iostream>
#include<vector>
using namespace std;

void Heapify(vector<int> & heap, int curr, int size)
{
    int largest = curr;
    int l = 2*curr + 1;
    int r = 2*curr + 2;

    if(l < size and heap[l] > heap[largest])
        largest = l;
    if(r < size and heap[r] > heap[largest])
        largest = r;
    if(largest != curr)
    {
        int temp = heap[curr];
        heap[curr] = heap[largest];
        heap[largest] = temp;

        Heapify(heap, largest, size);

    }
}

void Heap_Sort(vector<int>& heap)
{
    //Build Heap (rearrange array)

    for(int i = heap.size()/2 - 1; i >= 0; i--)
        Heapify(heap,0,i);
    
    for(int i = heap.size() - 1; i > 0; i--)
    {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;

        Heapify(heap, 0, i);
    }
}
int main()
{
    vector<int> heap{9, 6, 8, 2, 1, 4, 3};
    Heap_Sort(heap);

    cout<<"Heap in asc order\n";
    for(int i = 0; i < heap.size(); i++)
    {
        cout<<heap[i]<<" ";
    }
    return 0;
}