//OM NAMO NARAYANA
//https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/submissions/

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int> > matrix;
        vector<int> row(m);
        vector<long> col(m);
        for(int i = 0; i < n; i++){
            row[0]=rowSum[i];
            matrix.push_back(row);
            col[0] += rowSum[i];
        }
        
        int i = 0, j = 1;
        while(j < m){
            if(col[j] == colSum[j]){j++;continue;}
            while(colSum[j]-col[j] >= matrix[i][0]){
                swap(matrix[i][0], matrix[i][j]);
                col[0] -= matrix[i][j];
                col[j] += matrix[i][j];
                i++;
            }
            if(colSum[j] > col[j]){
                matrix[i][j] = colSum[j] - col[j];
                matrix[i][0] -= matrix[i][j];
                col[j] = colSum[j];
                j++;
            }
        }
        return matrix;
    }
};