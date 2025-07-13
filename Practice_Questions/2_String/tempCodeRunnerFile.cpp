//Minimise the maximum difference

#include<bits/stdc++.h>
using namespace std;


void Minimise_the_maximum_difference(vector<int> &s)
{
    sort(s.begin(), s.end());

    int ans = s[s.size()-1] - s[0];
    int k = 3;

    int smallest = s[0]+k;
    int largest = s[s.size()-1] - k;

    for(int i = 0; i < s.size()-1; i++)
    {
        int Min = min(smallest, s[i+1] - k);
        int Max = max(largest, s[i] + k);

        if (Min < 0)
            continue;
        
        ans = min(ans, Max - Min);

    }
    cout << ans << endl;
}
int main()
{
    vector<int> a;

    a = {1, 3, 10, 15};

    Minimise_the_maximum_difference(a);
    return 0;
}