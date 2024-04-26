def solution(n, cores):
    if n <= len(cores): return n
    
    n -= len(cores)
    left = 0
    right = max(cores) * n
    time = 0
    while left <= right:
        mid = (left + right) // 2
        s = sum(mid // core for core in cores)
        
        if n <= s:
            time = mid
            right = mid - 1
        else:
            left = mid + 1
    
    remain_work = n - sum((time - 1) // core for core in cores)
    answer = 0
    for i, core in enumerate(cores):
        if time % core == 0:
            remain_work -= 1
            
            if remain_work == 0:
                answer = i + 1
                break
            
    return answer