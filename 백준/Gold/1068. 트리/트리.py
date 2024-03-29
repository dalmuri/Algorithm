def delete_node(node, children, is_in_tree, deleted):
    if not is_in_tree[node]:
        return
    
    is_in_tree[node] = False
    deleted.append(node)
    for child in children[node]:
        delete_node(child, children, is_in_tree, deleted)

n = int(input())
parents = list(map(int, input().split(" ")))
to_del = int(input())

children = [[] for i in range(n)]
for i in range(n):
    if parents[i] == -1:
        continue
    
    children[parents[i]].append(i)

is_in_tree = [True for i in range(n)]
deleted = []
delete_node(to_del, children, is_in_tree, deleted)

answer = 0
for i in range(n):
    if is_in_tree[i]:
        is_leaf = True
        for child in children[i]:
            if not (child in deleted):
                is_leaf = False
                break
        
        if is_leaf:
            answer += 1

print(answer)