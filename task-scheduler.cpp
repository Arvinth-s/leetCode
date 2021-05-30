//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int res=0;
        priority_queue<int> pq;

        n++;
        for(char ch:tasks)freq[ch-'A']++;
        for (int f : freq)
            if (f > 0)
                pq.push(f);

        while(pq.size()>0){ 
            int x=pq.size();
            int mn, temp[x];
            
            
            for(int i=0; i<x; i++){
                temp[i]=pq.top();
                pq.pop();
            }
            
            mn = (x>n)?temp[n-1]-temp[n]+1:temp[x-1];
            res += n*mn;
            
            
            for(int i=0; i<min(n,x); i++){
                temp[i] -= mn;
                if(temp[i]>0)pq.push(temp[i]);
            }
            
            
            for(int i=n; i<x; i++)
                pq.push(temp[i]);
            
            if(pq.size()==0)res -= n-x;
        
        }
        
        
        return res;
        
        
    }
};