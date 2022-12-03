#include<bits/stdc++.h>
using namespace std;


  void dfs(vector<vector<int>> adj,int v,vector<bool> &visited)
   {
       visited[v] = 1;
       for(int i=0;i<adj[v].size();i++)
       {
           if(adj[v][i]==1&&!visited[i])
               dfs(adj,i,visited);
       }
   }
 
 
   int CountComponents(vector<vector<int>> adj, int V) {
       
       int count = 0;
       vector<bool> visited(V,0);
       for(int i=0;i<V;i++)
       {
           if(!visited[i])
           {
               count++;
               dfs(adj,i,visited);
           }
       }
       return count;
   }

int main()
{
    int n,m;
    cin>>n;

    vector<vector<int>>adj;
    for(int i=0;i<n;i++)
    {
        vector<int>temp;
        for(int j=0;j<n;j++)
        {
            cin>>m;
            temp.push_back(m);
        }
        adj.push_back(temp);
    }
    cout<<CountComponents(adj,n);

}