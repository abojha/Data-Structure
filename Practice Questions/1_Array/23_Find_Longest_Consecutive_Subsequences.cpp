#include<bits/stdc++.h>
using namespace std;

void print(int *arr, int size)
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


/*                              "Naive Solution" 
                            "Time Complexity = O(NlogN)"
                            "Space Complexity = O(1)"
*/
int LongestConsecutiveSubsequences(int *arr, int n)
{
    int ans = 1;
    int count = 1;
    // Sort the array
    sort(arr, arr+n);

    // create a vector
    vector<int> v;
    v.push_back(arr[0]);

    // Push the non-repeating elements in vector from array
    for(int i = 1; i < n; i++)
    {
        if(arr[i] != arr[i-1])
        {
            v.push_back(arr[i]);
        }
    }

    for(int i= 0; i < v.size(); i++)
    {
        // If there is contiguous element then increase the counter
        if(v[i] == v[i-1]+1)
            count++;
        
        // if not then reset the counter
        else
            count = 1;
        
        // store max value to ans
        ans = max(ans, count);
    }

    return ans;
    
}


/*                              "HashMap Method" 
                            "Time Complexity = O(N)"
                            "Space Complexity = O(N)"
*/
int LongestConsecutiveSubsequence_ByHashing(int *arr, int n)
{
    int ans = 1;
    // Create a unordered set
    unordered_set<int> s;

    //Insert all the array element in set s
    for(int i= 0; i < n; i++)
        s.insert(arr[i]);

    // Check each possible sequence from the start
    // and then update optimal length

    for(int i = 0; i < n; i++)
    {
        // If current element is starting element
        // of possible sequence
        if(s.find(arr[i]-1) == s.end())
        {
            //Then check for the next element in the sequence
            int next_ele_consec = arr[i];
            // increment j till the consecutive number is getting
            while(s.find(next_ele_consec) != s.end())
                next_ele_consec++;
            
            //Update optimal length for consecutive sequence
            ans = max(ans, next_ele_consec - arr[i]);
        }
    }
    return ans;

}
int main()
{
    int arr[] = {1, 2, 2, 3};
    cout<<LongestConsecutiveSubsequences(arr, 4);
    cout<<LongestConsecutiveSubsequence_ByHashing(arr, 4);
    return 0;
}