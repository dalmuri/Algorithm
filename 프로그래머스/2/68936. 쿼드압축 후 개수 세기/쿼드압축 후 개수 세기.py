def solution(arr):
    answer = [0, 0]
    
    def check(row, col, size):
        if size == 1:
            answer[arr[row][col]] += 1
            return
        
        for r in range(row, row + size):
            for c in range(col, col + size):
                if arr[r][c] != arr[row][col]:
                    check(row, col, size // 2)
                    check(row, col + size // 2, size // 2)
                    check(row + size // 2, col, size // 2)
                    check(row + size // 2, col + size // 2, size // 2)
                    return
        answer[arr[row][col]] += 1
    
    check(0, 0, len(arr))
    
    return answer