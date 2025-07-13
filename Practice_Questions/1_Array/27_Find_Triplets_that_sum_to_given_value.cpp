#include<bits/stdc++.h>
using namespace std;
/*
                        "Simple Method"
                        "Time Complexity = O(N^3)"
                        "Space Complexity = O(1)"
*/
void find_triplets(int *arr, int n, int sum)
{
    // fix the first element as A[i]
    for(int i = 0; i < n; i++)
    // fix the second element as A[j]
        for(int j = i + 1; j < n; j++)
    // fix the third element as A[k]
            for(int k = j + 1; k < n; k++)
    // if all the three elements' are equal to sum then print them
                if(arr[i] + arr[j] + arr[k] == sum)
                    cout<<"Triplet found :: "<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
}
/*
                        "Sorting Method"
                        "Time Complexity = O(N^2)"
                        "Space Complexity = O(1)"
*/
void Find3Elements(int *arr, int n, int sum)
{
    int left_ptr = 0;
    int right_ptr = 0;

    // sort the array
    sort(arr, arr+n);

    // Now fix the first element
    // and the find other two element
    // with the help of ptrs'

    for(int i = 0; i < n-2; i++)
    {
        // To find the other two elements, start two index
        // from both the cornere of array and increment 
        // them towards each other
        left_ptr = i + 1; // index at the left side of array
        right_ptr = n-1; // index at the right of array
        
        while(left_ptr < right_ptr)
        {
            if(arr[i] + arr[left_ptr] + arr[right_ptr] == sum)
            {
                cout<<"Triplet found :: "<< arr[i]<< " "<<arr[left_ptr]<<" "<<
                arr[right_ptr]<<endl;
            }
            else if(arr[i] + arr[left_ptr] + arr[right_ptr] < sum)
                left_ptr++;
            
            else
                right_ptr--;
        }
    }
}

bool find_3_elements(int *arr, int n, int sum)
{
    // fix the first element as A[i]
    for(int i = 0; i < n-2; i++)
    {
        // create  a set
        unordered_set<int> s;
        int curr_sum = sum - arr[i];
        for(int j = i + 1; j < n; j++)
        {
            if(s.find(curr_sum - arr[j]) != s.end())
            {
                cout<<"Triplet found :: "<< arr[i]<<" "<<arr[j]<<" "
                << (curr_sum - arr[j]);
                return true;
            }
            s.insert(arr[j]);
        }
    }
    return false;
}
int main()
{
    int arr[] = {1, 4, 45, 6, 10, 8};

    find_3_elements(arr, 6, 22);
    return 0;
}