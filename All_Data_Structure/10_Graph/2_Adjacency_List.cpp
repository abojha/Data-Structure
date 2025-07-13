#include<iostream>
using namespace std;

struct ListNode
{
    int vertexNumber;
    struct ListNode *next;
};
struct Graph
{
    int V;
    int E;
    struct ListNode **Adj;
};



struct Graph *Adjacency_List()
{
    int x, y;
    struct ListNode *temp;
    struct Graph *G = new struct Graph();
    if(!G)
    {
        cout<<"Memory Error\n";
        return NULL;
    }
    cout<<"Enter the number of vertices\n";
    cin>>G->V;
    cout<<"Enter the number of Edges\n";
    cin>>G->E;

    G->Adj = new struct ListNode*[G->V];

    for(int i = 0; i < G->V; i++)
    {
        G->Adj[i] = new struct ListNode[sizeof(struct ListNode)];
        G->Adj[i]->vertexNumber = i;
        G->Adj[i]->next = G->Adj[i];
    }
    for(int i = 0; i < G->E; i++)
    {
        cout<<"Reading Edge\n";
        cin>>x>>y;

        temp = new struct ListNode();
        temp->vertexNumber = y;
        temp->next = G->Adj[x];
        G->Adj[x]->next = temp;

        temp = new struct ListNode();
        temp->vertexNumber = y;
        temp->next = G->Adj[y];
        G->Adj[y]->next = temp;

    }
    return G;
}
int main()
{
    struct Graph *g;
    g = Adjacency_List();
    return 0;
}