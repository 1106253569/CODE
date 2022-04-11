#第一题
R = int(input("圆柱形底边半径为:"))
H = int(input("圆柱形高为:"))
V = 3.14 * (R**2) * H  #计算体积
print(R, H, "体积为:", V)

#第二题
slogan = input("请输入加油对象:")
print("加油!" + slogan)

#第三题
a = int(input("a="))
b = int(input("b="))
#求出表达式  s1=2a+3b 的值和表达式 s2=2a3+3b2的值
s1 = 2 * a + 3 * b
s2 = 2 * (a**3) + 3 * (b**2)
print("s1=", s1)
print("s2=", s2)