#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &rooms, vector<bool> &key, int r)
{
    if(key[r])
        return;
    
    key[r] = true;
    for(auto room : rooms[r])
        dfs(rooms, key, room);
}

bool canVisitAllRooms(vector<vector<int>> &rooms)
{
    vector<bool> key(rooms.size(), false);
    
    dfs(rooms, key, 0);
    for(bool k : key)
        if(!k)
            return false;

    return true;
}

int main()
{
    vector<vector<int>> rooms = {
        {1}, {2}, {3}, {0}
    };
    bool ans = canVisitAllRooms(rooms);

    cout << ans << endl;

    return 0;
}