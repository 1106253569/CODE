fo = open('hello.csv', 'r')
ls = []
for i in fo:
    line = line.replace('\n', ' ')
    ls.append(line.split(','))
print(ls)
fo.close()
