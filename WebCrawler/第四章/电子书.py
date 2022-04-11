import asyncio
import aiohttp
import requests
import aiofiles
import json


async def aiodownload(cid, b_id, title):
    data = {"book_id": b_id, "cid": f"{b_id}|{cid}", "need_bookinfo": 1}
    data = json.dumps(data)
    url = f"https://dushu.baidu.com/api/pc/getChapterContent?data={data}"
    async with aiohttp.ClientSession() as session:
        async with session.get(url) as resp:
            dic = await resp.json()
            async with aiofiles.open(f'{title}.txt',
                                     mode='w',
                                     encoding='utf-8') as f:
                await f.write(dic['data']['novel']['content'])


async def getCatalog(url, b_id):
    header = {
        'User-Agent':
        "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.80 Safari/537.36"
    }
    resp = requests.get(url=url, headers=header)
    dic = resp.json()
    tasks = []
    for a in dic['data']['novel']['items']:
        title = a['title']
        cid = a['cid']
        tasks.append(asyncio.create_task(aiodownload(cid, b_id, title)))
    await asyncio.wait(tasks)


if __name__ == "__main__":
    b_id = '4355373894'
    url = 'https://dushu.baidu.com/api/pc/getCatalog?data={"book_id":"' + b_id + '"}'
    asyncio.run(getCatalog(url, b_id))