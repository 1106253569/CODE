textFile = open("D:\python\File.txt", "rt")
print(textFile.readlines())
textFile.close()
binFlie = open("D:\python\File.txt", "rb")
print(binFlie.readlines())
binFlie.close()
