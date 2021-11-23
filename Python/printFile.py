fname=input("please enter you want to opening: ")
fo=open(fname,'r')
for line in fo:
    print(line)
fo.close()