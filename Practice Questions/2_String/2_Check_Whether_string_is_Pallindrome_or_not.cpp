#include<bits/stdc++.h>
using namespace std;

//1. compare one half with other
bool my_method(string &s)
{
    // calculate the length of string
    int n = s.length();

    //run loop till half
    // compare the current char with 
    // its equivalent char from last
    // if they are not equal at any point
    // then string will not be pallindrome
    for(int i = 0; i < n/2; i++)
    {
        if(s[i] != s[n-i-1])
            return false;
    }

    //here string become pallindrome
    return true;
}

bool reverse_and_compare_rule(string &s)
{
    //copy given string into new variable here r
    string r = s;
    
    //reverse the given string
    reverse(s.begin(), s.end());

    //compare now with copied variable
    if(s==r)
        //if same then return true
        return true;
    else
        // if not same then return false
        return false;

    
}
int main()
{
    string s = "abcaba";

    // if(my_method(s))
    // {
    //     cout << "Stirng is Pallindrome" << endl;
    // }
    // else
    // {
    //     cout << "String is not Pallindrome" << endl;
    // }


    if(reverse_and_compare_rule(s))
    {
        cout << "Stirng is Pallindrome" << endl;
    }
    else
    {
        cout << "String is not Pallindrome" << endl;
    }
    return 0;
}