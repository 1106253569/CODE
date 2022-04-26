def fun(*args):
    temp=args[0];
    sum=0;
    for i in args:
        sum=sum+i
        if i>temp:
            temp=i
    return sum,temp

sum,max=fun(2,3,4)
print(sum,max)