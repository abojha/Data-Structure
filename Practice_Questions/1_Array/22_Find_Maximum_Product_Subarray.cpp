#include<bits/stdc++.h>
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

/* ************************Naive Method*******************************
    ---------------------Time Complexity = O(N^2)----------------------
    ---------------------Space Complexity = O(1)-----------------------
*/

int maxSubarrayProduct(int *arr, int n)
{
    //Initialize result
    int result = arr[0];

    for(int i = 0; i < n; i++)
    {
        int mul = arr[i];

        // traversing in current subarray
        for(int j = i + 1; j < n; j++)
        {

            //update result evertime to keep eye over maximum product
            result = max(result, mul);
            mul *= arr[j];
        }
        //Updating the product for (n-1) index
        result = max(result, mul);
    }
    return result;
}

int maxProductSubarrays_(int *arr, int n)
{
    int Max = 1;
    int res = 1;
    int Min  = 1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i]>0)
        {
            Max *= arr[i];
            Min = min(1, Min*arr[i]);
        }

        else if(arr[i] == 0)
        {
            Max = Min = 1;
        }
        else{
            swap(Min, Max);
            Min *= arr[i];
            Max = max(1, arr[i]*Max);
        }
        res = max(Max, res);
    }
    return res;
}
int main()
{
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    
    cout<<maxProductSubarrays_(arr, 7);
    return 0;
}