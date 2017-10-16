//
// Created by Damian Kurpiewski on 11.07.2017.
//

#include <cstdio>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

/// Incidence list of the weighted graph
vector<vector<pair<int, int> > > graph;

/// Distance to each node from starting node
vector<int> distances;

void dijkstra(int node) {
    queue<pair<int, pair<int, int> > > nodes;

    distances.clear();
    distances = vector<int>(graph.size(), INT_MAX);
    distances[node] = 0;

    for (int i = 0; i < graph[node].size(); i++) {
        nodes.push(make_pair(graph[node][i].second, make_pair(node, graph[node][i].first)));
    }

    while (!nodes.empty()) {
        int distance;
        int from_node;
        int new_distance;
        node = nodes.front().second.second;
        distance = nodes.front().first;
        from_node = nodes.front().second.first;

        nodes.pop();

        new_distance = distances[from_node] + distance;

        if (new_distance >= distances[node]) {
            continue;
        }

        distances[node] = new_distance;

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            distance = graph[node][i].second;
            nodes.push(make_pair(distance, make_pair(node, next_node)));
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        int n, m, p, q;
        scanf("%d %d %d %d", &n, &m, &p, &q);
        graph.clear();
        graph = vector<vector<pair<int, int> > >(n);
        for(int i = 0; i < m; ++i) {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            graph[a].push_back(make_pair(b, w));
            graph[b].push_back(make_pair(a, w));
        }

        dijkstra(p);
        printf("Case #%d: ", t);
        if(distances[q] == INT_MAX) {
            printf("unreachable\n");
        } else {
            printf("%d\n", distances[q]);
        }
    }
}