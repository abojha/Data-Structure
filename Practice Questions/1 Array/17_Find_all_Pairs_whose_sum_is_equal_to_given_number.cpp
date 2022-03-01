#include<bits/stdc++.h>
#include<map>
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
/* **********************Brute force Method*******************************
    ---------------------Time Complexity = O(N^2)-------------------------
    ---------------------Space Complexity = O(1)-------------------------
*/
void Possible_Pairs_sum(int *arr, int n, int sum)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] + arr[j] == sum)
            {
                cout<<"Pair found :: "<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }
}

/* **********************Map STL  Method*******************************
    ---------------------Time Complexity = O(N)-------------------------
    ---------------------Space Complexity = O()-------------------------
*/
int pair_count(int *arr, int n, int sum)
{
    unordered_map<int, int> m;

    for(int i= 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    int twice_count = 0;

    for(int i = 0; i < n; i++)
    {
        twice_count += m[sum - arr[i]];

        if(m[sum-arr[i]] == arr[i])
        twice_count--;
    }
    return twice_count/2;

}

int Pair_count(int *arr, int n, int sum)
{
    unordered_map<int, int> m;

    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(m.find(sum - arr[i])!= m.end())
        {
            count += m[sum-arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
}
int main()
{
    int a[20];

    create_array(a, 5);
    Possible_Pairs_sum(a,5,10);
    cout<<pair_count(a,5, 10);
    cout<<Pair_count(a,5, 10);
    print_array(a, 5);
    return 0;
}