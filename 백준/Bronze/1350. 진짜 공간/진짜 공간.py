import sys

n = int(sys.stdin.readline())
files = list(map(int, sys.stdin.readline().split()))
cluster = int(sys.stdin.readline())

answer = 0
for file in files:
    if file == 0: continue
    
    answer += (file // cluster + min(file % cluster, 1)) * cluster

print(answer)