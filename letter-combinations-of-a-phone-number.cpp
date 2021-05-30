//OM NAMO NARAYANA

//string concatenation - faster than 9%
//string push pop - faster than 100%

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    
    vector<string> recur(string digits, int i){
        vector<string> res;
        if(i<0)return vector<string>{""};
        unordered_map<char, vector<char> > mp;
        mp['2'] = vector<char>{'a', 'b', 'c'};
        mp['3'] = vector<char>{'d', 'e', 'f'};
        mp['4'] = vector<char>{'g', 'h', 'i'};
        mp['5'] = vector<char>{'j', 'k', 'l'};
        mp['6'] = vector<char>{'m', 'n', 'o'};
        mp['7'] = vector<char>{'p', 'q', 'r', 's'};
        mp['8'] = vector<char>{'t', 'u', 'v'};
        mp['9'] = vector<char>{'w', 'x', 'y', 'z'};
        
        vector<string> rem=recur(digits, i-1);
        for(string s:rem){
            for(char r:mp[digits[i]]){
                s.push_back(r);
                res.push_back(s);
                s.pop_back();
            }
        }
        return res;
        
    }
    
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return vector<string>();
        return recur(digits, digits.size()-1);
    }
};