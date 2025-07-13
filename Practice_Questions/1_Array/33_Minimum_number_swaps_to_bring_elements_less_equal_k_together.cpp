#include<bits/stdc++.h>
using namespace std;

int countSwaps(int *arr, int n, int k)
{
    int count = 0;
    // Initialize the counter to count 
    // elements which are greater than k
    int bad = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] <= k)
            count++;
    }
    for(int i = 0; i < count; i++)
    {
        if(arr[i] > k)
            bad++;
    }
    int ans = bad;

    for(int i = 0, j = count; j < n; j++, i++)
    {
        if(arr[i] > k)
        {
            --bad;
        }

        if(arr[j] < k)
            ++bad;
        
        ans = min(ans, bad);
    }

    return ans;
}
int main()
{
    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout << countSwaps(arr, n, k);
    return 0;
}