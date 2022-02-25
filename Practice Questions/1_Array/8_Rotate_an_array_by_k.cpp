#include<iostream>
using namespace std;

void print_array(int *arr, int size)
{
    printf("This is Your Array\n");
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
void create_array(int *arr, int size)
{
    cout<<"Enter the elements of array\n";
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
}

void rotate(int *arr, int n, int k)
{
    k = k%n;
    
    for(int i = 0; i < n; i++)
    {
        if(i < k)
        {
            cout<<arr[n+i-k]<<" ";
        }
        else 
        {
            cout<<arr[i-k]<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    int array[] = {1, 2, 3, 4, 5};

    print_array(array, 5);

    rotate(array, 5, 2);

    return 0;
}