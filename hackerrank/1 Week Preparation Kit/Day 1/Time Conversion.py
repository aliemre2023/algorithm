#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    hour = s[0] + s[1]
    minute = s[3] + s[4]
    second =  s[6] + s[7]
    part = s[8] + s[9] 

    if(part == "AM"):
        if(hour == "12"):
            return (f"00:{minute}:{second}")
        else:
            return (f"{hour}:{minute}:{second}")
    else:
        if(hour == "12"):
            return (f"{hour}:{minute}:{second}")
        else:
            arranged_hour = int(hour) + 12
            return (f"{arranged_hour}:{minute}:{second}")

        



if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    fptr.write(result + '\n')

    fptr.close()
