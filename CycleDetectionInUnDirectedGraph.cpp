#include <bits/stdc++.h>
using namespace std;


bool detectCycle(int src,vector<int>adj[],int vis[])
{
    vis[src]=1;

    queue<pair<int,int>>q;

    q.push({src,-1});
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();


        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push({it,node});
            }else if(parent!=it)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int N,vector<int>adj[])
{
    int vis[N]={0};
    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        {
            if(detectCycle(i,adj,vis))
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
        cout<<"Cycle is Present"<<endl;
    }else{
        cout<<"NO Cycle"<<endl;
    }
    return 0;
}