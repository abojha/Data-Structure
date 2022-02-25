#include<bits/stdc++.h>
using namespace std;


// 1. by Swapping the character of string from middle
void reverse_by_swapping(string &s)
{
    // get the length of string
    int len = s.length();

    //Run the loop till half of string
    //Swap the character till half
    for(int i = 0; i < len/2; i++)
    {
        swap(s[i], s[len-i-1]);
    }
}


// 2. By inbuilt function of string "reverse"
void reverse_by_inbuilt(string &s)
{
    reverse(s.begin(), s.end());
}


//3. Reverse of Const string
char * reverse_of_const_string(char const *s)
{
    //Find the length of string
    int len = strlen(s);

    char *rev = new char[len + 1];

    strcpy(rev, s);

    for(int i = 0; i < len/2; i++)
    {
        swap(rev[i], rev[len-i-1]);
    }

    return rev;

}



int main()
{
   const char s[] = "Abhay Ojha";

    cout << s << endl;

    // reverse_by_swapping(s);
    // reverse_by_inbuilt(s);
    cout << reverse_of_const_string(s);
   


    return 0;
}