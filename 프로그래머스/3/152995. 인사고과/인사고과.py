def solution(scores):
    wanho = scores[0]
    wanho_score = wanho[0] + wanho[1]
    
    # 근무 태도 점수를 기준으로 내림차순 정렬
    # 근무 태도 점수가 동일할 경우 동료 평가 점수를 기준으로 오름차순 정렬
    scores.sort(reverse=True, key= lambda s : (s[0], -s[1]))
    
    answer = 1
    now_attitude = scores[0][0] # 현재의 근무 태도 점수 그룹
    upper_peer_max = -1 # 상위 그룹의 동료 평가 점수의 최댓값
    for score in scores:
        if wanho[0] < score[0] and wanho[1] < score[1]: # 완호가 인센티브를 받지 못하는 경우
            return -1
        
        if score[1] < upper_peer_max: # 현재 사원이 인센티브를 받지 못하는 경우
            continue
        
        upper_peer_max = max(upper_peer_max, score[1])
        if wanho_score < score[0] + score[1]: # 인센티브를 받을 수 있는 사원의 두 점수의 합이 완호보다 높은 경우
            answer += 1
    
    return answer