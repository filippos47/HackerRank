#!/bin/python3

import math
import os
import sys

# Complete the minimumPasses function below.
def minimumPasses(m, w, p, n):
    days = 0
    balance = 0
    minDays = sys.maxsize
    
    while balance < n:
        diff = math.ceil((p - balance) / (m * w))
        days = days + diff
        balance = balance + diff * m * w
        minDays = min(minDays, days + math.ceil((n - balance) / (m * w)))
        if balance >= n or days > minDays:
            break

        purchases = balance // p
        balance = balance - purchases * p
        total = purchases + m + w
        half = math.ceil(total / 2)

        if m > w:
            m = max(m, half)
            w = total - m
        else:
            w = max(w, half)
            m = total - w

    return min(minDays, days)


        

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    mwpn = input().split()

    m = int(mwpn[0])

    w = int(mwpn[1])

    p = int(mwpn[2])

    n = int(mwpn[3])

    result = minimumPasses(m, w, p, n)

    fptr.write(str(result) + '\n')

    fptr.close()
