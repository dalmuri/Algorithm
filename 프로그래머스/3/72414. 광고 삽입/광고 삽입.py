def str2int(time):
    h = int(time[:2])
    m = int(time[3:5])
    s = int(time[6:])
    
    return h * 3600 + m * 60 + s

def int2str(time):
    h = time // 3600
    time %= 3600
    m = time // 60
    time %= 60
    s = time
    
    return str(h).zfill(2) + ":" + str(m).zfill(2) + ":" + str(s).zfill(2)

def solution(play_time, adv_time, logs):
    play = str2int(play_time)
    prefix_sum = [0] * (play + 1)
    for log in logs:
        start = str2int(log[:8])
        end = str2int(log[9:])
        
        prefix_sum[start] += 1
        prefix_sum[end] -= 1
    
    for i in range(play + 1): prefix_sum[i] += prefix_sum[i - 1] # 초마다 시청자 수 계산
    for i in range(play + 1): prefix_sum[i] += prefix_sum[i - 1] # 누적합으로 변경
    
    adv = str2int(adv_time)
    max_start_time = 0
    max_accm = prefix_sum[adv - 1]
    for i in range(1, play - adv + 1):
        if max_accm < prefix_sum[i + adv - 1] - prefix_sum[i - 1]:
            max_accm = prefix_sum[i + adv - 1] - prefix_sum[i - 1]
            max_start_time = i
    
    return int2str(max_start_time)