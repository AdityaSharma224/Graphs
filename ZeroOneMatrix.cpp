#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>ZeroOneMatrix(vector<vector<int>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>dist(n,vector<int>(m,0));

    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)
            {
                q.push({{i,j},0});
                vis[i][j]=1;
            }else{
                vis[i][j]=0;
            }
        }
    }

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,+1,0,-1};

    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;

        int steps = q.front().second;

        q.pop();

        dist[x][y] = steps;

        for(int i=0;i<4;i++)
        {
            int nrow = x+dx[i];
            int ncol = y+dy[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol])
            {
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},steps+1});
            }
        }
    }
    return dist;
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }

    vector<vector<int>>ans = ZeroOneMatrix(arr);
    for(auto it:ans)
    {
        for(auto  j:it)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
//Time Complexity: O(NxM + NxMx4) ~ O(N x M)
//Space Complexity: O(N x M) + O(N x M) + O(N x M)