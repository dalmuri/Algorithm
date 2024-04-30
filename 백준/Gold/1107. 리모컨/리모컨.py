import sys

channel = int(sys.stdin.readline())
n = int(sys.stdin.readline())
broken = list(map(int, sys.stdin.readline().split()))

buttons = [True] * 10
for b in broken:
    buttons[b] = False

answer = abs(channel - 100)

def can_make(ch):
    if ch == 0: return buttons[0]
    while ch:
        if not buttons[ch % 10]: return False
        ch //= 10
    return True


def get_close(diff):
    c = channel
    
    while c >= 0 and abs(channel - c) < answer:
        if can_make(c):
            return len(str(c)) + abs(channel - c)
        c += diff
    
    return answer


if len(broken) == 10:
    print(answer)
else:
    print(min(answer, get_close(-1), get_close(1)))