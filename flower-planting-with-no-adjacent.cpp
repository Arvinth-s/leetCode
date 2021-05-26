//OM  NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        vector<vector<int>> edges(n, vector<int>());
        for (vector<int> path : paths)
        {
            edges[path[0] - 1].push_back(path[1] - 1);
            edges[path[1] - 1].push_back(path[0] - 1);
        }

        bool visited[n];
        vector<int> res(n);
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                visited[i] = true;
                res[i] = 1;
                stack<int> st;
                st.push(i);
                while (!st.empty())
                {

                    int u = st.top();
                    st.pop();
                    visited[u] = true;
                    bool colors[4] = {false, false, false, false};
                    for (int v : edges[u])
                    {
                        if (!visited[v])
                        {
                            for (int v2 : edges[v])
                            {
                                if (visited[v2])
                                {
                                    colors[res[v2] - 1] = true;
                                }
                            }
                            for (int j = 0; j < 4; j++)
                            {
                                if (!colors[j])
                                {
                                    res[v] = j + 1;
                                    st.push(v);
                                }
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int v : edges[i])
            {
                assert(res[v] != res[i]);
            }
        }

        return res;
    }
};