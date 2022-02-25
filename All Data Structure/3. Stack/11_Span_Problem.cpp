#include<iostream>
#include<stack>
using namespace std;

int stock_span(int price[],int size, int s[] )
{
    stack<int> st;
    st.push(0);
    for(int i = 0; i < size; i++)
    {
        while(!st.empty() && price[st.top()]<=price[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            s[i] = i+1;
        }
        else
        {
            s[i] = i-st.top();
        }
        st.push(i);
    }
    
}
int main()
{
    int price[] = {100,80,60,70,60,75,85};
    int s[7];
    int size = 7;

    stock_span(price,size,s);
    for(int i = 0; i < size; i++)
    {
        cout<<s[i]<<" ";
    }

    
    return 0;
}