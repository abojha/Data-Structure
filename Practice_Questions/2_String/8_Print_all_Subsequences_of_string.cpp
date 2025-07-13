#include<bits/stdc++.h>
using namespace std;

unordered_set<string> st;
void all_subsequences_of_string(string input, string output)
{
    if(input.empty())
    {
        //if the input string is empty print the output string
        cout << output<< endl;
        return;
    }

    //output is passed with including 
    // the first character of input string
    all_subsequences_of_string(input.substr(1), output + input[0]);

    //output is passed without including
    //the first character of input string
    all_subsequences_of_string(input.substr(1), output);
}

void all_subsequence_by_list(string s)
{
    
    for(int i = 0; i < s.length(); i++)
    {
        for(int j = s.length(); j >= 0; j--)
        {
            string sub_str = s.substr(i, j);
            st.insert(sub_str);

            for(int k = 1; k < sub_str.length(); k++)
            {
                string sb = sub_str;

                sb.erase(sb.begin() + k);
                if(st.find(sb) == st.end())
                    all_subsequence_by_list(sb);
            }
        }
    }
}
int main()
{
    // string s = "Ab";

    // all_subsequences_of_string(s, "");
    string s = "Abc";

    all_subsequence_by_list(s);

    for(auto it : st)
    {
        cout << it << endl;
    }


    return 0;
}