//OM NAMO NARAYANA
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == '1')
                dp[i][0] = res = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (matrix[0][i] == '1')
                dp[0][i] = res = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = (matrix[i][j] == '0') ? 0 : min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;

                res = max(res, dp[i][j]);
                // cout<<"res: "<<res<<endl;
            }
        }
        return res * res;
    }
};