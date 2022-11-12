#include <bits/stdc++.h>

using namespace std;

//想不到
string decodeString(string s, int &i)
{
    string ans;

    while(i < s.length() and s[i] != ']')
    {
        //因為數字一定會出現在'['前面
        //所以判斷數字即可同時判斷[
        //因此此if是直接把文字append上去
        if(!isdigit(s[i]))
            ans += s[i++];
        else
        {
            //計算有幾個重複
            int n = 0;
            while(i < s.length() and isdigit(s[i]))
                n = 10*n + s[i++] - '0';
            
            i++; //'['
            string t = decodeString(s, i);
            i++; //']'

            while(n-- > 0)
                ans += t;
        }
    }

    return ans;
}

string decodeString(string s)
{
    int i = 0;
    return decodeString(s, i);
}

int main()
{
    string s = "3[a2[c]]ef";
    string ans = decodeString(s);

    cout << ans << endl;

    return 0;
}