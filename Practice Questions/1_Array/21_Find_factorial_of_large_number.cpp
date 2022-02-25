#include<bits/stdc++.h>
#define Max 500
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

// int factorial(int n)
// {
//     if(n < 1)
//     return 1;

//     return n * factorial(n-1);
// }
// int large_element(int *arr, int n)
// {
//     int max = 0;
//     for(int i= 0; i < n; i++)
//     {
//         if(max < arr[i])
//         max = arr[i];
//     }
//      return factorial(max);
// }

// Multiply function declaration
int multiply(int x, int *res, int res_size);

void fact(int n)
{
    int res[Max];

    // Initialize result
    res[0] = 1;
    int res_size = 1;
    
// Apply simple factorial formula n! = 1 * 2 * 3 * .... * n
    for(int x = 2; x<=n; x++)
    {
        res_size = multiply(x, res, res_size);
    }
    
    for(int i = res_size-1; i >= 0; i--)
    {
        cout<<res[i];
    }
    cout<<endl;
}

// this function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the 
// number respresented by res[]. this function uses simple
// school mathematics for multipilcation.
// This function may value of  res_size and returns the 
// new value of res_size.
int multiply(int x, int *res, int res_size)
{
    int carry = 0; //Initialize carry to 0

    // One by one multiply n with individual digit of res[].
    for(int i = 0; i < res_size; i++)
    {
        int product = res[i] * x + carry;

        // Store last digit of product in res[].
        res[i] = product%10;

        // Put rest in carry
        carry = product/10;
    }

    //Put carry in res and increase result size
    while(carry)
    {
        res[res_size] = carry % 10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

// Driver Program
int main()
{
    
    fact(6);
    fact(5);
    fact(100);
    
    return 0;
}