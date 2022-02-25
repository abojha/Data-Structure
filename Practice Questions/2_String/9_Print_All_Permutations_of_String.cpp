#include<bits/stdc++.h>
using namespace std;


//Time complexity o(Time to print only one permutaion * no. of permutation)
// O(n*n!)
void permute(string &s, int l, int r)
{
    //Base case
    if(l == r)
    {
        cout << s << endl;
    }

    for(int i = l; i <= r; i++)
    {
        swap(s[l], s[i]); 

        permute(s, l+1, r);//find combination

        swap(s[l], s[i]); //backtracking
    }
}
int main()
{
     string s = "AB";
     permute(s, 0, 1);
    return 0;
}