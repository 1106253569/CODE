def prime(n):
    i = 2
    while i < n:
        if n % i == 0:
            return 0
        i = i + 1
    return 1


n = int(input())
print(n, end="=")
a = []
j = 2
while j <= n:
    if prime(j):
        if n % j == 0:
            a.append(j)
            n = n / j
            j = 2
            continue
    j = j + 1

i=0
while i<len(a):
    if i==len(a)-1:
        print(a[i],end='')
    else:
        print(a[i],end='x')
    i+=1
