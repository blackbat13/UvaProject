#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited);

int main()
{
    int a, b, casesCount, dominosCount, connectionsCount, initsCount, result;
    vector<vector<int>> graph;
    vector<bool> visited;

    scanf("%d", &casesCount);
    for (int caseId = 1; caseId <= casesCount; ++caseId)
    {
        scanf("%d %d %d", &dominosCount, &connectionsCount, &initsCount);
        graph = vector<vector<int>>(dominosCount + 1, vector<int>());
        visited = vector<bool>(dominosCount + 1, false);
        for (int i = 0; i < connectionsCount; ++i)
        {
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
        }

        for (int i = 0; i < initsCount; ++i)
        {
            scanf("%d", &a);
            dfs(graph, a, visited);
        }
        
        result = 0;
        for (auto const &el : visited)
        {
            if (el)
            {
                ++result;
            }
        }

        printf("%d\n", result);
    }

    return 0;
}

void dfs(vector<vector<int>> &graph, int node, vector<bool> &visited)
{
    if (visited[node])
    {
        return;
    }

    visited[node] = true;
    for (int i = 0; i < graph[node].size(); ++i)
    {
        if (!visited[graph[node][i]])
        {
            dfs(graph, graph[node][i], visited);
        }
    }
}