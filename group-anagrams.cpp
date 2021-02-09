//OM NAMO NARAYANA
//https://leetcode.com/problems/group-anagrams/submissions/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strss) {
        vector<pair<string, int> > strs;
        for(int i = 0; i < strss.size(); i++){
            strs.push_back(pair<string, int>(strss[i], i));
        }
        for(int i = 0; i < strs.size(); i++)sort(strs[i].first.begin(), strs[i].first.end());
        sort(strs.begin(), strs.end());
        string ref = strs[0].first;
        vector<vector<string> > res;
        res.push_back(vector<string>{strss[strs[0].second]});
        for(int i =1; i < strs.size(); i++){
            if(strs[i].first==ref)res.back().push_back(strss[strs[i].second]);
            else{
                ref = strs[i].first;
                res.push_back(vector<string>{strss[strs[i].second]});
            }
        }
        return res;
    }
};