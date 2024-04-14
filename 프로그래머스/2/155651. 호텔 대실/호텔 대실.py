import heapq

def get_time(time):
    return int(time[:2]) * 60 + int(time[3:])

def solution(book_time):
    book_time.sort();
    
    rooms = [get_time(book_time[0][1])]
    for i in range(1, len(book_time)):
        if rooms[0] + 10 <= get_time(book_time[i][0]):
            heapq.heappop(rooms)
        heapq.heappush(rooms, get_time(book_time[i][1]))
    
    return len(rooms)