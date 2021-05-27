//OM NAMO NARAYANA
//https://leetcode.com/problems/search-a-2d-matrix/submissions/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int start = 0, end = n-1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(matrix[mid][0] <= target && matrix[mid][m-1] >= target){
                int idx = lower_bound(matrix[mid].begin(), matrix[mid].end(), target) - matrix[mid].begin();
                return matrix[mid][idx]==target;
            }
            if(matrix[mid][m-1] < target){
                start=mid+1;
            }else {
                assert(matrix[mid][0] > target);
                end=mid-1;
            }
        }
        return false;
    }
};