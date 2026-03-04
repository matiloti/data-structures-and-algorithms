def out_of_bounds(node, graph):
    return node[0] < 0 or node[1] < 0 or node[0] >= len(graph) or node[1] >= len(graph)

def dfs(graph, node, depth):
    paths = [[0,-1],[1,0],[0,1],[-1,0]]
    maxD = depth
    for path in paths:
        curr = [node[0] + path[0], node[1] + path[1]]
        if not out_of_bounds(curr, graph) and graph[node[0]][node[1]] < graph[curr[0]][curr[1]]:
            maxD = max(maxD, dfs(graph, curr, depth+1))
    return maxD
            

def longest_path(graph):
    maxD = 0
    for x in range(len(graph)):
        for y in range(len(graph)):
            maxD = max(maxD, dfs(graph, [x,y], 1))
    return maxD

input = [[3,5,8], [3,4,4], [9,9,9]]
print(longest_path(input))
