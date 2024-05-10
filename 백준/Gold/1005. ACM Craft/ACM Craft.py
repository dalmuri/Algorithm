import sys
sys.setrecursionlimit(10**5)

t = int(sys.stdin.readline())

for _ in range(t):
    n, k = map(int, sys.stdin.readline().split())
    delays = [0] + list(map(int, sys.stdin.readline().split()))
    before = [[] for i in range(n + 1)]
    for i in range(k):
        x, y = map(int, sys.stdin.readline().split())
        before[y].append(x)
    
    w = int(sys.stdin.readline())
    times = [-1] * (n + 1)
    
    def calc(building):
        if times[building] != -1: return times[building]
        
        time = 0
        for i in before[building]:
            time = max(time, calc(i))
        
        time += delays[building]
        times[building] = time
        return time
    
    
    print(calc(w))