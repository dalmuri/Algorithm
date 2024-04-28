def solution(food):
    answer = ""
    for i, f in enumerate(food):
        answer += str(i) * (f // 2)
    return answer + "0" + answer[::-1]