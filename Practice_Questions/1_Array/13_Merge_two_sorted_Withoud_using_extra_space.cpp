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

void Merge_two_Sorted_array_without_using_extra_space(int *a1, int *a2, int m, int n)
{
    for(int i = n-1; i >= 0; i--)
    {
        int j;
        int last = a1[m-1];

        for(j = m-2; j >= 0 && a1[j] > a2[i]; j--)
            a1[j+1] = a1[j];
        
        if(j != m-2 && last > a2[i])
            a1[j+1] = a2[i];
            a2[i] = last;
    }
}
int main()       
{
    int arr1[6];
    int arr2[5];

    create_array(arr1, 6);
    create_array(arr2, 5);

    Merge_two_Sorted_array_without_using_extra_space(arr1, arr2, 6, 5);

    print_array(arr1, 6);
    print_array(arr2, 5);
    return 0;
}