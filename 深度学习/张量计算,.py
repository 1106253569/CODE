import torch
import numpy as np
from torch.functional import Tensor
# 判断当前环境GPU是否可用, 然后将tensor导入GPU内运行
if torch.cuda.is_available():
    tensor = Tensor.to('cuda')
tensor = torch.ones(4, 4)
tensor[:, 1] = 0  # 将第1列(从0开始)的数据全部赋值为0
print(tensor)
t1 = torch.cat([tensor, tensor, tensor], dim=1)
print(t1)
# 逐个元素相乘结果
print(f"tensor.mul(tensor): \n {tensor.mul(tensor)} \n")
# 等价写法:
print(f"tensor * tensor: \n {tensor * tensor}\n")
print(f"tensor + tensor: \n {tensor + tensor}\n")
#张量与张量的矩阵乘法
print(f"tensor.matmul(tensor.T): \n {tensor.matmul(tensor.T)} \n")
# 等价写法:
print(f"tensor @ tensor.T: \n {tensor @ tensor.T}\n")
#逐项赋值运算
print(tensor, "\n")
tensor.add_(5)
print(tensor)
# 自动赋值运算虽然可以节省内存, 但在求导时会因为丢失了中间过程而导致一些问题
# 所以我们并不鼓励使用它
