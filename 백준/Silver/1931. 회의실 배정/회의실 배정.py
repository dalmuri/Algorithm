import sys

n = int(sys.stdin.readline())
meetings = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]
meetings.sort(key=lambda x: (x[1], x[0]))

answer = 0
end_time = 0
for start, end in meetings:
    if end_time <= start:
        answer += 1
        end_time = end

print(answer)