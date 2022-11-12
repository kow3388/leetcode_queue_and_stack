#include <bits/stdc++.h>

using namespace std;

//想不出來
//hard 不用太在意
vector<string> neighbors(const string &code)
{
    vector<string> result;
    for(int i = 0; i < 4; i++)
    {
        //對4個位置上下各滾一次
        for(int j = -1; j <= 1; j += 2)
        {
            string nei = code;
            //維持0 ~ 9
            nei[i] = (nei[i] - '0' + j + 10) % 10 + '0';
            cout << nei << endl;
            result.push_back(nei);
        }
    }

    return result;
}

int openLock(vector<string> &deadends, string target)
{
    unordered_set<string> deadset(deadends.begin(), deadends.end());
    if(deadset.count("0000"))
        return -1;
    
    queue<string> q;
    q.push("0000");

    for(int i = 0; !q.empty(); i++)
    {
        for(int j = q.size(); j > 0; j--)
        {
            auto curr = q.front();
            q.pop();
            if(curr == target)
                return i;
            
            for(auto nei : neighbors(curr))
            {
                if(deadset.count(nei))
                    continue;
                //把看過的塞進deadset表示檢查過
                deadset.insert(nei);
                //把新的數字塞進queue從新的數字在去轉
                q.push(nei);
            }
        }
    }

    return -1;
}

int main()
{
    vector<string> deadends = {
        "0201", "0101", "0102", "1212", "2002"
    };
    string target = "0202";
    int ans = openLock(deadends, target);

    cout << ans << endl;

    return 0;
}