//OM NAMO NARAYANA
//https://leetcode.com/problems/longest-repeating-character-replacement/submissions/
class Solution {
public:
    int characterReplacement(string s, int k) {
        //(q.front, i) contains the required length
        //q has size k+1
        int res = 0, n = s.size();
        if(n==0)return 0;
        for(int i = 0; i < 26; i++){
            queue<int> q;
            q.push(-1);
            for(int j = 0; j < n-1; j++){
                if(int(s[j]-'A')-i != 0){
                    if(q.size()==k+1){
                        res = max(res, j - q.front()-1);
                        q.pop();
                    }
                    q.push(j);
                }
            }
            if(q.size() < k+1){return n;}
            res =  (int(s[n-1]-'A')-i==0) ? max(res, n- 1 - q.front()):max(res, n-2-q.front());
        }
        return res;
    }
};