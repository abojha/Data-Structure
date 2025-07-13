#include<iostream>
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

void sort_array(int *array, int n)
{
    int i = 0,  countzero = 0, countone =  0, counttwo = 0;
    
    while(i < n)
    {
        if(array[i] == 0)
            countzero+=1;
        else if(array[i] == 1)
            countone+=1;
        else
            counttwo+=1;
        i++;

    }

    for(int i = 0; i < countzero; i++)
    {
        array[i] = 0;
    }
    for(int i = countzero; i < countzero+countone; i++)
    {
        array[i] = 1;
    }
    for(int i = countzero+countone; i < n; i++)
    {
        array[i] = 2;
    }

    print_array(array, n);
}


int main()
{
    int array[5];
    create_array(array, 5);
    print_array(array, 5);

    sort_array(array, 5);
    return 0;
}