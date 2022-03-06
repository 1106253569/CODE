import requests
from lxml import etree

session= requests.session()
data = {
    "email":"1106253569@qq.com",
    "password":"asdf8296776"
}

header={
    'User_Agent':
    'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.80 Safari/537.36'
}

url="http://www.glidedsky.com/login"
session.post(url,data=data,headers=header)
resp=session.get("http://www.glidedsky.com/level/web/crawler-basic-1")
print(resp.text)

'''
page=resp.text
resp.close()
tree=etree.HTML(page)
html=tree.xpath("//div[@class='col-md-1']/text()")
sum_int = 0
for item in html:
    sum_int +=int(item.strip())
    print(sum_int)
'''    