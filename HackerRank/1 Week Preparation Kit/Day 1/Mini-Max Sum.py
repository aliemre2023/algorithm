#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'miniMaxSum' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def miniMaxSum(arr):
    min_num = arr[0]
    max_num = arr[0]
    total_sum = arr[0]

    for i in range(1,5):
        if(arr[i] < min_num):
            min_num = arr[i]
        elif(arr[i] > max_num):
            max_num = arr[i]
        total_sum += arr[i]

    print("{} {}".format(total_sum - max_num, total_sum - min_num))


if __name__ == '__main__':

    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
