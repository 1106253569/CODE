import re

#预加载
obj = re.compile(r'\d+')

#列表返回
lst = obj.findall('我的电话是10086,我女友的电话是10010')
print(lst)

#多次查询，返回迭代器
it = obj.finditer('我的电话是10086,我女友的电话是10010')
for i in it:
    print(i.group())

#找到第一个就结束，返回迭代器
s = obj.search('我的电话是10086,我女友的电话是10010')
print(s.group())