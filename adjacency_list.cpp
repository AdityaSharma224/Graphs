#include<bits/stdc++.h>
using namespace std;


// Undirected graph
// Space Complexity -> o(2xE) 2_Edges
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u,v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    return 0;
}

// Directed Graph
// Space Complexity -> O(E) single edge
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u,v;
        adj[u].push_back(v);

    }
    return 0;
}