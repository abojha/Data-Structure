#include<iostream>
#define size 5
using namespace std;

void print_an_array(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void Bubble_Sort(int *A)
{
    int temp;
    for(int i = 0; i < size-1; i++) //for number of passes
    {
        for(int j = 0; j < size-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}
void Advanced_Bubble_sort(int *a)
{
    int temp;
    int isSorted;
    for(int i = 0; i < size-1; i++)
    {
        isSorted = 1;
       
        for(int j = 0; j < size-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                isSorted = 0;
            }
        }
        if(isSorted == 1)
        {
            break;
        }
    }
}
int main()
{
    int arr[size];

    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    print_an_array(arr,size);
    // Bubble_Sort(arr);
    Advanced_Bubble_sort(arr);
    print_an_array(arr,size);
    

    return 0;
}