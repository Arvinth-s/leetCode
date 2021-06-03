//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

/*
faster than 14%
*/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (vector<int> interval : intervals)
        {
            if (res.back()[1] >= interval[0])
            {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
            else
            {
                res.push_back(interval);
            }
        }
        return res;
    }
};