#!/usr/bin/env python
# coding=utf-8
import math

'''
def circle(r):
    result = math.pi * r * r
    return result
r = float(input('请输入圆的半径'))

print('半径为%lf' % circle(r))
'''

r = float(input("请输入圆的半径："))
result = lambda r : math.pi * r * r
print('半径为%lf' % result(r))

