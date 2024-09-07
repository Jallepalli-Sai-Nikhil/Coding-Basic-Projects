def find_sum(num):
    s = 0
    while(num > 0):
        digit = int(num%10)
        s = s + digit
        num = int(num/10)
    return s

print(find_sum(12))


def find_sum_optimized(num):
    s = 0
    for digit in str(num):
        s += int(digit)
    return s


print(find_sum_optimized(12))