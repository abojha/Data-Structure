#include<bits/stdc++.h>
using namespace std;


                            //     "HashMap Method" 
                            // "Time Complexity = O(N)"
                            // "Space Complexity = O(N)"
int element_appear_more_Than_ndk_times(int *a, int n, int k)
{
    unordered_map<int, int> m;
    int x = n/k;

    for(int i = 0; i < n; i++)
        m[a[i]]++;
    
    for(auto &ele : m)
    {
        if(ele.second > x)
            cout<<ele.first<<" "<<ele.second<<endl;
    }
}


int main()
{
    int a[] = {1, 2, 3, 3, 4, 2, 1, 5, 4, 2, 1, 5, 7, 2, 3, 3};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 5;

    element_appear_more_Than_ndk_times(a, n, k);
    return 0;
}