def solution(nums):
    size = len(nums) // 2

    poket = dict()

    for num in nums:
        if num not in poket:
            poket[num] = 0
        poket[num] += 1

    print(len(poket))

    return min(size, len(poket))


print(solution([3, 1, 2, 3]))
