#include<iostream>
using namespace std;

class Fighting_num
{
    int n1,n2,n3;
    public:
        void get_data()
        {
            cout<<"Enter the three numbers\n";
            cin>>n1>>n2>>n3;
        }
        void compare()
        {
            if(n1>n2 && n1>n3)
            {
                cout<<"Greates number is "<<n1<<endl;
            }
            if(n2>n1 && n2>n3)
            {
                cout<<"Greates number is "<<n2<<endl;
            }
            if(n3>n2 && n3>n1)
            {
                cout<<"Greates number is "<<n3<<endl;
            }
        }
};
int main()
{
    Fighting_num a;
    a.get_data();
    a.compare();
    return 0;
}