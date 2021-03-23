# -*- coding: utf-8 -*-
# @Author: Ram Krishna Sharma
# @Date:   2021-02-03 22:37:54
# @Last Modified by:   ramkrishna
# @Last Modified time: 2021-02-03 23:57:01

import multiprocessing
num_cores = multiprocessing.cpu_count()
inputs = ["ram", "Krishna", "Sharma"]

# from multiprocessing import Pool

# def f(x):
#     return x*x

# if __name__ == '__main__':
#     p = Pool(5)
#     print(p.map(f, [1, 2, 3]))

from multiprocessing import Pool, TimeoutError
import time
import os

def f(x):
    return x*x

if __name__ == '__main__':
    pool = Pool(processes=4)              # start 4 worker processes

    # print "[0, 1, 4,..., 81]"
    print pool.map(f, range(10))