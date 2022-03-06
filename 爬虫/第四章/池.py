from concurrent.futures import ThreadPoolExecutor
#ProcessPoolExecutor

name="main"

def fn(name):
    for i in range(100):
        print(name,i)
    
if name == "main":
    with ThreadPoolExecutor(16) as t:
        for i in range(100):
            t.submit(fn,name=f"线程{i}")
    print("123")