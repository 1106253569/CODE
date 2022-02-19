import re

#列表返回
lst = re.findall(r'\d+', '我的电话是10086,我女友的电话是10010')
print(lst)

#多次查询，返回迭代器
it = re.finditer(r'\d+', '我的电话是10086,我女友的电话是10010')
for i in it:
    print(i.group())

#找到第一个就结束，返回迭代器
s = re.search(r'\d+', '我的电话是10086,我女友的电话是10010')
print(s.group())