import requests
import re

domain = 'https://dy.dytt8.net/index2.htm'
resp = requests.get(domain, verify=False)
resp.encoding = 'gb2312'
page_content = resp.text
resp.close()

obj1 = re.compile(r'<p>最新电影更新.*?<ul>(?P<want1>.*?</ul>)', re.S)
obj2 = re.compile(r"<a href='(?P<url1>.*?)'>.*?(?P<want2>《.*?)</a>", re.S)
obj3 = re.compile(r"<title>.*?(?P<name>《.*?》).*?</title>",re.S)
obj4 = re.compile(r'<br /><a target=.*?"(?P<net>.*?)">',re.S)

it1 = obj1.finditer(page_content)
for i in it1:
    ul = i.group('want1')


it2 = obj2.finditer(ul)
for i in it2:
    child_domain = 'https://dy.dytt8.net' + i.group('url1')
    resp1 = requests.get(child_domain , verify=False)
    resp1.encoding = 'gb2312'
    word = resp1.text
    resp1.close()
    it2 = obj4.finditer(word)
    for j in it2:
        print(j.group('net'))
    