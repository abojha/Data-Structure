#include <bits/stdc++.h>
using namespace std;

// Function to check whether the string1 is
// shuffled of string2


//Time complexity = O(m * n * logn) => m is size of second string, n is size of first string
bool is_shuffled(string s1, string s2)
{
    // n is the length of first string
    int n = s1.length();
    // m is the length of second string
    int m = s2.length();

    if (n > m)
    {
        return false;
    }
    else
    {
        // sort the first string
        sort(s1.begin(), s1.end());

        // Initialize the second string
        for (int i = 0; i < m; i++)
        {
            if ((i + n - 1) >= m)
                return false;
            // create a empty string
            string str = "";

            // Now choose characters equal to string1
            //  from string2 and copy them to str

            for (int j = 0; j < n; j++)
                str.push_back(s2[i + j]);

            //sort the str
            sort(str.begin(), str.end());

            if (str == s1)
                return true;
        }
    }
}

//Another method is efficient
int main()
{
    string s1 = "onetwofour";
    string s2 = "hellofourtwooneworld";

    if(is_shuffled(s1, s2))
        cout << "1 is substring shuffled of 2";
    
    else
        cout << "Aisa kuch nahi hai" << endl;
    return 0;
}