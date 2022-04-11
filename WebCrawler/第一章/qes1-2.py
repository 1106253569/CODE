import requests

query = input("输入你喜欢的明星:")

url = f"https://www.baidu.com/s?word={query}"

dic = {
    'User-Agent':
    'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/64.0.3282.140 Safari/537.36 Edge/18.17763'
}

resp = requests.get(url, headers=dic)

print(resp.text.encode('utf-8'))