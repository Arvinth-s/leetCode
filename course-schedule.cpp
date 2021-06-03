//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

/*
Finding cycle in directed graph
solution: DFS

faster than 44%
*/

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {

        bool visited[numCourses], presentCycle[numCourses];
        memset(visited, false, sizeof(visited));
        vector<vector<int>> graph(numCourses, vector<int>());
        for (vector<int> prerequisite : prerequisites)
        {
            graph[prerequisite[0]].push_back(prerequisite[1]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i])
            {
                memset(presentCycle, false, sizeof(presentCycle));
                stack<int> st;

                visited[i] = true;
                presentCycle[i] = true;
                st.push(i);

                while (!st.empty())
                {
                    int u = st.top();
                    for (int v : graph[u])
                    {
                        if (!presentCycle[v])
                        {
                            if (visited[v])
                                continue;
                            visited[v] = true;
                            presentCycle[v] = true;
                            st.push(v);
                            break;
                        }
                        else
                        {
                            return false;
                        }
                    }

                    if (st.top() == u)
                    {
                        st.pop();
                        presentCycle[u] = false;
                    }
                }
            }
        }

        return true;
    }
};