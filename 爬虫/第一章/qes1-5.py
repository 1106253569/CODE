import requests

URL = "https://movie.douban.com/j/search_subjects?type=movie&tag=爱情&sort=recommend&page_limit=20&page_start=0"



header = {
    'User_Agent':
    'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.80 Safari/537.36'
}

resp = requests.get(url=URL,  headers=header)
print(resp.text)
resp.close()