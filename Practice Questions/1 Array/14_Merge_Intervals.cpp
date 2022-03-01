#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

struct Intervals
{
    int start;
    int end;
};
bool compare(Intervals i1, Intervals i2)
{
    return (i1.start < i2.start);
}

///////////////////////////Time Complexity = O(NlogN)///////////////////////////
///////////////////////////Space Complexity = O(N)//////////////////////////////
void MergeIntervals(Intervals *arr, int n)
{
    sort(arr, arr+n, compare);
    stack<Intervals> s;
    s.push(arr[0]);

    for(int i = 1; i < n; i++)
    {
        Intervals top = s.top();
        
        if(top.end < arr[i].start)
        {
            s.push(arr[i]);
        }
        else if(top.end < arr[i].end)
        {
            top.end = arr[i].end;
            s.pop();
            s.push(top);
        }
    }

    while(!s.empty())
    {
        Intervals top = s.top();
        cout<<"Start = "<<top.start<<"   "<<"End = "<<top.end<<endl;
        s.pop();
    }
}


void Merge_Interval(Intervals *arr, int n)
{
    sort(arr, arr+n, compare);
    int index = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(index != 0 && arr[index-1].start <= arr[i].end)
        {
            while(index!=0 && arr[index-1].start <= arr[i].end)
            {
                arr[index-1].end = max(arr[index-1].end, arr[i].end);
                arr[index-1].start = min(arr[index-1].start, arr[i].start);
                index--;
            }
        }
        else
        {
            arr[index] = arr[i];
        }
        index++;
    }

    for(int i= 0; i < index; i++)
    {
        cout<<arr[i].start <<" "<<arr[i].end<<endl;
    }
}
int main()
{
    Intervals arr[] = { {6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int n = sizeof(arr)/sizeof(arr[0]);
    Merge_Interval(arr, n);
    return 0;
}