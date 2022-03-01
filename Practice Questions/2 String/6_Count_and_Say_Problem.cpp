#include <bits/stdc++.h>
using namespace std;

string count_and_say(int n)
{
    // Base case
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";

    string str = "11"; // start from 2nd position

    for (int i = 3; i <= n; i++)
    {
        // In below previous character is processed
        //  in current iteration there a dummy character
        //  added to make sure that loop runs one extra iteration

        str += '$';

        // get the lenght of string
        int len = str.length();
        int count = 1;
        string temp = "";

        for (int j = 1; j < len; j++)
        {
            if (str[j] != str[j - 1])
            {
                // Append count of str[j-1]
                temp += to_string(count);

                // Append str[j-1]
                temp += str[j - 1];

                // reset count
                count = 1;
            }

            else
                count++;
        }

        str = temp;
    }
    return str;
}
// Another Method

string generator(string str)
{
    //create the empty string
    string ans = "";

    //Create a unordered map to store the frequency of character
    unordered_map<char, int> tempCount;

    for (int i = 0; i <= str.length(); i++)
    {
        //if current element is not present in map
        if (tempCount.find(str[i]) == tempCount.end() && i > 0)
        {
            auto prev = tempCount.find(str[i - 1]);
            ans += to_string(prev->second) + prev->first;
        }
        else
            tempCount[str[i]]++;
    }
    return ans;
}

string countAndSay(int n)
{
    string res = "1";
    for (int i = 1; i < n; i++)
    {
        res = generator(res);
    }
    return res;
}
int main()
{
    cout << countAndSay(3);
    return 0;
}