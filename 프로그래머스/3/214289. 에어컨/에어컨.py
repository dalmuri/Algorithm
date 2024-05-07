def solution(temperature, t1, t2, a, b, onboard):
    inf = 10**6
    target = max(temperature - t2, t1 - temperature)
    dp = [[inf] * (target + 2) for _ in range(len(onboard))]
    # dp[i][j] = i시각에 j온도가 되기 위한 최소 비용
    dp[0][0] = 0
    for i in range(1, len(onboard)):
        start = target if onboard[i] else 0
        end = target + 1
        
        for j in range(start, end + 1):
            if j > 0: dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a) # ON
            if j == 0: dp[i][j] = min(dp[i][j], dp[i - 1][j]) # 외부온도와 동일한 상황 유지
            else: dp[i][j] = min(dp[i][j], dp[i - 1][j] + b) # ON 유지
            if j < target + 1: dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]) # OFF
    
    return min(dp[len(onboard) - 1])