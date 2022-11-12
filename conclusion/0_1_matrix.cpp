#include <bits/stdc++.h>

using namespace std;

//我寫的bfs trash code會time out
//以下是網路上的寫法
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    vector<int> dir = {0, 1, 0, -1, 0};
    const int row = mat.size();
    const int col = mat[0].size();
    queue<pair<int, int>> bfs;

    //把不是0的全部變成-1
    //-1表示我們需要計算的，並且從0的所在地當起點
    for(int r = 0; r < row; r++)
        for(int c = 0; c < col; c++)
            if(mat[r][c] == 0)
                bfs.push({r, c});
            else
                mat[r][c] = -1;
    
    //用bfs來衡量距離
    while(!bfs.empty())
    {
        auto curr = bfs.front();
        bfs.pop();
        for(int i = 0; i < 4; i++)
        {
            int r = curr.first + dir[i];
            int c = curr.second + dir[i+1];

            //如果mat[r][c] != -1，表示要馬是起點，要碼我們更新過了
            if(r < 0 or r >= row or c < 0 or c >= col or mat[r][c] != -1)
                continue;
            
            //計算距離
            mat[r][c] = mat[curr.first][curr.second] + 1;
            bfs.push({r, c});
        }
    }

    return mat;
}

//網路上另一種解法，採用dp
vector<vector<int>> updateMatrix1(vector<vector<int>> &mat)
{
    const int row = mat.size();
    const int col = mat[0].size();
    //the distance of cell is up to (row + col)
    const int INF = row + col;

    //先從左上角開始
    //去看上面和左邊更新一次mat的值
    for(int r = 0; r < row; r++)
        for(int c = 0; c < col; c++)
        {
            if(mat[r][c] == 0)
                continue;
            int top = INF, left = INF;

            if(r-1 >= 0)
                top = mat[r-1][c];
            if(c-1 >= 0)
                left = mat[r][c-1];
            
            //新的mat值是上面或是左邊較小的值+1
            mat[r][c] = min(top, left) + 1;
        }
    
    //在從右下角開始
    //去看下面和右邊更新mat值
    for(int r = row-1; r >= 0; r--)
        for(int c = col-1; c >= 0; c--)
        {
            if(mat[r][c] == 0)
                continue;
            int bottom = INF, right = INF;

            if(r+1 < row)
                bottom = mat[r+1][c];
            if(c+1 < col)
                right = mat[r][c+1];
            
            //新的值是原本的值或是(下面or右邊較小的值 + 1)
            mat[r][c] = min(mat[r][c], min(bottom, right)+1);
        }

    return mat;
}

int main()
{
    vector<vector<int>> mat = {
        {0, 1, 0},
        {0, 1, 0},
        {1, 1, 1},
        {1, 1, 1},
        {0, 1, 0}
    };
    mat = updateMatrix(mat);

    for(auto r : mat)
    {
        for(auto c : r)
            cout << c << " ";
        cout << endl;
    }

    return 0;
}