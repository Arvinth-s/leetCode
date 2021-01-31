//OM NAMO NARAYANA
//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/
class Solution {
public:
    int minAddToMakeValid(string S) {
        int n = S.size(), res = 0, buf = 0;
        for(char s:S){
            if(s=='('){
                if(buf>=0)buf++;
            }else{
                if(buf > 0)buf--;
                else{
                    res++;
                }
            }
        }
        res += buf;
        return res;
    }
};