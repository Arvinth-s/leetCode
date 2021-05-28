//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        bool visited[n];
        memset(visited, false, sizeof(visited));
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                res++;
                queue<int> st;
                st.push(i);
                while (!st.empty())
                {
                    int u = st.front();
                    visited[u] = true;
                    st.pop();
                    for (int v = 0; v < n; v++)
                    {
                        if (isConnected[u][v] && !visited[v])
                        {
                            st.push(v);
                        }
                    }
                }
            }
        }
        return res;
    }
};