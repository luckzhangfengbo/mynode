#!/usr/bin/env python
# coding=utf-8

def gcd(a, b):
    if b == 0:
        return a
    else :
        return gcd(b, a % b)

a = int(input("ａ的值是多少"))
b = int(input("ｂ的值是多少"))
print(gcd(a, b))
