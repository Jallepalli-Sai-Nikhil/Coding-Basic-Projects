def prefect(n):
    Sum = 0
    for i in range(1,n):
        if(n %i==0):
            Sum += i

    if(Sum == n):
        return True
    else:
        return False


def using_sqrt(n):
    if n <= 1:
        return False

    divisors_sum = 1
    i = 2
    sqrt_n = int(n**0.5)

    while i <= sqrt_n:
        if n % i == 0:
            divisors_sum += i
            if i != n // i:  # Add the corresponding divisor
                divisors_sum += n // i
        i += 1

    return divisors_sum == n


if __name__ == '__main__':
    n = 6
    # if prefect(n):
    #     print(n, "is a perfect number")
    # else:
    #     print(n, "is not a perfect number")

    if using_sqrt(n):
        print(n, "is a perfect square")

