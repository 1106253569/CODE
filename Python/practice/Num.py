import math


def getNum():
    nums = []
    iNum = input("please enter number: ")
    while iNum != "":
        nums.append(eval(iNum))
        iNum = input("please enter number: ")
    return nums


def mean(numbers):
    s = 0.0
    for num in numbers:
        s = s + sum
