import requests
import re

URL = 'https://movie.douban.com/chart'

header = {
    'User-Agent':
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.80 Safari/537.36"
}

resp=requests.get(url=URL,headers= header)
page_content = resp.text
resp.close()

obj = re.compile(r"</table>.*?<div id=.*?title=(?P<name>.*?)>"
                 r"<p class=.*?>(?P<year>.*?)(.*?)"
                 r"<div.*?<span class=.*?>(?P<score>.*?)</",re.S)

result=obj.finditer(page_content)
for it in result:
    print(it.group('name'))
    print(it.group('year'))
    print(it.group('score'))


    