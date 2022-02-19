import requests

url = "https://movie.douban.com/j/search_subjects"
param = {
    "type": "movie",
    "tag": "经典",
    "sort": "time",
    "page_limit": 20,
    "page_start": 0
}

header = {
    'User-Agent':
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.80 Safari/537.36"
}

resp = requests.get(url=url, params=param, headers=header)

print(resp.json())
