//OM NAMO NARAYANA


https://leetcode.com/problems/max-consecutive-ones-iii/submissions/

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int res = 0, n = A.size();
        //solution: [q.front()+1, i-1]
        //size K+1
        //j = zero.front()+1
        queue<int> zero;
        zero.push(-1);
        for(int i = 0; i < n-1; i++){
            if(A[i]==0){
                //already 1 zero extra. Don't include zero.front() and i
                if(zero.size()==K+1){
                    res = max(res, i-zero.front()-1);//[zero.front()+1, i-1]
                    zero.pop();
                }
                zero.push(i);
            }
        }
        
        //if entire array doesn't contain K zeros
        if(zero.size()<=K){
            return n;
        }
        
        assert(zero.size()==K+1);//contains 1 zero which shouldn't be included
        return max(res, (A[n-1]==0)?(n-1-zero.front()-1):(n-zero.front()-1) );//[zero.front()+1, n-2] or [zero.front()+1, n-1]
    }            

};