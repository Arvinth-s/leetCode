//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min_val = INT_MAX, res = 0;
        for (int price : prices)
            if (price < min_val)
                min_val = price;
            else
                res = max(res, price - min_val);

        return res;
    }
};