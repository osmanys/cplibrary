# Project Euler #3: Largest prime factor

t = int(input())
while t > 0:
    n = int(input())
    i = n // 2
    while i * i >= n:
        if n % i == 0:
            n = i
            i = n // 2 + 1
        i -= 1
    print(n)
    t -= 1
