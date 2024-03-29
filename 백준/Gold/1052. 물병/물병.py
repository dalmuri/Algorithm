def get_binary(n):
    result = []
    cnt = 0
    while n > 0:
        result.append(n & 1)
        cnt += n & 1
        n >>= 1
    return result, cnt

n, k = map(int, input().split(" "))

bnum, num_bottles = get_binary(n)
answer = 0

if num_bottles <= k:
    print(answer)
else:
    is_buying = False
    i = 0
    while i < len(bnum) and num_bottles > k:
        if not is_buying:
            if bnum[i] == 1:
                bnum[i] = 0
                is_buying = True
                answer += 2**i
        else:
            if bnum[i] == 1:
                bnum[i] = 0
                num_bottles -= 1
            else:
                bnum[i] = 1
                is_buying = False
                continue
        i += 1
    
    print(answer)