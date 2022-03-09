import asyncio
import aiohttp

async def download(url):
    name=url.rsplit("/",1)[1]
    async with aiohttp.ClientSession() as session:
        async with session.get(url) as resp:
            with open(name,mode='wb') as f:
                f.write(await resp.content.read())
            
        
    
async def main():
    urls={
        'http://www.baidu.com',
        'http://www.bilibili.com',
        'http://www.163.com'
    }
    
    tasks=[]
    for url in urls:
        d=download(url)
        tasks.append(d)
        
    await asyncio.wait(tasks)
    
if __name__=='__main__':
    asyncio.run(main())
