#include <bits/stdc++.h>

using namespace std;

class MovingAverage
{
    public:
        MovingAverage(int size)
        {
            q.resize(size);
            head = 0;
            count = 0;
        }
        
        double next(int val)
        {
            int idx = (head + count) % q.size();
            q[idx] = val;

            if(count < q.size())
                count++;
            else
                head = (head + 1) % q.size();

            double sum = 0.0;
            for(int i = 0; i < count; i++)
            {
                idx = (head + i) % q.size();
                sum += q[idx];
            }

            return sum/count;
        }
    private:
        vector<int> q;
        int head;
        int count;
};