//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;


/*
Interesting problem
Approach
end is a map which stores the other end of the current sequence
i.e, end[i]=j => that either [i, j] or [j, i] exists
it's always made sure that the end elements in the sequence always has the index of other end such that it maximizes the length of the sequence 



*/

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> end;
        int res = 0;

        for (int i : nums)
        {
            int r = i, l = i;

            if (end.find(i) != end.end())
                continue;
            end[i] = i;

            if (end.find(i + 1) != end.end())
            {
                if (end[i + 1] <= i)
                    continue;
                r = end[i + 1];
            }

            if (end.find(i - 1) != end.end())
            {
                if (end[i - 1] >= i)
                    continue;
                l = end[i - 1];
            }

            (end.find(l) != end.end()) ? end[l] = max(end[l], r) : r;
            (end.find(r) != end.end()) ? end[r] = min(end[r], l) : l;
            int length = max(end[l] - l, r - end[r]) + 1;

            res = max(res, length);
        }

        return res;
    }
};