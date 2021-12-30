Str=input('请出入钱数币种，人民币币种用R表示，美元币种用D表示，钱数和币种之前不能有任何其他字符。例如54.5R表示54.5元:')
Huilv=6
Outpout=eval(Str[0:-1])*Huilv
if str[-1] is 'D':
    print('转化后的人民币为',Outpout)
elif str[-1] is 'R':
    print('转化后的美元为',Outpout)
else:
    print('输入格式不对')
