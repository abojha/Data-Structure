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

void rotate(int arr[], int n)
{
    int x = arr[n-1];
    for(int i = n-1; i > 0; i--)
        arr[i] = arr[i-1];
        arr[0] = x;
}
int main()
{
    int array[] = {1, 2, 3, 4, 5};

    print_array(array, 5);

    rotate(array, 5);

    print_array(array, 5);
    return 0;
}