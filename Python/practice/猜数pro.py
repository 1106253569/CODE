import random

number = int(input("please enter number(0~100):"))
i = 1
autonumber = random.randint(0, 100)
min_temp, max_temp = 0, 100
while number != autonumber:
    if number > autonumber:
        print("too big")
        max_temp = number
    elif number < autonumber:
        print("too small")
        min_temp = number
    number = int(input("please enter number({}~{}):".format(min_temp, max_temp)))
    i += 1
print("恭喜,预测{}次，你猜中了！".format(i))
