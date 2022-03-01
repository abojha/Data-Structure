#include<bits/stdc++.h>
using namespace std;


//Split Binary STring in Substring with equal number of 0s and 1s
int splitString(string &s)
{
    //length of string
    int len = s.length();

    int countzero = 0;//counter for zero
    int countone = 0; // counter for one
    int count = 0; //counter for split

    //Iterate each element of string
    for(int i = 0; i < len; i++)
    {
        //if current char is zero then increment counter for zero
        if(s[i] == '0')
            countzero++;

        //other wise increment counter for one
        else // s[i] == 1
            countone++;
        
        if(countzero == countone)
            count++;
            
    }

    //AT last if countzero is not equal to countone
    // then split is not possible
    if(countzero != countone)
        return -1;
    
    //otherwise return count
    else
        return count;
}

int main()
{
    string s = "0100110101";
    cout << splitString(s);
    return 0;
}