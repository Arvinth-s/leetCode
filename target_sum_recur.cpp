//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

/*
faster than 5.12%
*/

class Solution
{
public:
    int recur(vector<int> &nums, int i, int sum, int target)
    {
        if (i == nums.size())
        {
            return target == sum;
        }

        return recur(nums, i + 1, sum, target) + recur(nums, i + 1, sum - 2 * nums[i], target);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int i : nums)
            sum += i;
        return recur(nums, 0, sum, target);
    }
};