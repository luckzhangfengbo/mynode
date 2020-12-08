#!/usr/bin/env python
# coding=utf-8
import re
import requests

name = input('请输入关键字:')
begin = int(input('开始页数:'))
end =int(input('结束页数:'))

w = 0
for i in range(begin, end + 1):
    url = "https://tieba.baidu.com/f?kw="+name+"&ie=utf-8&pn="+str(i * 50)
    r = requests.get(url)
    r.encoding = 'utf-8'
    p = "http.*?\.jpg"
    pic_urls = re.findall(p, r.text);
    print(pic_urls)
    """下载"""
    for pic_url in pic_urls:
        try:
            pic = requests.get(pic_url)
            string = './data/tieba/images/' + str(w + 1) + '.jpg'
            with open(string, 'wb') as f:
                f.write(pic.content)
                print('成功下载第%s张图片: %s' % (str(w + 1), str(pic_url)))
            w+=1
        except Exception as e:
            print('下载第%s张图片时失败: %s' % (str(w + 1), str(pic_url)))
            print(e)
            continue
