#!/usr/bin/env python
# coding=utf-8
"""使用requests发送请求和携带参数"""
#导入模块
import requests

url = "https://www.baidu.com"
#发送get请求
response = requests.get("http://www.baidu.com")
response.encoding = 'utf-8'
print(response.text)

#发送get请求,并携带参数
r = requests.get(url, params = {'key1' : 'value1', 'key2' : 'value2'})
r.encoding = 'utf-8'
print(r.text)

#发送post请求,并传输参数
r = requests.post(url, data = {'key' : 'value'})
r.encoding = 'utf-8'
print(r.text)
