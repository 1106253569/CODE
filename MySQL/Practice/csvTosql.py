import numpy as np
import pandas as pd

data = pd.read_csv(r'D:\CODE\MySQL\Practice\sql.csv')
for c in data:
    print(c, end=', ')
print('\n')
for i in np.array(data):
    print('(', end=' ')
    for j in i:
        print('\"' + str(j) + '\"', end=', ')
    print('),')
