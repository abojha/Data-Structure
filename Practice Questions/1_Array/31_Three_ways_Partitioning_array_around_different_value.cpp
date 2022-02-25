#include<bits/stdc++.h>
using namespace std;

void print_array(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void three_ways_partitioning(int *arr, int highVal, int lowVal, int n)
{
    //Initialize ext available position for
    // smaller (than range) and greater elements
    int start = 0, end = n-1;

    // Traverse elements from left
    for(int i = 0; i <= end;)
    {
        //if current element is smaller 
        // than range, put it on next
        // available position.
        if(arr[i] < lowVal)
        {
            //if i and start are same then we can't swap.
            // swap only when i is greater than start
            if(i == start)
                i++, start++;
            else{
                swap(arr[i++], arr[start++]);
            }
        }
            // if current element is greater
            // than range, put it on the 
            // next available greater position
        else if(arr[i] > highVal)
        {
            swap(arr[i], arr[end--]);
        }
        else
            i++;
    }
}
int main()
{
    int arr[] = {1, 14, 5, 20, 4, 2, 5, 54, 20, 87};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout << " Your array is " << endl;
    print_array(arr, size);

    three_ways_partitioning(arr, 20, 10, size);


    print_array(arr, size);
    return 0;
}