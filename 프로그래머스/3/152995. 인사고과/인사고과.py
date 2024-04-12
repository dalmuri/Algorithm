def solution(scores):
    wanho = scores[0]
    wanho_score = wanho[0] + wanho[1]
    
    scores.sort(reverse=True, key=lambda s : s[0]) # 근무태도 점수를 기준으로 내림차순 정렬
    
    answer = 1
    now_attitude = scores[0][0] # 현재의 근무 태도 점수 그룹
    upper_peer_max = -1 # 상위 그룹의 동료 평가 점수의 최댓값
    now_peer_max = -1 # 현재 그룹의 동료 평가 점수의 최댓값
    for score in scores:
        if score[0] != now_attitude:
            now_attitude = score[0]
            upper_peer_max = max(upper_peer_max, now_peer_max)
            
            # 그룹이 바뀔 때마다 완호가 인센티브를 받지 못하는지 확인함
            if wanho[0] <= now_attitude and wanho[1] < upper_peer_max:
                return -1
        
        now_peer_max = max(now_peer_max, score[1])
        if score[1] < upper_peer_max: # 현재 사원이 인센티브를 받지 못하는 경우
            continue
        
        if wanho_score < score[0] + score[1]: # 인센티브를 받을 수 있는 사원의 두 점수의 합이 완호보다 높은 경우
            answer += 1
    
    return answer