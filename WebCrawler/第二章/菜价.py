import requests 
from bs4 import BeautifulSoup

URL = "http://www.xinfadi.com.cn/priceDetail.html"
resp = requests.post(URL)

#把页面源代码交给bs4
page = BeautifulSoup(resp.text , "html.parser")
resp.close()
#从bs4查找对象
table = page.find("tbody",attrs= {"class":"ul"})
print(table)

