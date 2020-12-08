#!/usr/bin/env python
# coding=utf-8
fo = open("./input", "r+")
print("文件名:", fo.name)

str = '\nwww.haizei.com'

fo.seek(0, 2)
line = fo.write(str)

#读取文件内容
fo.seek(0)
for index in range(3):
    line = next(fo)
    print("文件行号 %d_%s" % (index, line))
fo.close()
