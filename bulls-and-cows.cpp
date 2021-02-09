//OM NAMO NARAYANA
//https://leetcode.com/problems/bulls-and-cows/submissions/

class Solution {
public:
    string getHint(string secret, string guess) {
        assert(secret.size()==guess.size());
        int n = secret.size(), demand[26], excess[26], bulls=0, cows=0;
        memset(demand, 0, sizeof(demand));        
        memset(excess, 0, sizeof(excess));
        for(int i =0; i < n; i++){
            if(secret[i]==guess[i])bulls++;
            else{
                if(demand[guess[i]-'0'] > 0)cows++, demand[guess[i]-'0']--;
                else excess[guess[i]-'0']++;
                if(excess[secret[i]-'0'] > 0)cows++, excess[secret[i]-'0']--;
                else demand[secret[i]-'0']++;
            }
        }
        ostringstream A;
        A << bulls;
        string res = A.str() + "A";
        ostringstream B;
        B << cows;
        res += B.str() + "B";
        return res;
    }
};