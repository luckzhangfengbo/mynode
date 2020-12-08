#!/usr/bin/env python
# coding=utf-8
from selenium import webdriver#导入库
import os
import json
"""
browser = webdriver.Chrome()#声明浏览器
url = 'https:www.jisuanke.com'
url2 = 'https://passport.jisuanke.com/?n=http://www.jisuanke.com#/'
browser.get(url)#打开浏览器预设网址
browser.get(url2)
print(browser.page_source)#打印网页源代码
#browser.close()#关闭浏览器
"""

#从selenium里面导入webdriver
from selenium import webdriver

#指定chrom的驱动
#执行到这里的时候Selenium会到指定的路径将chrome driver程序运行起来
driver = webdriver.Chrome()
#driver = webdriver.Firefox()#这里是火狐的浏览器运行方法

#get 方法 打开指定网址
url2 = 'https://passport.jisuanke.com/?n=http://www.jisuanke.com#/'
#选择网页元素
driver.get(url2)
element_keyword = driver.find_element_by_id('')
#输入字符
element_keyword.send_keys('13045426101')

#找到搜索按钮
element_search_button = driver.find_element_by_id('su')
