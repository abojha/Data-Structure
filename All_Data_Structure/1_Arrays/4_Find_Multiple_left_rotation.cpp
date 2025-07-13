#include<iostream>
using namespace std;
void preprocess(int arr[], int n,int temp[])
{
    for(int i = 0; i < n; i++)
    {
        temp[i] = temp[i+n] = arr[i];
    }
            
}
void reverseleft(int temp[],int k, int n)
{
    int start = k%n;
    for(int i = start; i < start+n; i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;

}
int main()
{
    int size;
    int *arr;
    int *temp;
    int k;
    arr = new int[size];
    temp = new int[2*size];
    cout<<"Enter the size of array:\n";
    cin>>size;
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    for(int i = 0; i < size; i ++)
    {
        cout<<arr[i]<<" ";
    }
    
    cout<<"\nEnter the rotation point:\n";
    cin>>k;
    preprocess(arr,size,temp);
    reverseleft(temp,k,size);
    return 0;
}