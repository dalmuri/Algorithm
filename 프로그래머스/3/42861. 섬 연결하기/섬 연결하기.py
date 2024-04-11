def get_root(num, parent):
    if parent[num] == -1:
        return num
    else:
        return get_root(parent[num], parent)

def solution(n, costs):
    costs.sort(key = lambda x : x[2])
    parent = [-1] * n
    
    answer = 0
    cnt = 0
    for cost in costs:
        node1 = cost[0]
        node2 = cost[1]
        
        if get_root(node1, parent) != get_root(node2, parent):
            cnt += 1
            parent[get_root(node2, parent)] = node1
            answer += cost[2]
            
            if cnt == n - 1:
                break
    
    return answer