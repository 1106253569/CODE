from email import header
import requests

url = "https://www.pearvideo.com/video_1753063"
contId = url.split("_")[1]

headers = {
    "User-Agent":
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Safari/537.36",
    #处理防盗链
    "Referer": url
}

proxies={
    "https": "https://218.60.8.83.3129"
}

videoStatusUrl = f"https://www.pearvideo.com/videoStatus.jsp?contId={contId}&mrd=0.35728453213028244"
resp = requests.get(videoStatusUrl, headers=headers)
dic = resp.json()
resp.close()
srcUrl = dic["videoInfo"]["videos"]["srcUrl"]
systemTime = dic["systemTime"]
srcUrl=srcUrl.replace(systemTime,f"cont-{contId}")
print(srcUrl)

with open("a.mp4" , mode = "wb") as f:
    f.write(requests.get(srcUrl).content)

