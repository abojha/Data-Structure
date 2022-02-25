#include<iostream>
using namespace std;

struct Heaps
{
    int *array;
    int capacity; //Size of heap
    int count;  //Number of element in heap
    int heap_type; //Max heap or Min heap
};

struct Heaps * create_a_heap(int capacity, int heap_type)
{
    
    struct Heaps * h = new struct Heaps();
    if(h == NULL)
    {
        cout<<"Memory Error\n";
        return NULL;
    }
    
    h->heap_type = heap_type;
    h->capacity = capacity;
    h->count = 0;
    h->array = new int[h->capacity];
    if(h->array == NULL)
    {
        cout<<"Memory Error\n";
        return NULL;
    }
    return h;
    
}

int Parent(struct Heaps *h, int i)
{
    if(i <= 0 || i >= h->count)
    return -1;

    return (i-1)/2;
}

int left_child(struct Heaps *h, int i)
{
    int left = 2*i + 1;
    if(left >= h->count)
    return -1;

    return left;
}
int right_child(struct Heaps *h, int i)
{
    int right = 2*i + 2;
    if(right >= h->count)
    return -1;

    return right;
}
// To find maximum element in max heap
int max_element(struct Heaps *h)
{
    if(h->count == 0)
    return -1;
    return h->array[0];
}
// To find minimum element in max heap
int min_element(struct Heaps *h)
{
    int min = INT16_MAX;
    if(h->count == 0)
    return -1;

    for(int i = (h->count+1)/2; i < h->count; i++)
    {
        if(h->array[i] < min)
        {
            min = h->array[i];
        }
    }
    return min;


}
void prelocate_down(struct Heaps *h, int i)
{
    
    int l,r,max,temp;
    l = left_child(h,i);
    r = right_child(h,i);

    if(l != -1 && h->array[l] > h->array[i])
    {
        max = l;
    }
    else
    {
        max = i;
    }
    if(r != -1 && h->array[r] > h->array[max])
    {
        max = r;
    }
    if(max != i)
    {

        temp = h->array[i];
        h->array[i] = h->array[max];
        h->array[max] = temp;
    }
    else
    {
        return;
    }
    prelocate_down(h,max);
   
    
}
int delete_element(struct Heaps *h)
{
    int data;
    if(h->count == 0)
    return -1;
    data = h->array[0];
    h->array[0] = h->array[h->count-1];
    h->count--;
    prelocate_down(h,0);
    return data; 


}


void Resize(struct Heaps *h)
{
    int *old_array = h->array;
    h->array = new int(h->capacity*2);

    for(int i = 0; i < h->capacity; i++)
    {
        h->array[i] = old_array[i];
    }
    h->capacity*=2;
    free(old_array);
}
int Insert(struct Heaps *h, int data)
{
    if(h->count == h->capacity)
    Resize(h);
    h->count++;

    int i = h->count-1;

    while(i >= 0 && data > h->array[(i-1)/2])
    {
        h->array[i] = h->array[(i-1)/2];
        i = (i-1)/2;
    }  
    h->array[i] = data;
}

//Destroying the Heap
void Destroy(struct Heaps *h)
{
    if(h==NULL)
    return;
    free(h->array);
    free(h);
    h = NULL;
}
// Heapifying the array
void Build_Heap(struct Heaps *h, int*a, int n)
{
   
    if(h==NULL)
    {
        return;
    }
    while(n>h->capacity)
    {
        Resize(h);
    }
    for(int i = 0; i < n; i++)
    {
        h->array[i] = a[i];
        h->count++;
    }
    
    h->count = n;
    for(int i = (n-1)/2; i>=0; i--)
    {
       
        prelocate_down(h,i);
    }
}

void delete_at_index(struct Heaps *h, int i)
{
    if(i > h->count)
    {
        cout<<"Wrong Position:";
        return;
    }
    int key = h->array[i];
    h->array[i] = h->array[h->count-1];
    h->count--;

    prelocate_down(h,i);
    cout<<"Successfully Deleted the element";

}
int Delete_Kth_element(struct Heaps *h, int k)
{
    for(int i = 0; i < k-1; i++)
    {
        delete_element(h);
    }
    cout<<delete_element(h);
}
int main()
{
    struct Heaps *s;
    s = new struct Heaps();
    s = create_a_heap(5,1);
    int a[] = {23,67,45,32,11};
    Build_Heap(s,a,5);
    
    // cout<<s->array[0];
    // cout<<s->array[1];
    // cout<<s->array[2];
    // cout<<s->array[3];
    //  cout<<max_element(s);
    // // cout<<s->array[left_child(s,0)];
    // // cout<<s->array[right_child(s, 0)];
    // // cout<<s->array[left_child(s,1)];
    // // cout<<s->array[right_child(s,1)];
    // cout<<min_element(s);

    // for(int i  = 0; i < s->count; i++)
    // {
    //     cout<<s->array[i]<<" ";
    // }
    // cout<<s->capacity<<endl;
    // cout<<s->count;
    // delete_at_index(s,10);
    Delete_Kth_element(s,4);
   
    return 0;
}