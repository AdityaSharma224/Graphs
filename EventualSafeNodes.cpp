#include<bits/stdc++.h>
using namespace std;

bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[], int check[])
{
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfsCheck(it, adj, vis, pathVis, check) == true)
            {
                check[node] = 0;
                return true;
            }
        }
        else if (pathVis[it])
        {
            check[node] = 0;
            return true;
        }
    }
    check[node] = 1;
    pathVis[node] = 0;
    return false;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    // code here
    int vis[V] = {0};
    int pathVis[V] = {0};
    int check[V] = {0};

    vector<int> safe;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfsCheck(i, adj, vis, pathVis, check);
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (check[i] == 1)
        {
            safe.push_back(i);
        }
    }
    return safe;
}
int main()
{
    int n,m;
    cin>>n>>m;

    vector<int>adj[n];
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>ans = eventualSafeNodes(n,adj);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}