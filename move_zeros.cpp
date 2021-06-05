//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int zeros = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!nums[i])
                ++zeros;
            else
                nums[i - zeros] = nums[i];
        }
        for (int i = n - 1; i > n - zeros - 1; --i)
            nums[i] = 0;
        return;
    }
};