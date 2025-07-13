#include<iostream>
#include<queue>
using namespace std;


int main()
{
    
    int i;
    int node;
    int visited[4] = {0,0,0,0};
    int a[4][4] = 
    {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };
    queue<int> explore_q;
    i = 3;
    visited[i] = 1;
    cout<<i<<" ";
    explore_q.push(i);

    while(!explore_q.empty())
    {
        node = explore_q.front();
        explore_q.pop();
        for(int i = 0; i < 4; i++)
        {
            if(a[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                cout<<i<<" ";
                explore_q.push(i);
                
            }
           
        }   
    }
    
    return 0;
}