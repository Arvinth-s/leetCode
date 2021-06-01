//OM NAMO NARAYANA

/*
Q) Given an integer n, return the least number of perfect square numbers that sum to n
A) Coin Change problem

faster than 71%

*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        int dp[n + 1];
        dp[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + 1;
            for (int j = 2; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};