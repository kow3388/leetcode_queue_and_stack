#include <bits/stdc++.h>

using namespace std;

//dfs的做法
void dfs(vector<int> &nums, int target, int sum, int idx, int &cnt)
{
    if(idx == nums.size() and sum == target)
    {
        cnt++;
        return;
    }
    else if(idx == nums.size() and sum != target)
        return;
    else
    {
        dfs(nums, target, sum+nums[idx], idx+1, cnt);
        dfs(nums, target, sum-nums[idx], idx+1, cnt);
    }
}

int findTargetSumWays(vector<int> &nums, int target)
{
    int cnt = 0;
    dfs(nums, target, 0, 0, cnt);

    return cnt;
}

/*網路上其他的做法，用dp
此問題可以通過轉換變成partial equal subset sum
https://leetcode.com/explore/learn/card/queue-stack/232/practical-application-stack/1389/discuss/97334/Java-(15-ms)-C++-(3-ms)-O(ns)-iterative-DP-solution-using-subset-sum-with-explanation
我們要找subset裡面是positive (P)，剩餘的是negative (N)，使得sum(P) - sum(N) = target
透過以下數學的轉換
sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
2*sum(P) = target + sum(nums)
sum(P) = (target + sum(nums))/2*/

//subsetSum => 找P的subarray數
int subsetSum(vector<int> &nums, int target)
{
    if(target < 0)
        return 0;
    
    vector<int> dp(target+1);
    dp[0] = 1;

    for(int n : nums)
        for(int i = target; i >= n; i--)
            dp[i] += dp[i-n];
    
    return dp[target];
}

int findTargetSumWays1(vector<int> &nums, int target)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);

    //如果全部總合比target小或(target+sum)為奇數，則不可能有解
    return (sum < target or (target + sum)%2)? 0 : subsetSum(nums, (target+sum)/2);
}

int main()
{
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    
    int ans = findTargetSumWays1(nums, target);
    cout << ans << endl;

    return 0;
}