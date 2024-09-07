import math

def sieve_build(n):
    if n<2:
        return []

    primes = [True] * (n+1)
    primes[0] = primes[1] = False
    for pr in range(2, int(math.sqrt(n))+1):
        if primes[pr]:
            for i in range(pr*pr, n+1, pr):
                primes[i] = False
    return primes

def is_prime(n, primes):
    return primes[n]

n = 100
prime = sieve_build(n)
num_to_check = 73
print("prime" if (is_prime(n, prime)==True) else "not prime")