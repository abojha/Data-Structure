#include<bits/stdc++.h>
using namespace std;

void printsubstr(string s, int low, int high)
{
    for(int i = low; i <= high; i++)
    {
        cout<< s[i];
    }
}

//Time complexity O(N^3)
//Space complexity O(1)
void LongestPal(string s)
{
    int flag = 1;
    // get the length of string
    int len = s.length();

    int Max_length = 1, start = 0;

    //first loop to traverse each character of string
    for(int i = 0; i < len; i++)
    {
        //second loop to access each substring
        for(int j = i; j < len; j++)
        {   flag = 1;

            //Third loop to check pallindrome
            for(int k = 0; k < (j - i + 1)/2; k++)
                //if not pallidrome then flag become false
                if(s[i+k] != s[j-k])
                    flag = 0;
            

            // if pallindrome
            if(flag && (j - i + 1)>Max_length)
                start = i, Max_length = j - i + 1;
        }
    }
    printsubstr(s, start, start + Max_length - 1);
}


int main()
{
    string s = "Geeks";

    LongestPal(s);
    return 0;
}