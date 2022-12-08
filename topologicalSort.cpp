#include <bits/stdc++.h>
using namespace std;


//TC-> O(N+E)
//SC-> O(N)+O(N)
void dfs(int node, stack<int> &st, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, st, adj, vis);
        }
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    stack<int> st;
    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, st, adj, vis);
        }
    }
    vector<int> topo;
    while (!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
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
    vector<int>ans = topoSort(n,adj);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}