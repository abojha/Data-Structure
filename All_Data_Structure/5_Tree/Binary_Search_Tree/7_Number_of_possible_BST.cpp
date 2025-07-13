#include<iostream>
#include"1_Binary_Search_Tree.cpp"
using namespace std;


int CountTrees(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    else
    {
        int sum = 0;
        int left, right, root;

        for(root = 1; root <= n; root++)
        {
            left = CountTrees(root-1);
            right = CountTrees(n-root);

            sum+=left*right;
        }
        return (sum);
    }
}
int main()
{
    cout<<CountTrees(3);

    return 0;
}
