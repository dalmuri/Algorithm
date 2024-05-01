import sys

n, m = map(int, sys.stdin.readline().split())

knows_truth = [False] * (n + 1)
line = list(map(int, sys.stdin.readline().split()))
if line[0] > 0:
    for i in range(1, len(line)):
        knows_truth[line[i]] = True

party = []
for _ in range(m):
    line = list(map(int, sys.stdin.readline().split()))
    party.append(line[1:])


prev = knows_truth.count(True)
while True:
    for p in party:
        if any(knows_truth[person] for person in p):
            for person in p:
                knows_truth[person] = True
    
    if prev == knows_truth.count(True): break
    prev = knows_truth.count(True)

answer = 0
for p in party:
    if all(not knows_truth[person] for person in p):
        answer += 1

print(answer)