from collections import defaultdict

def len_starseq(num, a):
    result = 0
    i = 0
    while i + 1 < len(a):
        if a[i] != a[i + 1] and (a[i] == num or a[i + 1] == num):
            result += 2
            i += 1
        
        i += 1
    
    return result

def solution(a):
    counts = defaultdict(int)
    for num in a:
        counts[num] += 1
    
    answer = 0
    for num in counts.keys():
        if counts[num] * 2 <= answer:
            continue
        
        answer = max(answer, len_starseq(num, a))
    
    return answer