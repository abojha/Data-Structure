#include<iostream>
#include<limits.h>
#include<vector>
#define V 6
using namespace std;

int selectMinVertex(vector<int>& value, vector<bool>& processed)
{
    int minimum = INT_MAX;
    int vertex;
     for(int i = 0; i < V; i++)
     {
         if(processed[i] == false && value[i] < minimum)
         {
             vertex = i;
             minimum = value[i];
         }
     }
     return vertex;
}
void dijikstra_algo(int graph[V][V])
{
    int parent[V];
    vector<int> value(V, INT_MAX);
    vector<bool> processed(V, false);

    parent[0] = -1;
    value[0] = 0;
    for(int i = 0; i < V; i++)
    {
        int U = selectMinVertex(value, processed);
        processed[U] = true;
                                                                                                                                                                                 
        for(int j = 0; j < V; j++)
        {
            if(graph[U][j]!= 0 && processed[j] == false && value[U] != INT_MAX
                && (value[U] + graph[U][j] < value[j]))
                {
                    value[j] = value[U] + graph[U][j];
                    parent[j] = U;
                }
        }
    }

    for(int i = 0; i < V; i++)
    {
        cout<<"u->V: "<< parent[i] << " -> "<<i<<"  wt  = "<<graph[parent[i]][i]<<endl;
    }                                                            
}

int main()
{
    
    int graph[V][V] = {

        {0,1,4,0,0,0},
        {1,0,2,7,5,0},
        {4,2,0,0,1,0},
        {0,7,0,0,3,3},
        {0,5,1,3,0,6},
        {0,0,0,3,6,0},
    };
    dijikstra_algo(graph);
    return 0;
}