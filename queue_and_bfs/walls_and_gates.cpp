#include <bits/stdc++.h>

using namespace std;

void wallsAndGates(vector<vector<int>> &rooms)
{
    const int row = rooms.size();
    const int col = rooms[0].size();
    queue<pair<int, int>> bfs;
    vector<pair<int, int>> dir = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    //initial where have the gate
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            if(rooms[i][j] == 0)
                bfs.push({i, j});
    
    int dis = 1;
    while(!bfs.empty())
    {
        int curr_size = bfs.size();
        for(int i = 0; i < curr_size; i++)
        {
            pair<int, int> gate = bfs.front();
            bfs.pop();
            for(int j = 0; j < 4; j++)
            {
                int r = gate.first + dir[j].first;
                int c = gate.second + dir[j].second;

                if(r >= 0 and r < row and c >= 0 and c < col and rooms[r][c] == INT_MAX)
                {
                    rooms[r][c] = dis;
                    bfs.push({r, c});
                }
            }
        }
        dis++;
    }
}

int main()
{
    vector<vector<int>> room = {
        {INT_MAX, -1, 0, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, -1},
        {INT_MAX, -1, INT_MAX, -1},
        {0, -1, INT_MAX, INT_MAX}
    };
    wallsAndGates(room);

    for(int i = 0; i < room.size(); i++)
    {
        for(auto r : room[i])
            cout << r << " ";
        cout << endl;
    }

    return 0;
}