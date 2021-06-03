//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size(), sum = 0;

        for (int i : nums)
            sum += i;

        if (sum % 2)
            return false;

        bool dp[n + 1][sum / 2 + 1];
        memset(dp, false, sizeof(dp));
        for (int i = 0; i < n + 1; i++)
            dp[i][0] = true;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j <= sum / 2; j++)
            {
                dp[i][j] = dp[i - 1][j] || (j - nums[i - 1] >= 0 && dp[i - 1][j - nums[i - 1]]);
            }
        }
        return dp[n][sum / 2];
    }
};