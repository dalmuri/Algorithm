def solution(target):
    points = [[100_001, -1] for _ in range(target + 1)]
    points[0] = [0, 0]
    for n in range(target + 1):
        # 싱글
        for i in range(1, 21):
            if n + i > target: break
            
            if points[n + i][0] > points[n][0] + 1 or (points[n + i][0] == points[n][0] + 1 and points[n + i][1] < points[n][1] + 1):
                points[n + i] = [points[n][0] + 1, points[n][1] + 1]
        
        # 더블
        for i in range(2, 41, 2):
            if n + i > target: break
            
            if points[n + i][0] > points[n][0] + 1 or (points[n + i][0] == points[n][0] + 1 and points[n + i][1] < points[n][1]):
                points[n + i] = [points[n][0] + 1, points[n][1]]
        
        # 트리플
        for i in range(3, 61, 3):
            if n + i > target: break
            
            if points[n + i][0] > points[n][0] + 1 or (points[n + i][0] == points[n][0] + 1 and points[n + i][1] < points[n][1]):
                points[n + i] = [points[n][0] + 1, points[n][1]]
        
        # 불
        if n + 50 > target: continue
        
        if points[n + 50][0] > points[n][0] + 1 or (points[n + 50][0] == points[n][0] + 1 and points[n + 50][1] < points[n][1] + 1):
            points[n + 50] = [points[n][0] + 1, points[n][1] + 1]
    
    return points[target]