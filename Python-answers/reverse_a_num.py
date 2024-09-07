def rev(n):
    if n <= 0:
        return 0
    else:
        s = ""
        while n > 0:
            digit = int(n % 10)
            s += str(digit)
            n = n // 10
        return int(s)


print(rev(12345))

n = 12345
print(str(n)[::-1])