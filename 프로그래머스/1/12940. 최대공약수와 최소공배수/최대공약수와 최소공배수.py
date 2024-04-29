def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)

def solution(n, m):
    answer = [gcd(n, m)]
    answer.append(answer[0] * (n // answer[0]) * (m // answer[0]))
    return answer