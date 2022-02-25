#include<bits/stdc++.h>
using namespace std;

void print_array(int *arr, int size)
{
    printf("This is Your Array\n");
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void create_array(int *arr, int size)
{
    cout << "Enter the elements of array\n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void alter_pos_and_neg(int *arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            for(int j = i; j < n; j++)
            {
                if(arr[j] > 0)
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        else
        {
            for(int j = i; j < n; j++)
            {
                if(arr[j] < 0)
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

//partition the negative and positive elements by pivot as 0
int partition(int *arr, int n)
{
    int j = 0;
    int pivot = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] < pivot)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return j;
}

void alter_pos_neg(int *arr, int n)
{
    int p = partition(arr, n);

    //  after partition, swap alternate negative element
    // by available positive elements till all the elements get exhausted
    for(int i = 0; (p < n && i < p); p++, i+=2)
        swap(arr[i], arr[p]);
}
int main()
{
    int arr[5] = {-2, 5, 2, -7, 8};
    print_array(arr, 5);
    // alter_pos_and_neg(arr, 5);
    alter_pos_neg(arr, 5);
    print_array(arr, 5);
    return 0;
}