#include<bits/stdc++.h>
using namespace std;

int Median_of_Unequal_Sorted_Array(int *arr1, int *arr2, int m, int n)
{
    int i = 0; //pointer to input arr1
    int j = 0; //pointer to input arr2

    int count;
    int m1 = -1, m2 = -1;

    for(count = 0; count <= (m+n)/2; count++)
    {
        m2 = m1;

        if(i != m && j != n)
            m1 = (arr1[i] > arr2[j]) ? arr2[j++] : arr1[i++];
        
        else if(i < m)
            m1 = arr1[i++];
        
        else if (j < n)
            m1 = arr2[j++];

    }

    if((m+n)%2 == 1)
        return m1;
    
    else
        return (m1+m2)/2;
}
int main()
{
    int arr1[] = {900};
    int arr2[] = {5, 8, 10, 20};

    cout << Median_of_Unequal_Sorted_Array(arr1, arr2, 1, 4);
    return 0;
}