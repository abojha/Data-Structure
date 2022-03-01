#include<bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include<set>
using namespace std;

void print_array(int *arr, int size)
{
    printf("This is Your Array\n");
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void create_array(int *arr, int size)
{
    cout << "Enter the elements of array\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

/* ********************** Direct  Method*******************************
    --------------Time Complexity = O(u) + O(v) + O(w)-----------------
    ---------------------Space Complexity = O(1)-----------------------
*/
// void find_common_elements(int *a1, int *a2, int *a3, int u, int v, int w)
// {
//     int x = 0, y = 0, z = 0;
//     while(x < u && y < v && z < w)
//     {
//         if(a1[x] == a2[y] && a2[y] == a3[z])
//         {
//             cout<<a1[x]<<" ";
//             x++, y++, z++;
//         }
//         else if(a1[x] < a2[y])
//         {
//             x++;
//         }
//         else if(a2[y] < a3[z])
//         {
//             y++;
//         }
//         else
//         {
//             z++;
//         }
//     }
// }

/* The above approach works well but it creates problem whenever there is
    duplicate elements, it prints duplicate elements multiple times
    we can solve this problem by keeping track on previous elements of
    each array
*/

void find_common_elements(int *a1, int *a2, int *a3, int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    int prev1, prev2, prev3;
    prev1 = prev2 = prev3 = INT16_MIN;

    // Iterate through while all array have elements
    while (i < n1 && j < n2 && k < n3)
    {
        while (prev1 == a1[i] && i < n1)
            i++;
        while (prev2 == a2[i] && i < n2)
            j++;
        while (prev3 == a3[i] && i < n3)
            k++;

        if (a1[i] == a2[j] && a2[j] == a3[k])
        {
            cout << a1[i] << " ";
            prev1 = a1[i];
            prev2 = a2[j];
            prev3 = a3[k];
            i++, j++, k++;
        }
        else if (a1[i] < a2[j])
        {
            prev1 = a1[i];
            i++;
        }
        else if (a2[j] < a3[k])
        {
            prev2 = a2[j];
            j++;
        }
        else
        {
            prev3 = a3[k];
            k++;
        }
    }
}

/* ********************** by SET STLMethod*******************************
    --------------Time Complexity = O(u) + O(v) + O(w)-----------------
    --------------Space Complexity = O(u) + O(v) + O(W)----------------
*/

void find_common_by_Multiset(int *a1, int *a2, int *a3, int n1, int n2, int n3)
{
    unordered_set<int> uset, uset2, uset3;

    for(int i = 0; i < n1; i++)
    uset.insert(a1[i]);
    for(int i = 0; i < n2; i++)
    uset2.insert(a2[i]);

    for(int i= 0; i < n3; i++)
    {
        if(uset.find(a3[i]) != uset.end() && uset2.find(a3[i]) != uset2.end())
        {
            if(uset3.find(a3[i]) == uset3.end())
            {
                cout<<a3[i]<<" ";
            }
            uset3.insert(a3[i]);
        }
    }
}
int main()
{
    int a1[5] = {1, 2, 2, 5, 6};
    int a2[7] = {2, 2, 6, 8, 10, 12, 14};
    int a3[4] = {2, 2, 8, 10};
    // find_common_elements(a1, a2, a3, 5, 7, 4);
    find_common_by_Multiset(a1, a2, a3, 5, 7, 4);

    return 0;
}
