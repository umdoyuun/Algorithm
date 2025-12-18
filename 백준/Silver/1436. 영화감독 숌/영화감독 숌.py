n = int(input())
a = 0

while(True):
    a += 1
    if '666' in str(a):
        n -= 1
        if n == 0:
            break
print(a)
