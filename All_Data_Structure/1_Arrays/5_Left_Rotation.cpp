#include<iostream>
#include<vector>
using namespace std;

vector<int> rotateLeft(vector<int> arr, int d)
{
    for(int i = 0; i < d; i++)
    {
        arr.push_back(arr[0]);
        arr.erase(arr.begin());
    }
    return arr;
}
int main()
{
    int size,d;
    cin>>size>>d;

    vector<int> arr(size);

    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    vector<int> res = rotateLeft(arr,d);
    for(int x:res)
    {
        cout<<x<<" ";
    }
    return 0;
}