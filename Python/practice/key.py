import random

key_list = [
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
    'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 1, 2, 3, 4, 5, 6, 7,
    8, 9
]
j = 0
ls = []
i = 0
while i < 8:
    ls.append(key_list[random.randint(0, 34)])
    i = i + 1
print(ls)