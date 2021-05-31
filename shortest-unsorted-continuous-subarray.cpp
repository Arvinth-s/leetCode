//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

// //O(NlogN) solution
// class Solution
// {
// public:
//     int findUnsortedSubarray(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> nums2(nums);
//         sort(nums2.begin(), nums2.end());
//         int l = n, r = -1;
//         for (int i = 0; i < n; i++)
//         {
//             if (nums[i] != nums2[i])
//             {
//                 l = min(l, i);
//                 r = max(r, i);
//             }
//         }
//         if (l == n)
//             return 0;
//         return r - l + 1;
//     }
// };

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        int l = n, r = -1;

        st.push(0);

        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && nums[i] < nums[st.top()])
            {
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }

        if (l == n)
            return 0;

        stack<int> st2;
        st2.push(n - 1);

        for (int i = n - 2; i >= 0; i--)
        {
            while (!st2.empty() && nums[i] > nums[st2.top()])
            {
                r = max(r, st2.top());
                st2.pop();
            }
            st2.push(i);
        }

        return r - l + 1;
    }
};