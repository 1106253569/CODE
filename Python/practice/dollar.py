price = input("输入货币数值:")
if price[-1] in ['$']:
    C = eval(price[0:-1]) * 6
    print("美元对人民币价格{:.2f}¥".format(C))
elif price[-1] in ['¥']:
    F = eval(price[0:-1]) / 6
    print("人民币对美元价格{:.2f}$".format(F))
else:
    print("输入格式错误")
