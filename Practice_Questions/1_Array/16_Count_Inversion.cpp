#include<iostream>
#include<bits/stdc++.h>
#include<set>
#include<algorithm>
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
void count_Invertsion(int *arr, int n)
{
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
                count++;
        }
    }

    cout<<"Coutning Inversion :: "<<count<<endl;
}


/* **********************Merge Sort Method*******************************
    ---------------------Time Complexity = O(NlogN)----------------------
    ---------------------Space Complexity = O(1)-------------------------
*/
/* ********************** Multiset Method********************************
    ---------------------Time Complexity = O(N^2)------------------------
    ---------------------Space Complexity = O(1)-------------------------
*/
void count_Inversions(int *arr, int n)
{
    multiset<int> s1;

    int inv_count = 0;
    s1.insert(arr[0]);

    multiset<int> :: iterator iter;


    for(int i = 1; i < n; i++)
    {
        s1.insert(arr[i]);

        iter = s1.upper_bound(arr[i]);


        inv_count += distance(iter, s1.end());

    }

    cout<<inv_count<<endl;
}



int main()
{
    int arr[5];

    create_array(arr, 5);
    print_array(arr, 5);

    // count_Invertsion(arr, 5);
    count_Inversions(arr, 5);
    return 0;
}