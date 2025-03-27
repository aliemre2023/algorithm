#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'caesarCipher' function below.
#
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING s
#  2. INTEGER k
#

def caesarCipher(s, k):
    english_letters = [chr(letter) for letter in range(97, 123)]
    uppercase_letters = [chr(letter) for letter in range(65, 91)]
    shifted_str = ""
    for i in s:
        if(i in english_letters):
            index = (english_letters.index(i) + k) % 26
            shifted_str += english_letters[index]
        elif(i in uppercase_letters):
            index = (uppercase_letters.index(i) + k) % 26
            shifted_str += uppercase_letters[index]               
        else:
            shifted_str += i
    return shifted_str
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    s = input()

    k = int(input().strip())

    result = caesarCipher(s, k)

    fptr.write(result + '\n')

    fptr.close()
