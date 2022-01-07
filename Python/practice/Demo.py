def isOdd(x):
    if x%2==0:
        return False
    else:
        return True

def isNum(s):
    new=eval(s)
    word=str(new)
    if word==s:
        return True
    else:
        return False

def isPrime(number):
    try:
        if isinstance(number,int):
            for i in range(2,number):
                if number%i==0:
                    return False
            return True
        else:
            NameError
    except NameError:
        print("输入错误，请输入一个整数")

def main():
    a=float(input("please enter number:"))
    real=isPrime(a)
    if real:
        print("质数")
    else:
        print("非质数")


main()


