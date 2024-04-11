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
    seq2 = copy.deepcopy(sequence)
    
    for i in range(len(sequence)):
        if i % 2 == 0:
            seq1[i] *= -1
        else:
            seq2[i] *= -1
    
    return max(max_sum(seq1), max_sum(seq2))
