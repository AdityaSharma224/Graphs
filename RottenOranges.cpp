#include <bits/stdc++.h>
using namespace std;

int rottenOranges(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int count = 0;
    int total = 0;
    int days = 0;

    queue<pair<int, int>> rotten;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0)
            {
                total++;
            }

            if (grid[i][j] == 2)
            {
                rotten.push({i, j});
            }
        }
    }

    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};

    while(!rotten.empty())
    {
        int k = rotten.size();
        count+=k;

        while(k--)
        {
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            for(int i=0;i<4;i++)
            {
                int nrow = x+dx[i];
                int ncol = y+dy[i];


                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1)
                {
                    grid[nrow][ncol]=2;
                    rotten.push({nrow,ncol});
                }
            }
        }
        if(!rotten.empty())
        {
            days++;
        }
    }
    if(total==count)
    {
        return days;
    }else{
        return -1;
    }

}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    int ans = rottenOranges(grid);
    cout << ans << endl;
}

// Complexity Analysis
// Space Complexity -> O(N*M) + O(N*M)
// Time Complexity -> O(N*M + N*M*4)