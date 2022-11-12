#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
    if(s.length() == 1)
        return false;
    
    stack<int> tmp;

    for(auto c : s)
    {
        if(c == '(' or c == '[' or c == '{')
            tmp.push(c);
        else if(tmp.empty())
            return false;
        else if(c == ')')
        {
            if(tmp.top() == '(')
                tmp.pop();
            else
                return false;
        }
        else if(c == ']')
        {
            if(tmp.top() == '[')
                tmp.pop();
            else
                return false;
        }
        else if(c == '}')
        {
            if(tmp.top() == '{')
                tmp.pop();
            else
                return false;
        }
    }

    return tmp.empty();
}

int main()
{
    string s = "()[]{}";
    bool ans = isValid(s);

    cout << ans << endl;

    return 0;
}