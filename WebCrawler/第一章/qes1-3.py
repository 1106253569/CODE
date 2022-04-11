import requests

url = "https://fanyi.baidu.com/sug"
s = input("please enter you want to translated word :")
dat = {"kw": s}

resp = requests.post(url, data=dat)
print(resp.json())