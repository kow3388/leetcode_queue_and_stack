#include <bits/stdc++.h>

using namespace std;

//因為是分類在queue裡面，所以這個我用bfs來解
//這個題目應該用dfs比較好
void bfs(vector<vector<char>> &grid, const int row, const int col, int r, int c)
{
    vector<pair<int, int>> dir = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    queue<pair<int, int>> q;
    q.push({r, c});

    grid[r][c] = '0';
    while(!q.empty())
    {
        int s = q.size();
        for(int i = 0; i < s; i++)
        {
            pair<int, int> land = q.front();
            q.pop();
            for(int j = 0; j < 4; j++)
            {
                int r = land.first + dir[j].first;
                int c = land.second + dir[j].second;

                if(r >= 0 and r < row and c >= 0 and c < col and grid[r][c] == '1')
                {
                    q.push({r, c});
                    grid[r][c] = '0';
                }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    const int row = grid.size();
    const int col = grid[0].size();
    int cnt = 0;

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            if(grid[i][j] == '1')
            {
                bfs(grid, row, col, i, j);
                cnt++;
            }
    
    return cnt;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    int ans = numIslands(grid);

    cout << ans << endl;

    return 0;
}