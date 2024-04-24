def to_binary(num):
    result = []
    while num > 0:
        result.append(num & 1)
        num >>= 1
    
    l = len(result)
    cnt = 0
    depth = 0
    while l > 0:
        if (l & 1) == 0:
            cnt += 2**depth
        l >>= 1
        depth += 1
    
    result += [0] * cnt
    
    result.reverse()
    return result, depth

def able(tree, depth):
    if depth == 1:
        return True
    
    mid = len(tree) // 2
    if tree[mid] == 0:
        return all(node == 0 for node in tree)
    
    return able(tree[:mid], depth - 1) and able(tree[mid + 1:], depth - 1)

def solution(numbers):
    answer = []
    for num in numbers:
        tree, depth = to_binary(num)
        answer.append(1 if able(tree, depth) else 0)
    
    return answer