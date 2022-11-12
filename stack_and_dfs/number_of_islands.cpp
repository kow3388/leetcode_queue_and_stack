#include <bits/stdc++.h>

using namespace std;

//using recursive dfs
void dfs(vector<vector<char>> &grid, int r, int c, const int row, const int col)
{
    if(r < 0 or r >= row or c < 0 or c >= col or grid[r][c] == '0')
        return;

    grid[r][c] = '0';
    dfs(grid, r-1, c, row, col);
    dfs(grid, r+1, c, row, col);
    dfs(grid, r, c-1, row, col);
    dfs(grid, r, c+1, row, col);
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
                cnt++;
                dfs(grid, i , j, row, col);
            }

    return cnt;
}

//using stack dfs
void dfs1(vector<vector<char>> &grid, stack<pair<int, int>> &s, const int row, const int col)
{
    while(!s.empty())
    {
        int r = s.top().first;
        int c = s.top().second;
        grid[r][c] = '0';

        if((r - 1) >= 0 and grid[r-1][c] == '1')
            s.push({r-1, c});
        else if((r + 1) < row and grid[r+1][c] == '1')
            s.push({r+1, c});
        else if((c - 1) >= 0 and grid[r][c-1] == '1')
            s.push({r, c-1});
        else if((c + 1) < col and grid[r][c+1] == '1')
            s.push({r, c+1});
        else
            s.pop();
    }
}

int numIslands1(vector<vector<char>> &grid)
{
    const int row = grid.size();
    const int col = grid[0].size();

    int cnt = 0;
    stack<pair<int, int>> s;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
            if(grid[i][j] == '1')
            {
                cnt++;
                s.push({i, j});
                dfs1(grid, s, row, col);
            }
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