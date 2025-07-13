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

///////////////////////////////// This is Kadane's Algorithm /////////////////////////////
//////////////////////////////// Time Complexity = O(N) /////////////////////////////////
int Largest_sum_Contiguous_Subarray(int *arr, int n)
{
    int curr_sum =  0;
    int max_sum = 0;

    for(int i = 0; i < n; i++)
    {
        curr_sum = curr_sum + arr[i];
        if(curr_sum > max_sum)
        {
            max_sum = curr_sum;
        }
        if(curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return max_sum;
}
void create_array(int *arr, int size)
{
    cout<<"Enter the elements of array\n";
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
}

int main()
{
    int array[] = {1, 2, -3, 4, -5};

    print_array(array, 5);

    cout<<Largest_sum_Contiguous_Subarray(array, 5);
    
    return 0;
}