//OM NAMO NARAYANA
//https://leetcode.com/problems/longest-repeating-character-replacement/submissions/
class Solution {
public:
    
    //changing max() to if() resulted in 3x faster solution
    int characterReplacement(string s, int k) {
        int i=0, j=0, res=0, n=s.size(), count[26]={0}, maxCount=0;
        for(; i < n; i++){
            if(++count[s[i]-'A'] > maxCount)maxCount=count[s[i]-'A'];
            
            //this is necessay condition for the window to be valid
            //if the most repeated character's freq + K < window size the window is not valid
            //However, this is not the sufficient condition. since the count of most repeated 
            //character can go down. Hence, the actual maxCount should change
            
            if(i-j+1 - maxCount > k){do{count[s[j++]-'A']--;}while(i-j+1 - maxCount > k);}
            
            //However given a valid window, it's understantable that we should try to update the 
            //all the elements in the window to the most occuring character before updation
            else if(res < i-j+1)res = i-j+1;
        }
        return res;
    }
};