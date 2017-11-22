# Project Euler #2: Even Fibonacci numbers

t = int(input())
while t > 0:
    n = int(input())
    a0, a1 = 2, 8
    s = 2
    while a1 <= n:
        s += a1
        temp = a1
        a1 = 4 * a1 + a0
        a0 = temp
    print(s)
    t -= 1
