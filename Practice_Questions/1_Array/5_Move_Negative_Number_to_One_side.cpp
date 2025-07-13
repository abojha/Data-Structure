// Time Complexity = O(N)
// Space Complexity = O(1)


#include<iostream>
#include<algorithm>
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
void Move_negative(int *arr, int size)
{
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] < 0)
        {
            if(i != j)
                swap(arr[i], arr[j]);
                j++;
        }
        
    }
}
int main()
{
    int arr[5];
    create_array(arr, 5);
    print_array(arr, 5);

    Move_negative(arr, 5);
    print_array(arr, 5);

   

    return 0;
}

