//OM NAMO NARAYABA
#include<bits/stdc++.h>
using namespace std;

/*

New approach (referred from gfg)

*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0, val = nums[0];
        for (int num : nums)
        {
            if (num == val)
                ++count;
            else
            {
                --count;
                if (!count)
                {
                    count = 1;
                    val = num;
                }
            }
        }

        return val;
    }
};