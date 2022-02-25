#include<iostream>
#include<algorithm>
using namespace std;


int kth_smallest_element(int *arr, int size, int k)
{
    sort(arr, arr+size);

    cout<<k<<"th smallest element is "<<arr[k-1]<<endl;
}
int kth_largest_element(int *arr, int size, int k)
{
    sort(arr, arr+size, greater<int> ());

    cout<<k<<"th Largest element is "<<arr[k-1]<<endl;
}
int main()
{
    
    int array[10];
    int Size = 10;

    for(int i = 0; i < 10; i++)
    {
        cin>>array[i];
    }

cout<<"Your Array is :: "<<endl;
    for(int i = 0; i < 10; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;

    kth_smallest_element(array, Size, 5);
    kth_largest_element(array, Size, 1);
   
    return 0;
}