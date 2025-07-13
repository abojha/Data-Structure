#include<iostream>
#include<queue>
using namespace std;

struct Graph
{
    int V;
    int E;
    int **Adj;
};

struct Graph *Adjacency_Matrix()
{
    int i, u, v;
    struct Graph *G = new struct Graph();
    if(!G)
    {
        cout<<"Memory Error";
        return NULL;
    }
    cout<<"Enter Number of Vertices\n";
    cin>>G->V;
    cout<<"Enter the Number of Edges\n";
    cin>>G->E;

   G->Adj = new int*[G->V];
   for(int k = 0; k < G->V; k++)
   {
       G->Adj[k] = new int[G->V];
   }

    for(u = 0; u < G->V; u++)
    {
        for(v = 0; v < G->V; v++)
        {
            G->Adj[u][v] = 0;
        }
    }
    for(i = 0; i < G->E; i++)
    {
        cout<<"Reading Edges\n";
        cin>>u>>v;
        G->Adj[u][v] = 1;
        G->Adj[v][u] = 1;
    }
    return G;
}
void print_graph(struct Graph *g)
{
    for(int i = 0; i < g->V; i++)
    {
        for(int j =  0; j < g->V; j++)
        {
            cout<<g->Adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Breadth_first_Search(struct Graph *G, int k)
{
    int node;
    queue<int> q;
    int visited[G->V];
    for(int i = 0; i < G->V; i++)
    {
        visited[i] = 0;
    }
     k = 0;
    q.push(k);
    cout<<k<<" "<<endl;
    visited[k] = 1;

    while(!q.empty())
    {
        node = q.front();
        q.pop();

        for(int j = 0; j < G->V; j++)
        {
            if(visited[j] == 0 && G->Adj[node][j] == 1)
            {
                visited[j] = 1;
                cout<<j<<" "<<endl;
                q.push(j);
            }
        }
    }


}
int main()
{
    Graph *G = new struct Graph();

    G = Adjacency_Matrix();
    print_graph(G);
    Breadth_first_Search(G,0);

    return 0;
}