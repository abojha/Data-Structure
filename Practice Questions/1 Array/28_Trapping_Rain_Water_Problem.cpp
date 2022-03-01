#include<bits/stdc++.h>
using namespace std;


// Trapped water for a block 
    //  = (waterlevel - block ht)* width
/*
    Base Cases:-
    1. Block (elements) must be greater or equal to 3 in number to trap water
    2. Block in increasing (or decreasing) order not able to trap water
    3. Amount of trapped water will depend on min. boundary height
        min(left_boundary, right_boundary)
    4. How pockets trap water
        Trapped water = min(max_left_boundary_of_current, max_right_boundary_of_current) - (height of current)
*/

class Solution 
{
    public:
        int trap(vector<int> &height)
        {
            int n = height.size();
            if(n <= 2) // we need atleast 3 bars to be able to trap water
                return 0;
            
            vector<int> left(n), right(n);
            left[0] = 0;
            int leftMax = height[0];
            for(int i = 1; i < n; i++) //store the leftmax for each bar
            {
                left[i] = leftMax;
                leftMax = max(leftMax, height[i]);
            }
            right[n-1] = 0;
            int rightMax = height[n-1];
            for(int i = n-1; i >= 0; i--)
            {
                right[i] = rightMax;
                rightMax = max(rightMax, height[i]);
            }

            // calculate the trapped_water for each block and sum up
            int trappedwater = 0;
            for(int i = 1; i < n; i++)
            {
                if(height[i] < left[i] and height[i] < right[i])
                {
                    trappedwater += min(left[i], right[i]) - height[i];
                }
            }
            return trappedwater;
        }

};

// O(1) space solution
class Solution2 
{
    public:
    int trap(vector<int> &height)
    {
        int trappedwater = 0;
        int n = height.size();
        int leftMax = height[0];
        int rightMax = height[n-1];
        int left = 1;   // left pointer
        int right = n-2;  // right pointer
        while(left <= right)
        {
            if(leftMax <= rightMax) // we want boundary of minimum height 
            {
                if(height[left] > leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    trappedwater += leftMax - height[left];
                    
                }
                left += 1;
            }
            else
            {
                if(height[right] > rightMax)
                {
                    rightMax = height[right];
                }
                else
                {
                    trappedwater += rightMax - height[right];
                }
                right -= 1;
            }
        }
        return trappedwater;
    }
};
int main()
{
    vector<int> h = {4, 2, 0, 3, 2, 5};
    Solution ab;
    cout<<ab.trap(h);

    Solution2 ab2;
    cout<<ab2.trap(h);

    return 0;
}