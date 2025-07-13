#include<iostream>
using namespace std;

int main()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int rev_array[10];
    int b = 0;

//Print the original array
    cout<<"Original Array\n";
    for(int i = 0; i < 10; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
//Now reverse the array and stored in rev_array
    cout<<"Reversing the array............."<<endl;
    for(int i = (10-1); i >= 0; i--)
    {
        rev_array[b] = array[i];
        b++;
    }

    cout<<"its done\n";

//Now print the reversed array
    cout<<"Reverse array \n";
    for(int i = 0; i < 10; i++)
    {
        cout<<rev_array[i]<<" ";
    }
    return 0;
}