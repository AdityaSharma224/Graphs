#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, int newColor, int inColor, int delRow[], int delCol[])
{
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == inColor && ans[nrow][ncol] != newColor)
        {
            dfs(nrow, ncol, image, ans, newColor, inColor, delRow, delCol);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int inColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1};
    dfs(sr, sc, image, ans, newColor, inColor, delRow, delCol);
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>image(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>image[i][j];
        }
    }

    int sr,sc,newColor;
    cin>>sr>>sc>>newColor;

    vector<vector<int>>ans = floodFill(image,sr,sc,newColor);
    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

// Complexity Analysis
// Space Complexity -> O(N*M) + O(N*M)
// Time Complexity -> O(N*M + N*M*4)
