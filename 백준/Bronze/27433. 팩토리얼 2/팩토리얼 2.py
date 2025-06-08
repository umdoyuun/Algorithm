def facto(n):
    if n >= 2:
        hap = n * facto(n-1)
        return hap
    elif n == 0 or n == 1:
        return 1

num = int(input())
print(facto(num))
