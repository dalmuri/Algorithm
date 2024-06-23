import sys

t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    weights = list(map(int, sys.stdin.readline().split()))
    
    acc = sum(weights)
    if acc < 0: print("Left")
    elif acc > 0: print("Right")
    else: print("Equilibrium")