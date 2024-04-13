def move(dist, rng, boundary):
    rng[0] += 0 if (rng[0] == 0 and dist > 0) else dist
    rng[1] += 0 if (rng[1] == boundary - 1 and dist < 0) else dist
    
    if rng[0] >= boundary or rng[1] < 0:
        return False
    
    rng[0] = max(rng[0], 0)
    rng[1] = min(rng[1], boundary - 1)
    
    return True

def solution(n, m, x, y, queries):
    reverse_dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]
    
    row_range = [x, x]
    col_range = [y, y]
    
    for query in reversed(queries):
        if query[0] > 1: # move row
            dist = reverse_dir[query[0]][0] * query[1]
            if not move(dist, row_range, n):
                return 0
        
        else: # move column
            dist = reverse_dir[query[0]][1] * query[1]
            if not move(dist, col_range, m):
                return 0
    
    return (row_range[1] - row_range[0] + 1) * (col_range[1] - col_range[0] + 1)