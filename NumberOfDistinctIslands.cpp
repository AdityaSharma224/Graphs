#include<bits/stdc++.h>
using namespace std;

void dfs(int row,int col,vector<vector<int>>&grid,vector<pair<int,int>>&vec,vector<vector<int>>&vis,int row0,int col0)
{
    int n = grid.size();
    int m = grid[0].size();

    vis[row][col]=1;
    vec.push_back({row-row0,col-col0});
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    for(int i=0;i<4;i++)
    {
        int nrow = dx[i]+row;
        int ncol = dy[i]+col;

           if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,grid,vec,vis,row0,col0);
            }
    }
}

int CountIslands(vector<vector<int>>&grid)
{
    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int,int>>>st;
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]==1)
            {
                vector<pair<int,int>>vec;
                dfs(i,j,grid,vec,vis,i,j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}

int main()
{
    int n,m;
    cin>>n>>m;

    vector<vector<int>>arr(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<CountIslands(arr);

}
// time complexity: n x m x log(n x m) + (n x m x 4)