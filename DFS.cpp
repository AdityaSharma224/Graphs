#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>adj[],int vis[],vector<int>&list)
{
    vis[node]=1;
    list.push_back(node);

    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,list);
        }
    }
}

vector<int>dfsCall(int v,vector<int>adj[])
{
    int vis[v] = {0};
    int src = 0;
    vector<int>list;
    dfs(src,adj,vis,list);
    return list;
}

void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<int>adj[5];
    addEdge(adj,0,1);
    addEdge(adj,0,4);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    vector<int>ans=dfsCall(5,adj);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}

// Complexity Analysis
// Time Complexity -> O(N)+O(2E);
// Space Complexity -> O(3N) ~O(N)
