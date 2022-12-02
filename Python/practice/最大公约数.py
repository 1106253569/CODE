def greatest_common_divisor(a, b):
    temp = min(a, b)
    m = 0
    i = 1
    while i <= temp:
        if a % i == 0 and b % i == 0:
            m = i
        i += 1
    return m


one = eval(input("please enter a :"))
two = eval(input("please enter b :"))
_max = greatest_common_divisor(one, two)
_min = (one * two) / _max
print("最大公约数={}\n最小公倍数={}".format(_max, _min))
