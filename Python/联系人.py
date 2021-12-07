print("=" * 20)
print("欢迎使用通讯录:")
print("1.添加联系人")
print("2.查看通讯录")
print("3.删除联系人")
print("4.修改联系人")
print("5.查看联系人")
print("6.退出")
print("=" * 20)
dict_1 = []
while True:
    n = eval(input("请输入您的选项:"))
    dict_2 = {}
    if n == 1:
        name = input("请输入联系人的名字:")
        phone = input("请输入联系人的电话:")
        email = input("请输入联系人的邮箱:")
        address = input("请输入联系人的地址")
        dict_2 = {'姓名': name, '手机': phone, '邮箱': email, '地址': address}
        dict_1.append(dict_2)
        print(dict_2)
        print("保存成功")
        continue
    elif n == 2:
        if len(dict_1) == 0:
            print("通讯录为空")
        else:
            print(dict_1)
    elif n == 3:
        if len(dict_1) == 0:
            print("通讯录为空")
        else:
            name1 = input("请输入要删除的联系人姓名:")
            for a in dict_1:
                if a['姓名'] == name1:
                    dict_1.remove(a)
                    print("删除成功")
                    break
                else:
                    print("查无此人")
    elif n == 4:
        if len(dict_1) == 0:
            print("通讯录为空")
        else:
            name2 = input("请输入要修改的联系人姓名:")
            t = True
            if name2.strip():
                for b in dict_1:
                    if name2 in b['姓名']:
                        t = False
                        print("若无需修改,请按回车键")
                        new_name = input("请输入新的名字:")
                        new_phone = input("请输入新的手机号:")
                        new_email = input("请输入新的邮箱:")
                        new_address = input("请输入新的地址:")
                        if new_name.strip():
                            b['姓名'] = new_name
                        if phone.strip():
                            b['手机'] = new_phone
                        if email.strip():
                            b['邮箱'] = new_email
                        if address.strip():
                            b['地址'] = new_address
                            dict_2 = {
                                '姓名': new_name,
                                '手机': new_phone,
                                '邮箱': new_email,
                                '地址': new_address
                            }
                            dict_1.append(dict_2)
                            print(dict_2)
                            print("修改成功")
                            break
                        else:
                            print("无此人")
    elif n == 5:
        if len(dict_1) == 0:
            print("通讯录为空")
        else:
            name3 = input("请输入要查找的联系姓名:")
            for c in dict_1:
                if c['姓名'] == name3:
                    print('名字:%s' % name)
                    print('手机:%s' % phone)
                    print('邮箱:%s' % email)
                    print('地址:%s' % address)
                    break
                else:
                    print("无此人")
    elif n == 6:
        print("退出通讯录")
        break
    else:
        print("当前没有这个选项")
