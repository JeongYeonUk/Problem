def solution1(answers):
    answer = []

    one = [1, 2, 3, 4, 5]
    two = [2, 1, 2, 3, 2, 4, 2, 5]
    three = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

    one_cnt, two_cnt, three_cnt = 0, 0, 0
    one_len, two_len, three_len = len(one), len(two), len(three)
    for idx, a in enumerate(answers):
        if one[idx % one_len] == a:
            one_cnt += 1
        if two[idx % two_len] == a:
            two_cnt += 1
        if three[idx % three_len] == a:
            three_cnt += 1

    maxi = max([one_cnt, two_cnt, three_cnt])
    if maxi == one_cnt:
        answer.append(1)
    if maxi == two_cnt:
        answer.append(2)
    if maxi == three_cnt:
        answer.append(3)

    return answer


def solution2(answers):
    p = [[1, 2, 3, 4, 5], [2, 1, 2, 3, 2, 4, 2, 5], [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]
    s = [0] * len(p)

    for a_idx, answer in enumerate(answers):
        for p_idx, patterns in enumerate(p):
            if answer == patterns[a_idx % len(patterns)]:
                s[p_idx] += 1

    return [i + 1 for i, v in enumerate(s) if v == max(s)]


answer = solution1([1, 3, 2, 4, 2])
print(answer)
