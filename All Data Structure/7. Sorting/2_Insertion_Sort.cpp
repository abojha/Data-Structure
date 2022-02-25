#include<iostream>
using namespace std;
void printArray(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void insertionSort(int *arr, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int key = arr[i+1];
        int j = i;
        while(j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main()
{
    int array[] = {22,35,12,18,10};
    int size = 5;
    printArray(array,size);
    insertionSort(array,size);
    printArray(array,size);


    return 0;
}