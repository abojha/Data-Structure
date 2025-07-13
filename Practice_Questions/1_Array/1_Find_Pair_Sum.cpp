#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void find_pair_sum(vector<int> &a, int n, int target) //Brute_force method
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] + a[j] == target)
            {
                cout<<"Found\n";
                cout<<a[i]<<" "<<a[j]<<endl;
            }
        }
    }
}

// Sorting Method

void pair_sum(vector<int> &a, int n, int target)
{
    sort(a.begin(), a.end());

    int low = 0;
    int high = n - 1;

    while(low < high)
    {
        if(a[low] + a[high] == target)
        {
            cout<<"Found\n";
            cout<<a[low]<<" "<<a[high]<<endl;
        }

        (a[low] + a[high] < target) ? low++ : high--;
        return;  
    }
    cout<<"Pair Not found\n";

}
int main()
{
    vector<int> a;
    int size;
    cout<<"Enter the size of array\n";
    cin>>size;

    for(int i = 0; i < size; i++)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }
    for(int i = 0; i < size; i++)
    {
       cout<<a[i]<<" ";
    }

   pair_sum(a, size, 5);
    return 0;
}