import numpy as np
import datetime
from multiprocessing import cpu_count
from multiprocessing import Pool


def direct(A, B):
    start_t = datetime.datetime.now()
    print("正在直接进行矩阵乘法计算")
    C = np.matmul(A, B)
    end_t = datetime.datetime.now()
    elapsed_sec = (end_t - start_t).total_seconds()
    print("直接计算 共消耗: " + "{:.2f}".format(elapsed_sec) + " 秒")
    return C


if __name__ == '__main__':
    x = 2500
    y = 5000
    A = np.random.randint(0, 10, x * y)
    A = A.reshape(x, y)
    B = np.random.randint(0, 10, x * y)
    B = B.reshape(y, x)
    print("矩阵A,B生成完毕")
    num_cores = int(cpu_count())
    print("本地计算机有: " + str(cpu_count()) + " 核心")
    pool = Pool(num_cores)
    print("创建进程池完毕")

    start_t = datetime.datetime.now()
    print("正在进行并行计算")
    C_ = np.zeros(x * x)
    C_ = C_.reshape(x, x)
    steps = 10
    result = [
        pool.apply_async(np.matmul, [A[i:i + 10, :], B])
        for i in range(0, np.size(A, axis=0), 10)
    ]
    pool.close()
    pool.join()
    end_t = datetime.datetime.now()
    elapsed_sec = (end_t - start_t).total_seconds()
    print("多进程计算 共消耗: " + "{:.2f}".format(elapsed_sec) + " 秒")

    i = 0
    for params in result:
        C_[i * 10:i * 10 + 10, :] = params.get()
        i += 1
    pool = Pool(4)
    start_t=datetime.datetime.now()
    print("创建进程池进行文件存储")
    pool.apply_async(np.savetxt, [r'Document\A.txt', A, '%4d'])
    pool.apply_async(np.savetxt, [r'Document\B.txt', B, '%4d'])
    pool.apply_async(np.savetxt, [r'Document\C_.txt', C_, '%4d'])
    pool.close()
    pool.join()
    print("A,B,C_矩阵已存储完毕")
    end_t = datetime.datetime.now()
    elapsed_sec = (end_t - start_t).total_seconds()
    print("文件储存 共消耗: " + "{:.2f}".format(elapsed_sec) + " 秒")
    del C_

    C = direct(A, B)
    print(np.size(C))
    np.savetxt(r'Document\C.txt', C,fmt='%4d')
