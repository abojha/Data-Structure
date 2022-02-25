#include<bits/stdc++.h>
using namespace std;


int Chocolate_distribution(vector<int> &choco_array)
{
    int total_chocolate = 0;
    int n = choco_array.size();
    //Declare two variables array
    // one for left side
    // another for right side.
    // with 1 chocolate each children
    vector<int> left(n, 1), right(n, 1);

    // for left neighbour
    for(int i = 1; i < n; i++)
    {
        // if the curr_child rank is higher than
        // its left_neighbour then curr_child
        // will have one more chocolate than
        // its left_neighnour
        if(choco_array[i] > choco_array[i-1])
        {
            left[i] = left[i-1] + 1;
        }   
    }

    // for right neighbour
    for(int i = n-2; i >= 0; i--)
    {
        // if the curr_child rank is higher than
        // its right_neighbour then curr_child
        // will have one more chocolate than
        // its right_neighnour
        if(choco_array[i] > choco_array[i+1])
        {
            right[i] = right[i-1] + 1;
        }
    }

    for(int i = 0; i < n; i++)
    {
        // Acutal number of chocolate
        // is maximum of right_or_left_ index chocolates
        total_chocolate += max(right[i], left[i]);
    }

    cout<<total_chocolate<<endl;

}
int main()
{
    vector<int> children_rank = {1, 2, 3};
    Chocolate_distribution(children_rank);
    return 0;
} 