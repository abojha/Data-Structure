#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a;
    a = {2, 3, 4, 5};

    int k = 2;

    k = k%4;

    for(int i = 0; i < 4; i++)
    {
        if(i < k)
        {
            cout << a[4+i-k] << " ";
        }
        else
            {
                cout << a[i-k] << " ";
            }
    }
    
    return 0;
}