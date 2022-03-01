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

void _find_sum_zero(int *arr, int n)
{
    int curr_sum = 0;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        curr_sum += arr[i];
        if(curr_sum == 0)
        {
            cout<<"yes"<<endl;
            break;
        }
    }
}

/* ************************Hashing Method********************************
    ---------------------Time Complexity = O(N)-------------------------
    ---------------------Space Complexity = O(N)-------------------------
*/
bool find_sum(int *arr, int n)
{
    unordered_set<int> s;
    int curr_sum = 0;
    for(int i = 0; i < n; i++)
    {
        curr_sum += arr[i];

        //If curr_sum == 0 or it is already present
        if(curr_sum == 0 || s.find(curr_sum) != s.end())
        {
            return true;
        }
        s.insert(curr_sum);
    }
    return false;
}
int main()
{
    int arr[] = {23, 45, -23, -45, 7};
    // _find_sum_zero(arr, 5);
    cout<<find_sum(arr, 5);

    return 0;
}