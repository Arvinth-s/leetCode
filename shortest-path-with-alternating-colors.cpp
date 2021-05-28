//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {

        
        vector<vector<vector<int> > > edges(2, vector<vector<int> >(n, vector<int>()));
        vector<vector<int> > res(2, vector<int>(n, -1));
        vector<int> ans(n);
        queue<vector<int> > q;
        
        
        res[0][0]=res[1][0]=0;
        
        q.push(vector<int>{0, 0, 0});
        q.push(vector<int>{0, 0, 1});
        
        
        for(vector<int> e:red_edges) edges[0][e[0]].push_back(e[1]);
        for(vector<int> e:blue_edges) edges[1][e[0]].push_back(e[1]);
        
        
        while(!q.empty()){
            vector<int> u = q.front();
            q.pop();
            int uidx=u[0], uval=u[1], color = 1-u[2];

            
            for(int i=0; i<edges[color][uidx].size(); i++){
                int v = edges[color][uidx][i];
                if(res[color][v]==-1 || res[color][v] > uval+1){
                    res[color][v]= uval+1;
                    q.push(vector<int>{v, res[color][v], color});
                }
            }
        }
        
        
        for(int i=0; i<n; i++){
            if(res[0][i]==-1)ans[i]=res[1][i];
            else if(res[1][i]==-1)ans[i] = res[0][i];
            else ans[i] = min(res[0][i], res[1][i]);
        }
        
        return ans;
    }
};