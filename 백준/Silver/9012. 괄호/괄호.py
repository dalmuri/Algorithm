import sys

def valid(ps):
    stk = []
    for c in ps:
        if c == '(':
            stk.append(c)
        else:
            if stk:
                stk.pop()
            else:
                return False
    
    return len(stk) == 0


n = int(sys.stdin.readline())

for _ in range(n):
    ps = sys.stdin.readline().strip()
    
    print("YES" if valid(ps) else "NO")