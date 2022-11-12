#include <bits/stdc++.h>

using namespace std;

//bfs
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    const int row = image.size();
    const int col = image[0].size();
    const int old_color = image[sr][sc];

    if(old_color == color)
        return image;

    queue<pair<int, int>> bfs;
    vector<pair<int, int>> dir = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    bfs.push({sr, sc});

    while(!bfs.empty())
    {
        int n = bfs.size();
        for(int i = 0; i < n; i++)
        {
            auto curr = bfs.front();
            bfs.pop();
            for(auto d : dir)
            {
                int r = curr.first + d.first;
                int c = curr.second + d.second;

                if(r >= 0 and r < row and c >= 0 and c < col and
                   image[r][c] == old_color)
                    bfs.push({r, c});
            }
            image[curr.first][curr.second] = color;
        }
    }

    return image;
}

//dfs
void dfs(vector<vector<int>> &img, int r, int c, int color, int old_color)
{
    if(r < 0 or r >= img.size() or c < 0 and c >= img[0].size() or
       img[r][c] != old_color)
        return;
    
    img[r][c] = color;

    dfs(img, r+1, c, color, old_color);
    dfs(img, r-1, c, color, old_color);
    dfs(img, r, c+1, color, old_color);
    dfs(img, r, c-1, color, old_color);
}

vector<vector<int>> floodFill1(vector<vector<int>> &image, int sr, int sc, int color)
{
    const int old_color = image[sr][sc];
    
    if(old_color == color)
        return image;
    
    dfs(image, sr, sc, color, old_color);

    return image;
}

int main()
{
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc =1;
    int color = 2;

    vector<vector<int>> ans = floodFill1(image, sr, sc, color);
    for(auto a : ans)
    {
        for(auto c : a)
            cout << c << " ";
        cout << endl;
    }

    return 0;
}