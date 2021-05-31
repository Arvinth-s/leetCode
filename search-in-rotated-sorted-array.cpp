//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

/*

#binary search implementation #100q #medium
faster than 13%

*/



class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int idx, l = 0, r = n - 1;
        while (r - l >= 1)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[0])
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        if (nums[r] > nums[0])
        {
            idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            if (idx < n && nums[idx] == target)
                return idx;
            return -1;
        }

        idx = lower_bound(nums.begin(), nums.begin() + r, target) - nums.begin();
        if (nums[idx] == target)
            return idx;

        idx = lower_bound(nums.begin() + r, nums.end(), target) - nums.begin();
        if (idx < n && nums[idx] == target)
            return idx;

        return -1;
    }
};