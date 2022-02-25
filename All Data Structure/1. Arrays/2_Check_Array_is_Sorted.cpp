#include<iostream>
using namespace std;

int is_array_sorted(int *A,int n)
{
    if(n==0||n==1)
    {
        return 1;
    }
    return ( *(A+n-1) < *(A+n-2) ? 0 : is_array_sorted(A,n-1));
}
int main()
{
    int array[3] = {7,11,8};
    int check;
    
    if(is_array_sorted(array,3))
    {
        cout<<"Array is sorted"<<endl;

    }
    else{
        cout<<"Arra is not sorted"<<endl;
    }
    
    return 0;
}