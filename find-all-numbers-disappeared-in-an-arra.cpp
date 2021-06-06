//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res;
        bool visited[n];
        memset(visited, false, sizeof(visited));

        for (int num : nums)
            visited[num - 1] = true;

        for (int i = 0; i < n; i++)
            if (!visited[i])
                res.push_back(i + 1);

        return res;
    }
};