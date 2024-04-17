def solution(n, stations, w):
    answer = 0
    
    wave_len = w * 2 + 1 # 전파 전달 거리
    for i in range(0, len(stations) + 1):
        # 전파가 닿지 않는 아파트 구간의 시작과 끝
        start = stations[i - 1] + w + 1 if i > 0 else 1
        end = stations[i] - w - 1 if i < len(stations) else n
        
        count = end - start + 1 # 전파가 닿지 않는 아파트의 수
        if count > 0:
            answer += count // wave_len + min(count % wave_len, 1)
    
    return answer