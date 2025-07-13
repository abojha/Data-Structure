#include<iostream>
#include<set>
using namespace std;


void print_array(int *arr, int size)
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
void Print_Duplicate(int *a, int n)
{
   int fr[n];
    for(int i = 0; i < n; i++)
    {
        fr[i] = 0;
    }
   for(int i = 0; i < n; i++)
   {
       fr[a[i]]++;
   }
   for(int i = 0; i < n; i++)
   {
       if(fr[i] > 1)
       {
           cout<<i<<" ";
       }
   }
}
int main()
{
    int a[5];
    create_array(a, 5);
    print_array(a, 5);

    Print_Duplicate(a, 5);
    return 0;
}