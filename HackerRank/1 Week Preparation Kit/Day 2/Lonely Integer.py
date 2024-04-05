#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'lonelyinteger' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY a as parameter.
#

def lonelyinteger(a):
    my_dict = dict()
    
    for i in range(len(a)):
        if a[i] in my_dict:
            my_dict[a[i]] += 1
        else:
            my_dict[a[i]] = 1
    for key, value in my_dict.items():
        if(value == 1):
            return key
        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    a = list(map(int, input().rstrip().split()))

    result = lonelyinteger(a)

    fptr.write(str(result) + '\n')

    fptr.close()
