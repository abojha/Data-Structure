#include<bits/stdc++.h>
using namespace std;

void Merge_two_sorted_array_without_extra_space(vector<int> &s1, vector<int> &s2)
{
    int last;
    int i = 0;
    int j = 0;
    int fVSize = s1.size();
    int sVSize = s2.size();

    for(i = sVSize - 1; i >= 0; i--)
    {
        last = s1[fVSize-1];

        for(j = fVSize-2; j >= 0 && s1[j] > s2[i]; j--)
        {
            s1[j+1] = s1[j];
        }

        if(j != fVSize-2 && last > s2[i])
        {
            s1[j+1] = s2[i];
            s2[i]  = last;
        }
    }
}
int main()
{
   vector<int> a, b;

   a = {1, 2, 5, 6, 7};
   b = {3, 4, 8, 9};

   Merge_two_sorted_array_without_extra_space(a, b);

   for(auto x : a)
   {
       cout << x << " ";
   }
   for (auto y : b)
   {
       cout << y << " ";
   }
    
    return 0;
}