import asyncio
import time

async def download(url):
    print('开始下载')
    await asyncio.sleep(2)
    print('Download over!')
    
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
