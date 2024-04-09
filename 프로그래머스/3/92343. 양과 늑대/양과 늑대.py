def search(now, sheep, wolf, visited, info, edges):
    if wolf >= sheep:
        return sheep
    
    result = sheep
    for edge in edges:
        parent, child = edge
        
        if visited[parent] and not visited[child]:
            visited[child] = True
            
            if info[child] == 0:
                result = max(result, search(child, sheep + 1, wolf, visited, info, edges))
            else:
                result = max(result, search(child, sheep, wolf + 1, visited, info, edges))
            
            visited[child] = False
    
    return result

def solution(info, edges):
    visited = [False for i in range(len(info))]
    visited[0] = True
    
    return search(0, 1, 0, visited, info, edges)