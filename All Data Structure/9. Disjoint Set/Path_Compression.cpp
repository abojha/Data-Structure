#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int parent;
    int rank;
};

vector<Node> dsuf;

int find(int v)
{
    if(dsuf[v].parent == -1)
    return v;
    return dsuf[v].parent = find(dsuf[v].parent); 
}

void Union(int fromP, int toP)
{
    if(dsuf[fromP].rank > dsuf[toP].rank)
        dsuf[toP].parent = fromP; 
    else if(dsuf[fromP].rank < dsuf[toP].rank)
        dsuf[fromP].parent = toP; 
    else{
        dsuf[fromP].parent = toP;
        dsuf[toP].rank += 1;
    }
}

bool isCyclic(vector<pair<int, int>> & edge_list)
{
    for(auto p : edge_list)
    {
        int fromP = find(p.first);
        int toP = find(p.second);

        if(fromP == toP)
        return true;

        Union(fromP, toP);
    }
    return false;
}

int main()
{
    int E;
    int V;
    cin>>E>>V;

    dsuf.resize(V);

    for(int i = 0; i < V; i++)
    {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }
    vector<pair<int,int>> edge_List;
    for(int i = 0; i < E; i++)
    {
        int from, to;
        cin>>from>>to;
        edge_List.push_back({from, to});
    }

    if(isCyclic(edge_List))
    {
        cout<<"True\n";
    }
    else{
        cout<<"False\n";
    }
    return 0;
}