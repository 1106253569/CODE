def fun(a,b,c):
    if (a+b>c) and (b+c>a) and (a+c>b):
        if a==b==c:
            return '全等三角形'
        return '是三角形'
    else:
        return '不是三角形'
    
a,b,c=map(int,input().split(','))
str_result=fun(a,b,c)
print(str_result)