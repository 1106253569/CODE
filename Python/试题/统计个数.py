Str = input('请输入一行字符:')
Num_English = 0
Num_space = 0
Num_num = 0
Num_other = 0
for i in Str:
    if 'a' <= i <= 'z' or 'A' <= i <= 'Z':
        Num_English += 1
    elif '0' <= i <= '9':
        Num_num += 1
    elif i == ' ':
        Num_space += 1
    else:
        Num_other += 1
print(Num_English)
print(Num_num)
print(Num_space)
print(Num_other)
