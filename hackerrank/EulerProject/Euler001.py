# Project Euler #1: Multiples of 3 and 5

t = int(input())
while t > 0:
    n = int(input()) - 1
    n3 = n // 3
    n5 = n // 5
    n15 = n // 15
    print((3 * n3 * (n3 + 1) + 5 * n5 * (n5 + 1) - 15 * n15 * (n15 + 1)) // 2)
    t -= 1
