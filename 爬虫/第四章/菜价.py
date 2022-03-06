import requests
from concurrent.futures import ProcessPoolExecutor
from lxml import etree

data = {
    "Date": "Sat, 05 Mar 2022 13:56:39 GMT",
    "limit": "20",
    "current": "2",
    "pubDateStartTime": " ",
    "pubDateEndTime": " ",
    "prodPcatid": " ",
    "prodCatid": " ",
    "prodName": " "
}

header = {
    'User-Agent':
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.80 Safari/537.36"
}

URL = "http://www.xinfadi.com.cn/priceDetail.html"


def download_one_page(url):
    resp = requests.post(url)
    html = etree.HTML(resp.text)
    table = html.xpath(
        "/html/body/div[2]/div/div/div/div[4]/div[1]/div/table")[0]
    trs = table.xpath("./tr")
    print(len(trs))


resp = requests.post(URL,headers=header,data=data)
print(resp.text)