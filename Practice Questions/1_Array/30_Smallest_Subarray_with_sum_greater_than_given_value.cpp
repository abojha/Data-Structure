#include<iostream>
using namespace std;


int SmallestSubarray(int *arr, int n, int k)
{
    //Initialize the length of smalles subarray
    int min_len = n+1;

    
    // Pick ever element as starting point
    for(int start = 0; start < n; start++)
    {
        // Initialize the curr_sum starting with current_start
        int curr_sum = arr[start];

        // If first element itself is greater than the k
        if(curr_sum > k)
            return 1;
        
        //Try different ending points for current start
        for(int end = start+1; end < n; end++)
        {
                // add last element to currrent sun
                curr_sum += arr[end];

                //If sum becomes more than k and lenght of
                // this subarray is smaller than current
                // smallest lenght, then update the smalles lenght

                if(curr_sum > k && (end - start + 1) < min_len)
                {
                    min_len = end - start + 1;

                    for(int i = start; i <= end; i++)
                    {
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                }
        }
    }
    return min_len;

}

int SmallestSubarray1(int *arr, int n, int k)
{
    // Initialize current_sum and min_lenght
    int curr_sum = 0, min_len = n+1;

    // Initialize starting and ending point
    int start = 0, end = 0;

    while (end < n)
    {
        // Keep adding array element while current sum is smaller or equal to k
        while( curr_sum <= k && end < n)
            curr_sum += arr[end++];
        
        // If curr_sum becomes greater than x
        while(curr_sum > k && start < n)
        {
            //update min_length if needed
            if(end - start < min_len)
                min_len = end - start;

            // remove starting elements
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int res = SmallestSubarray1(arr, n, 51);
    
    if(res == n+1)
    {
        cout << "Not Possible\n";
    }
    else
    {
        cout << res << endl;
    }
    return 0;
}