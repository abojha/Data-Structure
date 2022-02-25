#include<iostream>
using namespace std;

void PrintArray(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void SelectionSort(int *A, int n)
{
    int temp;
    for(int i = 0; i < n-1; i++)
    {
        int minIndex = i;
        for(int j = i+1; j < n; j++)
        {
            if(A[minIndex] > A[j])
            {
                minIndex = j;
            }
            
        }
        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}
int main()
{
    int a[] = {25,12,34,96,1};
    int n = 5;

    PrintArray(a, n);
    SelectionSort(a,n);
    PrintArray(a,n);
    return 0;
}