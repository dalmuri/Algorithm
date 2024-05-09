import sys

def valid(ps):
    cnt = 0
    for c in ps:
        if c == '(':
            cnt += 1
        else:
            if cnt:
                cnt -= 1
            else:
                return False
    
    return cnt == 0


n = int(sys.stdin.readline())

for _ in range(n):
    ps = sys.stdin.readline().strip()
    
    print("YES" if valid(ps) else "NO")