#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    size = len(arr)
    p = 0
    n = 0
    z = 0
    for i in range(size):
        if arr[i] > 0:
            p += 1
        elif arr[i] < 0:
            n += 1
        else:
            z += 1
    
    print("{:.6f}".format(p / size))
    print("{:.6f}".format(n / size))
    print("{:.6f}".format(z / size))
    
if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
