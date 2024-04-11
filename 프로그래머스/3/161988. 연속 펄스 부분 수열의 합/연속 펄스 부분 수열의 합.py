import copy

def max_sum(arr):
    now_max = [arr[0]]
    result = arr[0]
    for i in range(1, len(arr)):
        now_max.append(max(0, now_max[i - 1]) + arr[i])
        result = max(result, now_max[i])
    
    return result

def solution(sequence):
    seq1 = copy.deepcopy(sequence)
    idx = 0
    while idx < len(seq1):
        seq1[idx] *= -1
        idx += 2
    
    seq2 = copy.deepcopy(sequence)
    idx = 1
    while idx < len(seq2):
        seq2[idx] *= -1
        idx += 2
    
    return max(max_sum(seq1), max_sum(seq2))