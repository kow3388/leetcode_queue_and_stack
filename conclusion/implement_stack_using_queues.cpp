#include <bits/stdc++.h>

using namespace std;

//我自己的做法
class MyStack1
{
    public:
        void push(int x)
        {
            q1.push(x);
        }
        
        int pop()
        {
            while(q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }

            int v = q1.front();
            q1.pop();
            swap(q1, q2);

            return v;
        }
        
        int top()
        {
            return q1.back();
        }
        
        bool empty()
        {
            return q1.empty();
        }
    private:
        queue<int> q1;
        queue<int> q2;
};

//網路上其他的做法
//只需要一個queue
class MyStack
{
    public:
        void push(int x)
        {
            q.push(x);
            int i = q.size();
            while(i-- > 1)
            {
                q.push(q.front());
                q.pop();
            }
        }
        
        int pop()
        {
            int v = q.front();
            q.pop();

            return v;
        }
        
        int top()
        {
            return q.front();
        }
        
        bool empty()
        {
            return q.empty();
        }
    private:
        queue<int> q;
};