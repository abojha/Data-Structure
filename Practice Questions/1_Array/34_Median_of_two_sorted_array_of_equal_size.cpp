#include<bits/stdc++.h>
using namespace std;

int MedianOfTwoSortedArray(int *arr1, int *arr2, int n)
{
    int i = 0; // Current index of arr1[]
    int j = 0; // Current index of arr2[]
    int count;
    int m1 = -1, m2 = -1;

    /*Since there are 2n elements, 
      median will be average of elements
      at index n and n-1 in the array
      after merging arr1 and arr2
    */
    for(count = 0; count <= n; count++)
    {
    /*Below is the handle case where 
    all elements of arr2 are smaller than
    smallest(or first) element of arr1
    */
        if(i == n)
        {
            m1 = m2;
            m2 = arr2[0];
            break;
        }
    
    /*Below is the handle case where 
    all elements of arr1 are smaller than
    smallest(or first) element of arr2
    */
        else if(j == n)
        {
            m1 = m2;
            m2 = arr1[0];
            break;
        }
    // equal sign because if two 
    // arrays have some common elements
        if(arr1[i] <= arr2[j])
        {
            // store the prev median
            m1 = m2;
            m2 = arr1[i];
            i++;
        }

        else
        {
            // store the previous median
            m1 = m2;
            m2 = arr2[j];
            j++;
        }

    }
    return (m1 + m2)/2;
}

int Median_Of_Two_Sorted_Array_equal_size(int *arr1, int *arr2, int n)
{
    int i = n-1;
    int j = 0;

    while(arr1[i] > arr2[j] && i > -1 && j < n)
    {
        swap(arr1[i--], arr2[j++]);
    }
    sort(arr1, arr1+n);
    sort(arr2, arr2+n);

    return (arr1[n-1] + arr2[0])/2;
}
int main()
{
    int arr1[] = {1, 12, 15, 26, 38};
    int arr2[] = {2, 13, 17, 30, 45};

    cout << MedianOfTwoSortedArray(arr1, arr2, 5);
    cout << Median_Of_Two_Sorted_Array_equal_size(arr1, arr2, 5);
    return 0;
}