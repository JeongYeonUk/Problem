def int_to_bit(n):
    n_bit = []
    while n:
        n_bit.append(n % 2)
        n = n // 2

    return n_bit.count(1)


def solution(n):
    n_bit_count = int_to_bit(n)
    n = n + 1
    while True:
        next_bit_count = int_to_bit(n)
        if next_bit_count == n_bit_count:
            break
        n = n + 1
    return n


if __name__ == "__main__":
    print(solution(78))
