//OM NAMO NARAYANA

//https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/submissions/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //[i, j] is the required answer
        //[i, j] should contain n-1 or n
        int buf = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        if( (nums[n-1]>x && nums[0] > x) || buf < x){
            return -1;
        }
        //slide window from left to right
        int i = 0, j = n-1, res = INT_MAX/2;
        while(i <= j &&  j-i <= n-1 && j<=2*n-1){
            if(buf < x){
                if(j-i < n-1 && j<=2*n-1)buf += nums[(++j)%n];
                else break;
            }else if(buf > x){
                if(i <= n-1 && i < j)buf -= nums[(i++)%n];
                else break;
            }else{
                res = min(res, j-i+1);
                if(j<=2*n-1 && i <= n-1)buf += nums[(++j)%n] - nums[(i++)%n];
                else break;
            }
        }
        if(res == INT_MAX/2)return -1;
        return res;
    }
};