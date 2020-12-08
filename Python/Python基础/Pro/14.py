#!/usr/bin/env python
# coding=utf-8
"""写文件"""

file = open("./input", "w", encoding = 'utf-8')
file_write('hello world')
file.write("\n")
file.writelines(['write','line'])
file.close()
