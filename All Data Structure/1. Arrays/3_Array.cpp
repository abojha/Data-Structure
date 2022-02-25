#include <iostream>
using namespace std;

class MyArray
{
    int Used_length;
    int total_length;
    int *ptr = new int[total_length];

public:
    void Create_Array(MyArray* array, int tSize, int uSize);
    void Print_Array(int tSize, int uSize);
    void Insertion_Array(int tSize, int uSize);
    void BinarySearch(int tSize, int uSize);
    void Deletion(int tSize, int uSize);
};
void MyArray::Create_Array(MyArray* array, int tSize, int uSize)
{
    array->ptr;
    total_length = tSize;
    Used_length = uSize;
    if (Used_length > total_length)
    {
        cout << "Enter the length in limits of " << total_length << " elements" << endl;
    }
    else
    {
        cout<<"Enter the elements "<<endl;
        for (int i = 0; i < Used_length; i++)
        {
            cin >> *(ptr + i);
        }
    }
}
void MyArray::Print_Array( int tSize, int uSize)
{
    
    cout<<"\nYour list is "<<endl;
    for (int i = 0; i < uSize; i++)
    {
        cout << *(ptr + i);
        cout<<"\t";
    }
}
void MyArray ::Insertion_Array( int tSize, int uSize)
{
    
    int index;
    int place;
    int element;
    cout << "\nEnter the element which you want to insert\n"
         << endl;
    cin >> element;
    cout << "Enter the place where you want to insert\n"
         << endl;
    cin >> place;
    index = place - 1;
    for (int j = Used_length - 1; j >= index; j--)
    {
        *(ptr + j + 1) = *(ptr + j);
    }
    *(ptr + index) = element;
}
void MyArray:: BinarySearch(int tSize, int uSize)
{
    int element;
    int low=0,mid,high = uSize-1;
    cout<<"Enter the element which you want to search : "<<endl;
    cin>>element;

    while(low<=high)
    {
        mid = (high+low)/2;
        if(*(ptr+mid)==element)
        {
            cout<<"The element "<<element<<" is present at "<<mid+1<<endl;
            break;
        }

        else{
            if(mid<element)
            {
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
}
void MyArray :: Deletion(int tSize, int uSize)
{
    int j;
    printf("Enter the place from wherer you want to delete element:\n");
    cin>>j;

    for(int i = j-1; i < uSize-1; i++)
    {
        *(ptr+i) = *(ptr+i+1);
    }
   
}

int main()
{
    MyArray ab;
    int number_list;
    int Slist;
    int Ulist;
    cout << "Enter the total Size of list " << endl;
    cin >> Slist;
    cout << "Enter the used size of the list " << endl;
    cin >> Ulist;
    ab.Create_Array(&ab, Slist, Ulist);
    ab.Print_Array(Slist, Ulist);
    // ab.Insertion_Array(Slist, Ulist);
    // ab.Print_Array(Slist,Ulist+1);
    // ab.BinarySearch(Slist,Ulist);
    ab.Deletion(Slist,Ulist);
    ab.Print_Array(Slist,Ulist-1);
    return 0;
}