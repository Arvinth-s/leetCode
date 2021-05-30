//OM NAMO NARAYANA

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        long long res = INT_MIN;
        vector<int> zeros{-1};
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                zeros.push_back(i);
            }
        }

        zeros.push_back(n);

        for (int i = 0; i < zeros.size() - 1; i++)
        {

            int l = zeros[i] + 1, r = zeros[i + 1] - 1;
            if (l > r)
                continue;
            if (l == r)
            {
                if (res < nums[l])
                    res = nums[l];
                continue;
            }

            long long pro = nums[l];
            for (int j = l + 1; j <= r; j++)
                pro *= nums[j];

            if (pro > 0)
            {
                res = max(res, pro);
                continue;
            }
            else
            {

                long long first_negative = nums[l];
                for (int j = l + 1; j <= r && first_negative > 0; j++)
                    first_negative *= nums[j];

                long long last_negative = nums[r];
                for (int j = r - 1; j >= l && last_negative > 0; j--)
                    last_negative *= nums[j];

                pro = max(pro / first_negative, pro / last_negative);
                res = max(res, pro);
            }
        }

        return (res > 0 || zeros.size() <= 2) ? res : 0;
    }
};