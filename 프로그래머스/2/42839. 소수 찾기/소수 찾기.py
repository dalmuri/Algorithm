from itertools import permutations

def solution(numbers):
    is_prime = [True] * 10**len(numbers)
    is_prime[0] = False
    is_prime[1] = False
    
    for i in range(2, len(is_prime)):
        if not is_prime[i]: continue
        
        for j in range(i << 1, len(is_prime), i):
            is_prime[j] = False
    
    answer = set()
    
    for length in range(1, len(numbers) + 1):
        for num_tuple in permutations(numbers, length):
            num = int("".join(num_tuple))
            if is_prime[num]: answer.add(num)
    
    return len(answer)