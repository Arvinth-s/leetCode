//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

/*
faster than 58% 
*/

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), res = 0;
        bool visited[m][n];
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    res++;
                    stack<pair<int, int>> st;
                    st.push(pair<int, int>(i, j));
                    visited[i][j] = true;

                    while (!st.empty())
                    {
                        pair<int, int> u = st.top();
                        st.pop();

                        if (u.first > 0 && grid[u.first - 1][u.second] == '1' && !visited[u.first - 1][u.second])
                        {
                            st.push(pair<int, int>(u.first - 1, u.second));
                            visited[u.first - 1][u.second] = true;
                        }

                        if (u.second > 0 && grid[u.first][u.second - 1] == '1' && !visited[u.first][u.second - 1])
                        {
                            st.push(pair<int, int>(u.first, u.second - 1));
                            visited[u.first][u.second - 1] = true;
                        }

                        if (u.first < m - 1 && grid[u.first + 1][u.second] == '1' && !visited[u.first + 1][u.second])
                        {
                            st.push(pair<int, int>(u.first + 1, u.second));
                            visited[u.first + 1][u.second] = true;
                        }

                        if (u.second < n - 1 && grid[u.first][u.second + 1] == '1' && !visited[u.first][u.second + 1])
                        {
                            st.push(pair<int, int>(u.first, u.second + 1));
                            visited[u.first][u.second + 1] = true;
                        }
                    }
                }
            }
        }

        return res;
    }
};