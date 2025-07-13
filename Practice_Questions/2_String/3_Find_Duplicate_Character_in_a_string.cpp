#include <bits/stdc++.h>
using namespace std;

void Duplicate_Character(char s[])
{
    int k = 0;
    int n = strlen(s);
    int fr[n];

    for (int i = 0; i < n; i++)
    {
        fr[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        if (fr[i] == 0)
        {
            fr[i]++;
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    fr[j] = -1;
                    fr[i]++;
                }
            }
        }
    }
    while (k < n)
    {
        if (fr[k] > 1)
        {
            cout << s[k] << " :: " << fr[k] << endl;
        }
        k++;
    }
}

void Dupilcate_character_by_map(string str)
{
    map<char,int> count;

    for(int i = 0; i < str.length(); i++)
        count[str[i]]++;
    
    for(auto it: count)
    {
        if(it.second > 1)
        {
            cout << it.first << " count = " << it.second << endl;
        }
    }
}
int main()
{
    char s[] = "Abhay Ojha";
    Duplicate_Character(s);
    Dupilcate_character_by_map(s);
    return 0;
}