//OM NAMO NARAYANA
//https://leetcode.com/problems/permutation-in-string/submissions/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26], count2[26], i=0, j=0, n=s1.size();
        memset(count1, 0, sizeof(count1)); memset(count2, 0, sizeof(count2));
        for(char s:s1)count1[s-'a']++;
        for(; j < s2.size(); j++){
            int idx = s2[j]-'a';
            ++count2[idx];
            while(count2[idx] > count1[idx] && i <= j)count2[int(s2[i++]-'a')]--;
            if(j-i+1 == n)return true;
        }
        return false;
    }
};