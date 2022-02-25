#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void replace(vector<int> b)
{
    int n = b.size();
    stack<int> s;
    s.push(b[0]);
    for(int i = 1; i < n; i++)
    {
        if(!s.empty() && s.top()>b[i])
        {

            s.push(b[i]);
        }
        while(s.top()<b[i])
        {
            cout<<"The next nearest element for "<<s.top()<<" is "<<b[i]<<endl;
            s.pop();
            if(s.empty())
            {
                break;
            }
            s.pop();
        }
        s.push(b[i]);
        
    }
}
int main()
{
    vector<int> b = {1,5,7,2,12};
    replace(b);
    
    return 0;
}