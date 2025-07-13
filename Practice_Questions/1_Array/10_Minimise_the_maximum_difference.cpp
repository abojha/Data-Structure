#include<iostream>
#include<algorithm>
#include<math.h>
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
int Minimise(int *arr, int n)
{
    int k = 3;
    sort(arr, arr+n);

    int ans = arr[n-1] - arr[0];
    int smallest = arr[0] + k;
    int largest = arr[n-1] - k;

    for(int i = 0; i < n-1; i++)
    {
        int Min = min(smallest, arr[i+1]-k);
        int Max = max(largest, arr[i] + k);

        if(Min < 0)
        continue;

        ans = min(ans, Max-Min);
    }
    return ans;
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
    int array[] = {1, 5, 10, 15};

    print_array(array, 4);
    cout<<Minimise(array, 4);

    
    
    return 0;
}