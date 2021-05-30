//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3]={0, 0, 0};
        for(int i:nums)count[i]++;
        count[1]+=count[0];
        count[2]+=count[1];
        int idx=0;
        for(int i=0; i<3;i++)
            for(; idx<count[i]; idx++)
                nums[idx]=i;

    }
};