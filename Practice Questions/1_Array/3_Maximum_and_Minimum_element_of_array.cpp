#include<iostream>
using namespace std;


int max_element(int *arr, int size)
{
    int max = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }
    return max;
}
int min_element(int *arr, int size)
{
    int min = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(min > arr[i])
            min = arr[i];
    }
    return min;
}
int main()
{
    
    int array[10];
    int Size = 10;

    for(int i = 0; i < 10; i++)
    {
        cin>>array[i];
    }

    for(int i = 0; i < 10; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<"Maximum element is :: "<<endl;
    cout<<max_element(array, Size)<<endl;
    cout<<"Minimum element is :: "<<endl;
    cout<<min_element(array, Size)<<endl;
    return 0;
}