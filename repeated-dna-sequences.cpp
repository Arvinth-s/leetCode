//OM NAMO NARAYANA
//https://leetcode.com/problems/repeated-dna-sequences/submissions/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        if(s.size()<10)return vector<string>{};
        vector<string> res;
        string acc=s.substr(0, 10);
        mp[acc]=1;
        for(auto ch = s.begin()+10; ch != s.end(); ch++){
            acc.erase(0, 1);
            acc.push_back(*ch);
            if(mp.find(acc)==mp.end())mp[acc]=1;
            else if(mp[acc]==1){mp[acc]=2;res.push_back(acc);}
        }
        return res;
    }
};