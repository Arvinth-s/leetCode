//OM NAMO NARAYANA
//https://leetcode.com/problems/longest-turbulent-subarray/submissions/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int res = 1, i = 0, j = -1, n = arr.size();        
        while(i < n-1 && arr[++i] == arr[++j]);
        if(n==1 || i==n)return 1;
        bool increase = (arr[i] > arr[j]);
        for(;i<n; i++){
            if(arr[i]==arr[i-1])j=i;
            else if(increase ^ (arr[i] > arr[i-1]))j = i-1;
            else {   
                if(i - j + 1 > res)res = i - j + 1;
                increase = !increase;
            }
        }
        return res;
    }
};