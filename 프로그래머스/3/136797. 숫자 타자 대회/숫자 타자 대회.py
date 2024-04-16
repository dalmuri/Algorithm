def get_dist():
    coordinate = [(3, 1), (0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2), (2, 0), (2, 1), (2, 2)]
    dist = [[1] * 10 for i in range(10)]
    for i in range(9):
        for j in range(i + 1, 10):
            diff_r = abs(coordinate[i][0] - coordinate[j][0])
            diff_c = abs(coordinate[i][1] - coordinate[j][1])
            
            distance = 0
            if diff_r > 0 and diff_c > 0:
                tmp = min(diff_r, diff_c)
                diff_r -= tmp
                diff_c -= tmp
                distance += tmp * 3
            
            if diff_r > 0: distance += diff_r * 2
            elif diff_c > 0: distance += diff_c * 2
            
            dist[i][j] = distance
            dist[j][i] = distance
    
    return dist

def solution(numbers):
    dist = get_dist() # dist[i][j] = i에서 j로 이동해 누를 때의 가중치
    
    inf = 300_001 # 무한대로 취급. numbers의 길이가 최대 100,000 이므로 가중치 합은 항상 300,000 이하
    weights = [[[inf] * 10 for i in range(10)] for n in range(len(numbers) + 1)]
    # weights[i+1][l][r] = numbers[i]까지 누른 후 왼손과 오른손이 각각 l, r 위에 있을 때의 가중치 합의 최솟값
    weights[0][4][6] = 0
    
    for i in range(1, len(numbers) + 1):
        num = int(numbers[i - 1])
        
        for l in range(10):
            for r in range(10):
                if weights[i - 1][l][r] == inf: continue
                
                # 가만히
                if l == num or r == num:
                    weights[i][l][r] = min(weights[i][l][r], weights[i - 1][l][r] + 1)
                    continue
                
                # 왼손 이동
                weights[i][num][r] = min(weights[i][num][r], weights[i - 1][l][r] + dist[l][num])
                
                # 오른손 이동
                weights[i][l][num] = min(weights[i][l][num], weights[i - 1][l][r] + dist[r][num])
    
    return min(map(min, weights[len(numbers)]))