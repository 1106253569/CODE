import asyncio
import time

#async def func():
#   print("Hello")

#if __name__=='__main__':
#    g=func()
#    #print(g)
#    asyncio.run(g)


async def func1():
   print("Hello")
   #time.sleep(3)
   await asyncio.sleep(3)
   print("Hello")
   
async def func2():
   print("you too")
   #time.sleep(2)
   await asyncio.sleep(2)
   print("you too")
   
async def func3():
   print("bye")
   #time.sleep(4)
   await asyncio.sleep(4)
   print("bye")
   
'''   
if __name__=='__main__':
    f1=func1()
    f2=func2()
    f3=func3()
    tasks={
        f1,f2,f3
    }
    t1=time.time()
    asyncio.run(asyncio.wait(tasks))
    t2=time.time()
    print(t2-t1)
'''

async def main():
    #NO.1(不推荐)
    '''
    f1=func1()
    await f1
    '''
    #N0.2(推荐)
    tasks={
        asyncio.create_task(func1()) ,
        asyncio.create_task(func2()) ,
        asyncio.create_task(func3()) 
    }
    await asyncio.wait(tasks)
    
if __name__=='__main__':
    t1=time.time()
    asyncio.run(main())
    t2=time.time()
    print(t2-t1)