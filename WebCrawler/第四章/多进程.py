from multiprocessing import Process

name='main'

def func():
    for i in range(1000):
        print("func",i)
        
if name == "main":
    t =Process(target=func)
    t.start()    
    for i in range(1000):
        print("main",i)