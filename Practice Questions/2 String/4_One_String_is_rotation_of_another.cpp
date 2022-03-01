#include<bits/stdc++.h>
using namespace std;

bool are_rotaions(string &s1, string &s2)
{
    if(s1.size()!=s2.size())
        return false;
    
    // concatenat the s1 with s1
    string temp = s1 + s1;

    //if s2 is the substring of temp
    // then they are roation of each other

    return (temp.find(s2) != string :: npos);

}

bool are_rotaions_by_STL(string &s, string &goal)
{
    if(s.size()!=goal.size())
        return false;
    
    queue<char> q1, q2;

    for(int i = 0; i < s.size(); i++)
    {
        q1.push(s[i]);
    }
    for(int i = 0; i < goal.size(); i++)
    {
        q2.push(goal[i]);
    }

    int k = goal.size();

    while(k--)
    {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);

        if(q1 == q2)
            return true;
    }
    return false;
}
int main()
{   
    string a = "ABCD";
    string b = "BCDA";

    if(are_rotaions_by_STL(a, b))
        cout << "String are roation of each other" << endl;
    else
        cout << "Strings are not rotation of each other " << endl;
    
    return 0;
}