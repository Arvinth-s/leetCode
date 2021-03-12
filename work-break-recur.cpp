//OM NAMO NARAYANA

//passed 34/42 cases TLE
class Solution {
public:
    bool recur(string s, vector<string>& wordDict, int start, int end){
        // printf("start:%d end:%d\n", start, end);
        if(end < start)return true;
        //loops through the word dictionary
        for(int i = 0; i < wordDict.size(); i++){
            //checks whether the size matches
            if(end -start + 1 != wordDict[i].size())continue;
            //checks equality
            if(s.substr(start, end-start+1)==wordDict[i])return true;
            
        }
        //breaks into [start, i], [i+1, end]
        for(int i = start; i < end; i++){
            if(recur(s, wordDict, start, i) && recur(s, wordDict, i+1, end))return true;
        }
        //if none matches
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        return recur(s, wordDict, 0, s.size()-1);
    }
};