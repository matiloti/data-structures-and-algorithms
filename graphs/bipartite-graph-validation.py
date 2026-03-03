def dfs(graph, colors, color, curr):
    colors[curr] = color
    for node in graph[curr]:
        if node in colors:
            if colors[node] == color:
                return False
        else:
            if not dfs(graph, colors, not color, node):
                return False
    return True

def bipartite(graph):
    colors = {}
    for node in range(len(graph)):
        if node not in colors:
            if not dfs(graph, colors, True, node):
                return False
    return True

input = [[1,4], [0,2], [1], [4], [0,3]]
print(bipartite(input))

input = [[1,4], [0,2], [1], [4,2], [0,3]]
print(bipartite(input))