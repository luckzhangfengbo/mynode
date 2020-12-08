#!/usr/bin/env python
# coding=utf-8
import random

#0~1之间的随机数

print(random.random())

#制定范围之内的随机数
print(random.randint(10, 100))

#获取列表中的一个随机数
list1 = [1, 2, 3, 5, 7, 11]
print(random.choice(list1))

