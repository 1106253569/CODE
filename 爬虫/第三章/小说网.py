import requests
import re

session= requests.session()
data = {
    "loginName":"19854199286",
    "password":"asdf8296776"
}

#起点小说网
#url="https://ptlogin.yuewen.com/login"
#resp=session.get(url,data=data)
#resp.encoding="UTF-8"
#print(resp.text)

#7k小说网
url="https://h5.17k.com/ck/user/login"
session.post(url,data=data)
resp=session.get("https://user.17k.com/ck/author/shelf?platform=4&appKey=1351550300")
print(resp.json())


