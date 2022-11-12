#include <bits/stdc++.h>

using namespace std;

//我的寫法
class MyQueue1
{
    public:
        MyQueue1()
        {}
        
        void push(int x)
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }

            s2.push(x);

            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        
        int pop()
        {
            int v = s1.top();
            s1.pop();

            return v;
        }
        
        int peek()
        {
            return s1.top();
        }
        
        bool empty()
        {
            return s1.empty();
        }
    private:
        stack<int> s1;
        stack<int> s2;
};

//網路上的寫法
//不用只有在需要front的時候才會去處理stack
class MyQueue
{
    public:
        MyQueue()
        {}
        
        void push(int x)
        {
            s1.push(x);
        }
        
        int pop()
        {
            int v = peek();
            s2.pop();

            return v;
        }
        
        int peek()
        {
            if(s2.empty())
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            
            return s2.top();
        }
        
        bool empty()
        {
            return s1.empty() and s2.empty();
        }
    private:
        stack<int> s1;  //input
        stack<int> s2;  //output
};