#include <bits/stdc++.h>
using namespace std;



bool isDetect(int node, int parent,int vis[],vector<int>adj[])
{
    vis[node]=1;
    for(auto it:adj[node])
    {
        if(!vis[it])
        {
            if(isDetect(it,node,vis,adj))
            {
                return true;
            }
        }else if(it!=parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int N,vector<int>adj[])
{
    int vis[N] = {0};
    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        {
            if(isDetect(i,-1,vis,adj)==true)
            {
                return true;
            }
        }
    }
    return false;
    
}

int main()
{
    int N,E;
    cin>>N>>E;
    vector<int>adj[N];
    for(int i=0;i<N;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = isCycle(N,adj);
    if(ans==true)
    {
        cout<<"Contains Cycle"<<endl;
    }else{
        cout<<"No Cycle present"<<endl;
    }
    return 0;
}
// Complexity Analysis
// Space Complexity -> O(N+2E)
// Time Complexity -> O(N)+O(N)