//OM NAMO NARAYANA

//dp soltion
class Solution {
public:
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
       unordered_map<string, bool> wordMap;
        for(string word:wordDict){
            wordMap[word] = true;
        }
        int n = s.size();
        
        //dp[i] stores whether s[0, i] can be broken
        bool dp[n];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++){
            
            //if the entire word matches
            if(wordMap[s.substr(0, i+1)])
            {
                dp[i] = true; 
                continue;
            }
            for(int j = 0; j < i; j++){
                //till j is satisfied and s[j+1, i] exists
                if(dp[j] && wordMap[s.substr(j+1, i-j)]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n-1];
    }
};