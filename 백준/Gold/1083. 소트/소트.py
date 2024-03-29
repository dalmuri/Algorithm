def sort(now, arr, s):
    max_idx = now
    for i in range(now, min(len(arr), now + s + 1)):
        if arr[max_idx] < arr[i]:
            max_idx = i
    
    s -= max_idx - now
    max_num = arr[max_idx]
    del arr[max_idx]
    arr.insert(now, max_num)
    
    return s

n = int(input())
arr = list(map(int, input().split(" ")))
s = int(input())

i = 0
while i < n and s > 0:
    s = sort(i, arr, s)
    i += 1

print(*arr)