Fr = open("hello.txt", "r")  #默认文件存储在当前路径
Flist = Fr.readlines()
Line_length = []
apple_num = 0
for i in Flist:
    apple_num += i.count("apple")
    Length = len(i.split())
    Line_length.append(Length)
max_length = max(Line_length)
min_length = min(Line_length)
print("最长行长度为", max_length)
print("最短行长度为", min_length)
print("文献中apple出现次数", apple_num)
Fr.close()
