def solution(n, times):
    left, right = 1, max(times) * n
    answer = right
    while left <= right:
        mid = (left + right) // 2
        s = sum(mid // time for time in times)
        
        if n <= s:
            answer = mid
            right = mid - 1
        else:
            left = mid + 1
    
    return answer