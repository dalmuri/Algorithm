from itertools import count

direction = [[-1, 0], [0, 1], [1, 0], [0, -1]] # 상 우 하 좌

def movable(now_x, now_y, next_x, next_y, rectangle):
    x = (now_x + next_x) / 2
    y = (now_y + next_y) / 2
    on_line = any((x1 <= x <= x2 and y in (y1, y2)) or (x in (x1, x2) and y1 <= y <= y2) for x1, y1, x2, y2 in rectangle)
    in_rectangle = any(x1 < x < x2 and y1 < y < y2 for x1, y1, x2, y2 in rectangle)
    
    return on_line and not in_rectangle

def solution(rectangle, characterX, characterY, itemX, itemY):
    now = [characterX, characterY]
    prev = None
    
    for dist in count(0):
        if now == [characterX, characterY] and prev != None: # 한 바퀴 회전
            dist_cycle = dist
            break
        elif now == [itemX, itemY]:
            dist_item = dist
        
        for d in direction:
            nxt = [now[0] + d[0], now[1] + d[1]]
            if nxt != prev and movable(*now, *nxt, rectangle):
                prev = now
                now = nxt
                break
    
    return min(dist_item, dist_cycle - dist_item)