account_0 = "admin"
pwd_0 = "123"
i = 3
while i != 0:
    account = input("输入账号：")
    pwd = input("输入密码：")
    i = i - 1
    if account == account_0 and pwd == pwd_0:
        print("密码正确")
        break
    else:
        if account != account_0:
            print("账号错误！")
            print("还有{}次机会".format(i))
        else:
            print("密码错误！")
            print("还有{}次机会".format(i))
if i == 0:
    print("输入错误次数太多，请稍后再试")
