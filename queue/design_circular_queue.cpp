#include <bits/stdc++.h>

using namespace std;

class MyCircularQueue
{
    public:
        MyCircularQueue(int k)
        {
            q.resize(k);
            head = 0;
            count = 0;
        }
        
        bool enQueue(int value)
        {
            if(count == q.size())
                return false;
            
            int idx = (head + count) % q.size();
            q[idx] = value;
            count++;

            return true;
        }
        
        bool deQueue()
        {
            if(count == 0)
                return false;
            
            head = (head + 1) % q.size();
            count--;

            return true;
        }
        
        int Front()
        {
            return (count == 0)? -1 : q[head];
        }
        
        int Rear()
        {
            int idx = (head + count - 1) % q.size();
            return (count == 0)? -1 : q[idx];
        }
        
        bool isEmpty()
        {
            return (count == 0);
        }
        
        bool isFull()
        {
            return (count == q.size());
        }

    private:
        vector<int> q;
        int head;
        int count;
};