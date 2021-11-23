fname=input("please enter name: ")
fo=open(fname,"w+")
ls=['sun\n','moon\n','star']
fo.writelines(ls)
fo.seek(0)
for line in fo:
    print(line,end='')
fo.close()