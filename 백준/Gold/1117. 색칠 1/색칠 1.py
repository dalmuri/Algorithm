import sys

w, h, f, c, x1, y1, x2, y2 = map(int, sys.stdin.readline().split())

folded = f if f * 2 <= w else w - f

print(w * h - (max(0, (min(x2, folded) - x1) * (y2 - y1) * (c + 1) * 2) + max(0, (x2 - max(x1, folded)) * (y2 - y1) * (c + 1))))