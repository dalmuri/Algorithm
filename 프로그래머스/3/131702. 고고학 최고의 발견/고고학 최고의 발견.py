import copy
import math

# clockHands[row][col]과 그 상하좌우의 시계를 cnt 횟수만큼 조작
def turn(row, col, n, cnt, clockHands):
    clockHands[row][col] = (clockHands[row][col] + cnt) % 4
    
    if row > 0 : clockHands[row - 1][col] = (clockHands[row - 1][col] + cnt) % 4
    if row + 1 < n : clockHands[row + 1][col] = (clockHands[row + 1][col] + cnt) % 4
    if col > 0 : clockHands[row][col - 1] = (clockHands[row][col - 1] + cnt) % 4
    if col + 1 < n : clockHands[row][col + 1] = (clockHands[row][col + 1] + cnt) % 4

# 첫 번째 행에 맞춰 다른 모든 행을 조작하여 그 횟수를 반환
# 모든 시계가 12시를 바라보지 않는다면 -1을 반환
def control(n, clockHands):
    cnt = 0
    for r in range(1, n):
        for c in range(n):
            if clockHands[r - 1][c] > 0:
                cnt += 4 - clockHands[r - 1][c]
                turn(r, c, n, 4 - clockHands[r - 1][c], clockHands)
    
    for c in range(n):
        if clockHands[n - 1][c] > 0:
            return -1
    
    return cnt

# 첫 번째 행을 조작하여 조작 횟수를 반환
def set_row0(num, n, clockHands):
    cnt = 0
    for c in range(n):
        t = num % 4
        num //= 4
        
        if t > 0:
            turn(0, c, n, t, clockHands)
            cnt += t
        
        if num == 0: break;
    
    return cnt

def solution(clockHands):
    n = len(clockHands)
    answer = math.inf
    
    for i in range(4**n):
        cpy = copy.deepcopy(clockHands)
        cnt1 = set_row0(i, n, cpy) # 첫 번째 행 조작
        
        cnt2 = control(n, cpy) # 다른 모든 행 조작
        if cnt2 != -1:
            answer = min(answer, cnt1 + cnt2) # 조작 성공
    
    return answer