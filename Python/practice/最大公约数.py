def compare(a,b):
    if a<b:
        return a
    elif a>b:
        return b
    else:
        return a

one,two=eval(input("please enter two numbers:"))
temp=compare(one,two)
max=0
i=1
while i<=temp:
    if one%i==0 and two%i==0:
        max=i
    i+=1
min=(one*two)/max
print("最大公约数={}\n最小公倍数={}".format(max,min))