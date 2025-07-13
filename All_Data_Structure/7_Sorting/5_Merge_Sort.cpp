#include<iostream>
using namespace std;

void PrintArray(int *a,int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Merge(int *a, int low, int mid, int high)
{
    int b[100];
    int i,j,k;
    i = low;
    j = mid+1;
    k = low;

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        if(a[i] > a[j])
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while(i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while(j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for(int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}
void MergeSort(int *a, int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        MergeSort(a, low, mid);
        MergeSort(a, mid+1, high);
        Merge(a,low,mid,high);

    }
    
}
int main()
{
    int array[] = {22,43,12,45,63};
    int size = 5;
    PrintArray(array,size);
    MergeSort(array,0,size-1);
    PrintArray(array,size);
    return 0;
}