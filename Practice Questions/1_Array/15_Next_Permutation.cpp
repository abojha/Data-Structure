#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;






void Next_Permutation(vector<int> &nums)
{
    int high_peek = -1;
    int i;
    int n= nums.size();

    //find the high_peek first
    for(i = 1; i < n; i++)
    {
        if(nums[i] > nums[i-1])
            high_peek = i;
    }

    //Check if the sequence is in descending order. if it then return the sequence with sort in ascending order

    if(high_peek == -1)
    {
        sort(nums.begin(), nums.end());
        return;
    }

    // find the number which is lesser than high_peak but greater than highpeak's previous smaller number

    int index = high_peek;
    for(i = high_peek; i < n; i++)
    {
        if(nums[high_peek] > nums[i] && nums[high_peek-1] < nums[i])
        {
            index = i;
        }
    }
    swap(nums[high_peek-1], nums[index]);
    sort(nums.begin() + high_peek, nums.end());

}
void print_array(vector<int> &arr, int size)
{
    printf("This is Your Array\n");
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
void create_array(int *arr, int size)
{
    cout<<"Enter the elements of array\n";
    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
}
int main()
{
    vector<int> ab = {1, 2, 6, 12};

    Next_Permutation(ab);

    print_array(ab, 4);
    return 0;
}