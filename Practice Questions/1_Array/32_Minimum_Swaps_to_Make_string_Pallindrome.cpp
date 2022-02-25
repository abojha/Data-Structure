#include<bits/stdc++.h>
using namespace std;

int countSwaps(string s)
{
    //calculate length of string as n
    int n = s.length();

    //counter to count minimum swaps
    int count = 0;

    //A loop which run till  mid 
    // of string

    for(int i = 0; i < n/2; i++)
    {
        // Left pointer
        int left = 0;

        // Right pointer
        int right = n - left - 1;

        // A loop which run from right
        // pointer to left pointer

        while(left < right)
        {
            //if both characters are same
            // then break the loop
            // otherwise move the right pointer
            // one towards the left
            if(s[left] == s[right])
                break;
            else
                right--;
        }
        //if both pointers are at same
        // position, it denotes that we
        // don't have sufficient characters
        // to make pallindrome string
        if(left == right)
            return -1;
        
        // else swap and increase the counter
        for(int j = right; j < n - left - 1; j++)
        {
            swap(s[j], s[j+1]);
            count++;
        }
    }
    return count;

    
}
int main()
{
    string s = "aabcb";
    int ans1 = countSwaps(s);
   

    cout << ans1;


    return 0;
}