def solution(k, ranges):
    # 콜라츠 추측 계산
    collatz = [k]
    while k > 1:
        k = k // 2 if (k & 1) == 0 else k * 3 + 1
        collatz.append(k)
    
    # 길이 1의 구간마다 넓이 계산
    areas = [(collatz[i] + collatz[i + 1]) / 2 for i in range(len(collatz) - 1)]
    
    # 정답 계산
    answer = []
    for start, b in ranges:
        end = len(areas) + b
        answer.append(sum(areas[start:end]) if start <= end else -1)
    
    return answer