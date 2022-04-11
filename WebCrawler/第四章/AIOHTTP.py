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
        'https://www.vcg.com/creative/1011322625',
        'https://www.vcg.com/creative/1001890342',
        'https://www.vcg.com/creative/816934896'
    }
    
    tasks=[]
    for url in urls:
        d=asyncio.create_task(download(url))
        tasks.append(d)
        
    await asyncio.wait(tasks)
    
if __name__=='__main__':
    asyncio.run(main())
