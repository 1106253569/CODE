fo = open("2016.csv", 'r')
ls = []
for line in fo:
    line = line.replace("\n", "")
    ls.append(line.split(","))
    lns = ""
    for s in ls:
        lns += "{}\t".format(s)
    print(ls)
fo.close
