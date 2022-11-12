#include <bits/stdc++.h>

using namespace std;

int evalRPN(vector<string> &tokens)
{
    if(tokens.size() == 1)
        return stoi(tokens[0]);
    else
    {
        int n = tokens.size();
        stack<string> tmp;
        for(int i = 0; i < n; i++)
        {
            if(tokens[i] == "+" or tokens[i] == "-" or
                tokens[i] == "*" or tokens[i] == "/")
            {
                long long num2 = stoll(tmp.top());
                tmp.pop();
                long long num1 = stoll(tmp.top());
                tmp.pop();

                if(tokens[i] == "+")
                    tmp.push(to_string(num1 + num2));
                else if(tokens[i] == "-")
                    tmp.push(to_string(num1 - num2));
                else if(tokens[i] == "*")
                    tmp.push(to_string(num1 * num2));
                else
                    tmp.push(to_string(num1 / num2));
            }
            else
                tmp.push(tokens[i]);
        }

        return stoi(tmp.top());
    }
}

int main()
{
    vector<string> tokens = {
        "4","13","5","/","+"
    };
    int ans = evalRPN(tokens);

    cout << ans << endl;

    return 0;
}