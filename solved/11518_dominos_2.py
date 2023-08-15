def dfs(graph: list, node: int, visited: list):
    if visited[node]:
        return

    visited[node] = True

    for next_node in graph[node]:
        if not visited[next_node]:
            dfs(graph, next_node, visited)


cases_count = int(input())

for _ in range(cases_count):
    dominos_count, connections_count, inits_count = map(int, input().split())
    graph = [[] for _ in range(dominos_count + 1)]
    visited = [False] * (dominos_count + 1)
    for _ in range(connections_count):
        a, b = map(int, input().split())
        graph[a].append(b)

    for _ in range(inits_count):
        a = int(input())
        dfs(graph, a, visited)

    result = visited.count(True)
    print(result)
