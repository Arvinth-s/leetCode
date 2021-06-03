//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //first:maximum profit with including this
    //second:maximum profit without including this
    pair<int, int> recur(vector<int> &nums, int i)
    {
        if (i == nums.size())
            return pair<int, int>(0, 0);
        pair<int, int> r = recur(nums, i + 1);
        pair<int, int> res;
        res.first = r.second + nums[i];
        res.second = max(r.second, r.first);
        return res;
    }

    int rob(vector<int> &nums)
    {
        pair<int, int> res = recur(nums, 0);
        return max(res.first, res.second);
    }
};