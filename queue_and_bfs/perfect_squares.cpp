#include <bits/stdc++.h>

using namespace std;

//dp 作法
int numSquares(int n)
{
    vector<int> cnt(n+1, INT_MAX);
    cnt[0] = 0;

    for(int i = 1; i < n+1; i++)
        for(int j = 1; j*j <= i; j++)
            cnt[i] = min(cnt[i], cnt[i-j*j] + 1);

    return cnt[n];
}

//網路上其他作法
//static dp
//把vector設成static，因此在程式結束前都會保留住
//所以會比較快
int numSquares1(int n)
{
    static vector<int> cnt({0});

    while(cnt.size() <= n)
    {
        int m = cnt.size();
        int cnt_squares = INT_MAX;
        for(int i = 1; i*i <= m; i++)
            cnt_squares = min(cnt_squares, cnt[m - i*i] + 1);
        
        cnt.push_back(cnt_squares);
    }

    return cnt[n];
}

//網路上其他作法
//bfs
int numSquares2(int n)
{
    vector<int> perfectsquare;
    vector<int> cnt(n);

    for(int i = 1; i*i <= n; i++)
    {
        perfectsquare.push_back(i*i);
        cnt[i*i - 1] = 1;
    }

    if(perfectsquare.back() == n)
        return 1;

    queue<int> q;
    for(auto i : perfectsquare)
        q.push(i);
    
    int curr_cnt = 1;
    while(!q.empty())
    {
        curr_cnt++;
        for(int i = q.size(); i > 0; i--)
        {
            int tmp = q.front();
            for(auto &j : perfectsquare)
            {
                if(tmp + j == n)
                    return curr_cnt;
                else if((tmp + j < n) and (cnt[tmp + j - 1] == 0))
                {
                    cnt[tmp + j - 1] = curr_cnt;
                    q.push(tmp + j);
                }
                else if(tmp + j > n)
                    break;
            }

            q.pop();
        }
    }

    return 0;
}

int main()
{
    int n = 13;
    int ans = numSquares(n);

    cout << ans << endl;

    return 0;
}