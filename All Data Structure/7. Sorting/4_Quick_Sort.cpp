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
int Partition(int *a, int low, int high)
{
    int temp;
    int i = low+1;
    int j = high;
    do{
    while(a[low] >= a[i])
    {
        i++;
    }
    while(a[low] < a[j])
    {
        j--;
    }
    if(i < j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    }while(i < j);
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;
    return j;
}
void QuickSort(int *a, int low, int high)
{
    
    int pivotpos;
    if(low < high)
    {
        pivotpos = Partition(a, low, high);
        QuickSort(a,low, pivotpos-1);
        QuickSort(a,pivotpos+1,high);
    }
    
   
}
int main()
{
    
    
    return 0;
}