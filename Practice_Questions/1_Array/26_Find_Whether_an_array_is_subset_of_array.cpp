#include<bits/stdc++.h>
using namespace std;

/*
                                "Simple Method"
                            "Time Complexity = O(mn)"
                            "Space Complexity = O(1)"
*/
bool is_arr2_is_subset_of_arr1(int *arr1, int *arr2, int m, int n)
{
    int i = 0;
    int j = 0;
    for( i = 0; i < n; i++)
        for( j = 0; j < m; j++)
            if(arr2[i] == arr1[j])
                break;
    //if the inner loop will not break this means 
    // atleast one element is ther in arr2
    // which is not present in arr1
    if(j == m)
        return 0;
    
    // if we reach these level then arr2 is
    // subset of arr1
    return 1;
}
/*
                                "Hashmap Method"
                            "Time Complexity = O()"
                            "Space Complexity = O()"
*/
bool ByHashmap(int *arr1, int *arr2, int m, int n)
{
    unordered_set<int> s;

    for(int i = 0; i < m; i++)
        s.insert(arr1[i]);

    
    for(int i = 0; i < n; i++)
    {
        if(s.find(arr2[i]) == s.end())
            return 0;
    }
    return 1;
}
/*
                        "Sorting and Merging Method"
                        "Time Complexity = O(mlogm + nlogn)"
                        "Space Complexity = O()"
*/
bool SortingAndMerging(int *arr1, int *arr2, int m, int n)
{
    //Sort both the arrays
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);

    int i = 0;
    int j = 0;

    while(i < n && j < m)
    {
        // if arr1 value is smaller then increment the index
        if(arr1[j] < arr2[i])
            j++;
        
        // if both are equal then increment both the idices
        else if(arr1[j] == arr2[i])
            i++, j++;

        // if arr1 present value is greater than arr2 present value 
        // return 0
        else 
            return false;
    }
    return (i < n) ? false : true;
}
int main()
{
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};  

    if(SortingAndMerging(arr1, arr2, 6, 4))
        cout<<"Array2 is subset of Array1"<<endl;

    else
        cout<<"Array2 is not subset of Array1"<<endl;
    return 0;
}