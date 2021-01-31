//OM NAMO NARAYANA
//https://leetcode.com/problems/can-convert-string-in-k-moves/submissions/

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.size()!=t.size())return false;
        int n = s.size(), arr[26];
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < n; i++){
            if(t[i]==s[i])continue;
            int temp = t[i] - s[i];
            if(temp < 0)temp += 26;
            if(26*(arr[temp]++) + temp > k)return false;
        }
        return true;
    }
};