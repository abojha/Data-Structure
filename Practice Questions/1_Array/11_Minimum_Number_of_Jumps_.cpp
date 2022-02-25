#include<iostream>
#include<vector>
using namespace std;


///////////////////// time complexity O(N) //////////////////////////////
///////////////////// space complexity O(1) //////////////////////////////
bool canJump(vector<int> & nums) {
    int n = nums.size();
    int reachable = 0;

    for(int i = 0; i < n; i++)
    {
        if(reachable < i)
        return false;

        reachable = max(reachable, i + nums[i]);
    }
    return true;
}
int main()
{
    vector<int> a;
    int i = 0;
    while(i < 5)
    {
        int c;
        cin>>c;
        a.push_back(c);
        i++;
    }
    // for(int i = 0; i < 5; i++)
    // {
    //     cout<<a[i]<<" ";
    // }

    cout<<canJump(a);
                
    return 0;
}