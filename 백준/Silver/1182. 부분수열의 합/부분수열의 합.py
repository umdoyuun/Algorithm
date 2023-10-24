count = 0
def powerset(x, hap):
    global count
    hap = hap + a[x]
    if hap == S:
        count += 1
    if x == n-1:
        return
    powerset(x+1, hap)
    powerset(x+1, hap - a[x])

n, S = map(int,input().split())
a = list(map(int, input().split()))

powerset(0,0)
print(count)
