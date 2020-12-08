#!/usr/bin/env python
# coding=utf-8
from selenium import webdriver#导入库
browser = webdriver.Chrome()#声明浏览器
url = 'https:www.jisuanke.com'
url2 = 'https://passport.jisuanke.com/?n=http://www.jisuanke.com#/'
browser.get(url)#打开浏览器预设网址
browser.get(url2)
print(browser.page_source)#打印网页源代码
#browser.close()#关闭浏览器
