//OM NAMO NARAYANA
//https://leetcode.com/problems/4sum-ii/submissions/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size(), res=0;
        if(n==0)return 0;
        unordered_map<int, int> AB, CD;
        vector<int> ABs;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                AB[A[i]+B[j]]=(AB.find(A[i]+B[j])==AB.end())?ABs.push_back(A[i]+B[j]), 1:AB[A[i]+B[j]]+1;
                CD[C[i]+D[j]]=(CD.find(C[i]+D[j])==CD.end())?1:CD[C[i]+D[j]]+1;
            }
        }
        for(int val:ABs)
            if(CD.find(-val)!=CD.end())
                res += CD[-val]*AB[val];
        return res;
        
    }
};