#include <bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    const int d = temperatures.size();
    vector<int> ans(d);
    stack<int> s;

    for(int i = d-1; i >= 0; i--)
    {
        while(!s.empty() and temperatures[s.top()] <= temperatures[i])
            s.pop();
        
        ans[i] = s.empty()? 0 : s.top() - i;
        s.push(i);
    }

    return ans;
}

int main()
{
    vector<int> t = {73,74,75,71,69,72,76,73};
    vector<int> ans = dailyTemperatures(t);

    for(auto a : ans)
        cout << a << endl;

    return 0;
}