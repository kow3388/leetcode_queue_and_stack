#include <bits/stdc++.h>

using namespace std;

class MinStack
{
    public:
        MinStack()
        {
        }
        
        void push(int val)
        {
            s.push_back(val);
            if(min_v.empty() or val <= min_v.back())
                min_v.push_back(val);
        }
        
        void pop()
        {
            int tmp = s.back();
            s.pop_back();

            if(tmp == min_v.back())
                min_v.pop_back();
        }
        
        int top()
        {
            return s.back();
        }
        
        int getMin()
        {
            return min_v.back();
        }
    private:
        vector<int> s;
        vector<int> min_v;
};