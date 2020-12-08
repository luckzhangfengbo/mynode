#!/usr/bin/env python
# coding=utf-8
fo = open("./input", "r+")
print("file name:", fo.name)

str = "\nwww.fangsong.run"
fo.seek(0, 3) #表示./input结尾
fo.write(str)

#读取文件所有内容
fo.seek(0)
for index in range(3):
    line = next(fo)
    print("文件行号 %d - %s" % (index, line))
fo.close()
