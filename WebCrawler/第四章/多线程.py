from threading import Thread


name="main"

def func(name):
    for i in range(1000):
        print(name,i)

if name == "main":
    t1 =Thread(target=func,args=("线程1",))
    t1.start()  
    t2 =Thread(target=func,args=("线程2",))
    t2.start() 
    for i in range(1000):
        print("main",i)

'''
class MyThread(Thread):
    def run(self):
        for i in range(1000):
            print("child",i)

if name == "main":
    t=MyThread()
    #t.run()方法调用，为单线程
    t.start()
    for i in range(1000):
        print("main",i)
'''