#include<bits/stdc++.h>
using namespace std;




void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid)
{
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});

    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        for(int delRow = -1; delRow<=1; delRow++)
        {
            for(int delCol=-1; delCol<=1;delCol++)
            {
                int nrow = row+delRow;
                int ncol = col+delCol;

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
}

int NumOfIsland(vector<vector<char>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int count = 0;
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<m;col++)
        {
            if(!vis[row][col] && grid[row][col]=='1')
            {
                count++;
                bfs(row,col,vis,grid);
            }
        }
    }
    return count;
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<char>>grid(n,vector<char>(m,'#'));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }
    int ans = NumOfIsland(grid);
    cout<<ans;
}