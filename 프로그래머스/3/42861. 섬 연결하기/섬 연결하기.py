def get_root(num, parent):
    if parent[num] == num:
        return num
    else:
        return get_root(parent[num], parent)

def solution(n, costs):
    parent = list(range(n))
    
    costs.sort(key = lambda x : x[2])
    answer = 0
    cnt = 0
    for cost in costs:
        root1 = get_root(cost[0], parent)
        root2 = get_root(cost[1], parent)
        
        if root1 != root2:
            cnt += 1
            answer += cost[2]
            parent[root2] = root1
            
            if cnt == n - 1:
                break
    
    return answer