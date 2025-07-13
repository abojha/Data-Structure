#include<iostream>
#define size 5
using namespace std;

void print_an_array(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int max(int *a, int n)
{
    int max = a[0];
    for(int i = 0; i  < n; i++)
    {
        if(max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}
void CountSort(int *a, int n)
{
    int j = 0;
  int max_ele = max(a,n);
  int size_of_count_array = max_ele +1;

  int *count_array = new int[size_of_count_array];
  for(int i = 0; i < size_of_count_array; i++)
  {
      count_array[i] = 0;
  }

  for(int i = 0; i < n; i++)
  {
      count_array[a[i]]++;
  }

    for(int i = 0; i < size_of_count_array; i++)
    {
        if(count_array[i]!=0)
        {
            a[j] = i;
            count_array[i]--;
            i--;
            j++;
        }
    }

  

}
int main()
{
    int arr[size];

    for(int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    print_an_array(arr,size);
    // Bubble_Sort(arr);
    CountSort(arr,size);
    print_an_array(arr,size);
    

    return 0;
}