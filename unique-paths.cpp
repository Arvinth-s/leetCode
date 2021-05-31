//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long res=1;
        for(int i=max(n,m); i<=m+n-2; i++)res*=i;
        for(int i=2; i<=min(m,n)-1; i++)res/=i;
        return res;
        
    }
};