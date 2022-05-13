def fun(n):
    y=1
    if n>=1 and n<=3:
        y=1
    if n>=4:
        y=3*fun(n-1)+1
    return y
    
n=int(input())
for i in range(n):
    print(fun(i+1),end=" ")