//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int dp[amount + 1];
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++)
        {
            for (int coin : coins)
            {
                if (coin <= i)
                {
                    if (dp[i - coin] == -1)
                        continue;
                    if (dp[i] == -1 || dp[i] > dp[i - coin] + 1)
                        dp[i] = dp[i - coin] + 1;
                }
            }
        }

        return dp[amount];
    }
};