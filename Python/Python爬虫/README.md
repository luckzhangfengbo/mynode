## `urllib` 模块

有如下四个模块

- [`urllib.request`](https://docs.python.org/zh-cn/3/library/urllib.request.html#module-urllib.request) 打开和读取 URL

- [`urllib.error`](https://docs.python.org/zh-cn/3/library/urllib.error.html#module-urllib.error) 包含 [`urllib.request`](https://docs.python.org/zh-cn/3/library/urllib.request.html#module-urllib.request) 抛出的异常

- [`urllib.parse`](https://docs.python.org/zh-cn/3/library/urllib.parse.html#module-urllib.parse) 用于解析 URL

- [`urllib.robotparser`](https://docs.python.org/zh-cn/3/library/urllib.robotparser.html#module-urllib.robotparser) 用于解析 `robots.txt` 文件

  

```python
#!/usr/bin/env python
# coding=utf-8
"""urllib的使用"""
import urllib.request

#向制定一个URL发送请求，获取回应
response = urllib.request.urlopen("http://www.fangsong.run")
#获取响应内容
content = response.read().decode('utf-8')
fo = open('./fangsong.html', 'w', encoding = 'utf-8')
print(content, file = fo)
fo.close()


#响应头信息
print(response.headers)
#响应码
print(response.status)
```

```python
Connection: close
Content-Length: 48327
Server: GitHub.com
Content-Type: text/html; charset=utf-8
Strict-Transport-Security: max-age=31556952
Last-Modified: Fri, 10 Jul 2020 01:36:45 GMT
ETag: "5f07c62d-bcc7"
Access-Control-Allow-Origin: *
Expires: Thu, 16 Jul 2020 11:33:23 GMT
Cache-Control: max-age=600
X-Proxy-Cache: MISS
X-GitHub-Request-Id: 4A5E:2A37:12F5B9:1755F1:5F1038AA
Accept-Ranges: bytes
Date: Thu, 16 Jul 2020 11:32:11 GMT
Via: 1.1 varnish
Age: 528
X-Served-By: cache-hkg17935-HKG
X-Cache: HIT
X-Cache-Hits: 1
X-Timer: S1594899132.629190,VS0,VE1
Vary: Accept-Encoding
X-Fastly-Request-ID: ea09594f3e3d38c033755ede864ce735303f9638


200
```

##　安装虚拟环境

https://www.cnblogs.com/chjxbt/p/10517952.html

**一、问题：为什么要搭建虚拟环境**

在开发过程中，当需要使用python的某些工具包/框架时需要联网安装。比如联网安装Flask框架flask-0.10.1版本

```
sudo pip install flask==0.10.1
```

使用如上命令，会将flask-0.10.1安装到/usr/local/lib/python3.5/dist-packages路径下

如果在一台电脑上，想开发多个不同的项目， 需要用到同一个包的不同版本， 如果使用上面的命令， 在同一个目录下安装或者更新， 新版本会覆盖以前的版本， 其它的项目就无法运行了。

**二、解决方案：虚拟环境**

虚拟环境可以搭建独立的Python运行环境，使得单个项目的运行环境与其他项目互不影响。

**三、如何搭建虚拟环境（Linux系统）**

步骤：

1、安装虚拟环境

```
sudo apt-get install virtualenv
sudo apt-get install virtualenvwrapper
```

 安装完虚拟环境后，如果提示找不到`mkvirtualenv`命令，须配置环境变量：

```python
# 1、在~（家目录）下创建目录用来存放虚拟环境
mkdir ~/.virtualenvs

# 2、打开~/.bashrc文件，并添加如下：
export WORKON_HOME=$HOME/.myvirtualenvs
source /usr/share/virtualenvwrapper/virtualenvwrapper.sh

# 3、运行
source ~/.bashrc
```

**四、如何使用虚拟环境**

![undefined](http://ww1.sinaimg.cn/large/006Uqzbtly1ggt3lfllh5j30k00bb3zt.jpg)

*创建环境*

```python
cd ~/.myvirtualenvs
mkvirtualenv -p /usr/bin/python3 Python3
```

上面命令第二个`python3`可以自定义

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggt39wmrl0j30q90a8wno.jpg)

*进入与退出环境*

```bash
fangsong@fangsong-FX503VD:~/.myvirtualenvs$ workon Python3
(Python3) fangsong@fangsong-FX503VD:~/.myvirtualenvs$ deactivate
```

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggt3iojlt9j30i501x0tl.jpg)

*安装requests*

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggt3zxs982j30qf0fads6.jpg)

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggv3dgrlfrj30q00ek13j.jpg)



### requests模块





```python
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
```

一个简单的爬虫

```python
#!/usr/bin/env python
# coding=utf-8

import requests
src = "https://imgsa.baidu.com/forum/wh%3D144%2C90/sign=c1e4b2dbe2cd7b89e93932823b106e9e/f66fc65c10385343ee1135309713b07ecb80888e.jpg"
response = requests.get(src)
with open('./data/tieba/images/1.jpg', "wb") as file:
    file.write(response.content)
```

思路

>1. 向起始URL发送请求
>2. 从(1) 的相应中提取每个贴吧标题和对应的URL发送请求，获取响应(正则表达式)
>3. 在(2)的响应中,提取每张图片的URL发送请求
>4. (4)保存图片
>5. 从(1)提取下一页中的URL



## 爬虫

第一版：

```python
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
```

第二版：

1. 提取一级标题:

`<a rel="noreferrer" href="/p/6793476420" title="像我科一样奋斗，随心记录" target="_blank" class="j_th_tit " clicked="true">像我科一样奋斗，随心记录</a>`

`<a rel="noreferrer" href="/p/6661814756" title="渐渐的你笑了，慢慢的我哭了" target="_blank" class="j_th_tit ">渐渐的你笑了，慢慢的我哭了</a>`

所以可以写出正则表达式为：

```python
pattern = re.compile(r'<a rel="noreferrer" href="(/p/\d+?)" title=".+?" target="_blank" class="j_th_tit .*?">(.+?)</a>')
url_title = pattern.findall(content)
```

2. 提取图片:

``<img class="BDE_Image" src="http://tiebapic.baidu.com/forum/w%3D580/sign=8181ff92e036afc30e0c3f6d8318eb85/685d972bd40735fa6403fceb89510fb30e2408b2.jpg" size="174406" changedsize="true" width="560" height="373" style="cursor: url(&quot;//tb2.bdstatic.com/tb/static-pb/img/cur_zin.cur&quot;), pointer;">``

所以可以写出正则表达式为:

```python
content = self.parse_text(url = url)
urls = re.findall(r'<img class="BDE_Image".*?src="(.*?)".*?', content)
```

3. 下一页

`<a href="//tieba.baidu.com/f?kw=%E7%A7%91%E6%AF%94&amp;ie=utf-8&amp;pn=50" class="next pagination-item ">下一页&gt;</a>`

所以可以写出正则表达式为:

```python
next_url = re.findall(r'<a href="(.*?)".*?>下一页&gt;</a>', content)
```

4. 反爬伪装

`Linux:`

```python
self.header = {"User-Agent":"Mozilla/5.0 (X11;\
                Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36"}
```

`Mac`

```python
self.header = {"User-Agent" : "Mozilla/5.0 (Macintosh;\
                       Intel Mac OS X 10_9_2) AppleWebKit/537.75.14 (KHTML, like Gecko) Version/7.0.3 Safari/537.75.14"}
```

完整代码:

```python
#!/usr/bin/env python
# coding=utf-8
"""爬百度贴吧"""

import requests
import re

class TiebaSpider:
    """贴吧爬虫"""
    def __init__(self):
        """初始化参数"""
        self.kw = input('关键词：')
        self.base_url = 'https://tieba.baidu.com/f'
        self.page_num = 1
        """
        self.header = {"User-Agent" : "Mozilla/5.0 (Macintosh;\
                       Intel Mac OS X 10_9_2) AppleWebKit/537.75.14 (KHTML, like Gecko) Version/7.0.3 Safari/537.75.14"}
        """
        self.header = {"User-Agent":"Mozilla/5.0 (X11;\
                Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36"}

        self.title = ''

    def parse_text(self, url, params = None):
        """发送请求，获取响应内容"""
        req = requests.get(url, headers = self.header, params = params)
        return req.text#响应对象的文本信息

    def parse_byte(self, url, params = None):
        req = requests.get(url, headers = self.header, params = params)
        return req.content#响应对象的content

    def page(self, content):
        """解析每一页"""
        print("第{}页爬取中...".format(self.page_num))
        self.page_num += 1
        pattern = re.compile(r'<a rel="noreferrer" href="(/p/\d+?)" title=".+?" target="_blank" class="j_th_tit .*?">(.+?)</a>')
        url_title = pattern.findall(content)
        for url, title in url_title:
            self.title = title
            self.detail('https://tieba.baidu.com' + url)
            #保存标题
            self.save_title()
            #判断下一页
            next_url = re.findall(r'<a href="(.*?)".*?>下一页&gt;</a>', content)
        if next_url:#下一页存在
            next_url = 'https:' + next_url[0]
            content = self.parse_text(url = next_url)
            self.page(content)
        else:
            print('爬虫结束...共爬取{}页！'.format(self.page_num))

    def detail(self, url):
        """每一个帖子的详情"""
        content = self.parse_text(url = url)
        urls = re.findall(r'<img class="BDE_Image".*?src="(.*?)".*?', content)
        for url in urls:
            self.save_img(url = url)

    def save_title(self):
        """保存帖子的标题"""
        with open('./data/tieba/tieba_{}.txt'.format(self.kw), 'a', encoding = 'utf-8') as file:
            file.write(self.title)
            file.write('\n')

    def save_img(self, url):
        """保存图片"""
        content = self.parse_byte(url = url)
        image_path = './data/tieba/images/{}.jpg'.format(self.title)
        try:
            with open(image_path, 'wb') as file:
                file.write(content)
        except:
            pass

    def start(self):
        """开始爬虫"""
        print('爬虫开始...')
        content = self.parse_text(url = self.base_url, params = {'kw' : self.kw, 'ie' : 'utf-8', 'fr' : 'search'})
        self.page(content)

if __name__ == '__main__':
    spider = TiebaSpider()
    spider.start()
```

**框架**

```python
#!/usr/bin/env python
# coding=utf-8
"""
爬百度贴吧
"""

import requests
import re 

class TiebaSpider:
    """贴吧爬虫"""
    def __init__(self):
        """初始化参数"""
        self.kw = imput('请输入关键词:')
        self.base_url = 'https://tieba.baidu.com/f'
        self.page_num = 1
        self.header = {"User-Agent":"Mozilla/5.0 (X11;\
                Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36"}
        self.title = ''

    def parse_text(self, url, params = None):
        """发送请求，获取相应内容"""

        return #响应对象的文本信息
    
    def parse_byte(self, url, params=None):

        return #响应对象的content

    def page(self, content):
        """解析每一页"""
        print("第()页爬取中...".format(self.page_num))


        #判断下一页
        if #下一页存在:
            self.parse_text()
        else:
            print('爬虫结束...爬取{}页！'.format(self.page_num))

    def save_title(self):
        """保存帖子的标题"""

    def save_img(self, url):
        """保存图片"""


    def start(self):
        """开始爬虫"""
        print('爬虫开始...')
        content = self.parse_text(url = self.base_url, params = {'kw' : self.kw. 'ie' : 'utf-8', 'fr' : 'search'})
        self.page(content)



if __name__=='__main__':
    spider = TiebaSpider()
    spider.start()
```

## 爬虫框架

```python
scrapy startproject chinanews_crawl
```

```python
scrapy genspider chinanews chinanews.com
```

```python
scrapy crawl chinanews
```

```python
# cat items.py 
# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

from scrapy.item import Item, Field

class ChinanewsCrawlItem(Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    title = Field()
    link = Field()
    desc = Field()
    pub_date = Field()
```

```python
#cat chinanews.py 
#-----------------------
from scrapy import Spider
from bs4 import BeautifulSoup
from ..items import ChinanewsCrawlItem

class ChinanewsSpider(Spider):
    name = 'chinanews'
    allowed_domains = ['chinanews.com']
    start_urls = ('http://www.chinanews.com/rss/scroll-news.xml',)

    def parse(self, response):
        rss = BeautifulSoup(response.body, "html.parser")
        for item in rss.find_all('item'):
            feed_item = ChinanewsCrawlItem()
            feed_item['title'] = item.title.text
            feed_item['link'] = item.link.text
            feed_item['desc'] = item.description.text
            feed_item['pub_date'] = item.pubDate
            yield feed_item
```



### 创建项目

在开始爬取之前，您必须创建一个新的`Scrapy`项目。 进入您打算存储代码的目录中，运行下列命令:

```
scrapy startproject tutorial
```

该命令将会创建包含下列内容的 `tutorial` 目录:

```
tutorial/
    scrapy.cfg
    tutorial/
        __init__.py
        items.py
        pipelines.py
        settings.py
        spiders/
            __init__.py
            ...
```

这些文件分别是:

`scrapy.cfg`: 项目的配置文件

`tutorial/`: 该项目的python模块。之后您将在此加入代码。

`tutorial/items.py`: 项目中的item文件.

`tutorial/pipelines.py`: 项目中的pipelines文件.

`tutorial/settings.py`: 项目的设置文件.

`tutorial/spiders/`: 放置spider代码的目录.

### 定义Item

首先根据需要从dmoz.org获取到的数据对item进行建模。 我们需要从dmoz中获取名字，url，以及网站的描述。 对此，在item中定义相应的字段。编辑 `tutorial` 目录中的 `items.py` 文件:

```
import scrapy

class DmozItem(scrapy.Item):
    title = scrapy.Field()
    link = scrapy.Field()
    desc = scrapy.Field()
```

一开始这看起来可能有点复杂，但是通过定义item， 您可以很方便的使用Scrapy的其他方法。而这些方法需要知道您的item的定义。

### 编写第一个爬虫(Spider)

Spider是用户编写用于从单个网站(或者一些网站)爬取数据的类。

其包含了一个用于下载的初始URL，如何跟进网页中的链接以及如何分析页面中的内容， 提取生成 [item](https://scrapy-chs.readthedocs.io/zh_CN/0.24/topics/items.html#topics-items) 的方法。

为了创建一个Spider，您必须继承 [`scrapy.Spider`](https://scrapy-chs.readthedocs.io/zh_CN/0.24/topics/spiders.html#scrapy.spider.Spider) 类， 且定义以下三个属性:

- [`name`](https://scrapy-chs.readthedocs.io/zh_CN/0.24/topics/spiders.html#scrapy.spider.Spider.name): 用于区别Spider。 该名字必须是唯一的，您不可以为不同的Spider设定相同的名字。
- [`start_urls`](https://scrapy-chs.readthedocs.io/zh_CN/0.24/topics/spiders.html#scrapy.spider.Spider.start_urls): 包含了Spider在启动时进行爬取的url列表。 因此，第一个被获取到的页面将是其中之一。 后续的URL则从初始的URL获取到的数据中提取。
- [`parse()`](https://scrapy-chs.readthedocs.io/zh_CN/0.24/topics/spiders.html#scrapy.spider.Spider.parse) 是spider的一个方法。 被调用时，每个初始URL完成下载后生成的 [`Response`](https://scrapy-chs.readthedocs.io/zh_CN/0.24/topics/request-response.html#scrapy.http.Response) 对象将会作为唯一的参数传递给该函数。 该方法负责解析返回的数据(response data)，提取数据(生成item)以及生成需要进一步处理的URL的 [`Request`](https://scrapy-chs.readthedocs.io/zh_CN/0.24/topics/request-response.html#scrapy.http.Request) 对象。

以下为我们的第一个Spider代码，保存在 `tutorial/spiders` 目录下的 `dmoz_spider.py` 文件中:

```
import scrapy

class DmozSpider(scrapy.Spider):
    name = "dmoz"
    allowed_domains = ["dmoz.org"]
    start_urls = [
        "http://www.dmoz.org/Computers/Programming/Languages/Python/Books/",
        "http://www.dmoz.org/Computers/Programming/Languages/Python/Resources/"
    ]

    def parse(self, response):
        filename = response.url.split("/")[-2]
        with open(filename, 'wb') as f:
            f.write(response.body)
```

```python
scrapy genspider chinanews chinanews.com #进行添加网址
```

### 爬取

进入项目的根目录，执行下列命令启动spider:

```
scrapy crawl dmoz
```

`crawl dmoz` 启动用于爬取 `dmoz.org` 的spider，您将得到类似的输出:

```
2014-01-23 18:13:07-0400 [scrapy] INFO: Scrapy started (bot: tutorial)
2014-01-23 18:13:07-0400 [scrapy] INFO: Optional features available: ...
2014-01-23 18:13:07-0400 [scrapy] INFO: Overridden settings: {}
2014-01-23 18:13:07-0400 [scrapy] INFO: Enabled extensions: ...
2014-01-23 18:13:07-0400 [scrapy] INFO: Enabled downloader middlewares: ...
2014-01-23 18:13:07-0400 [scrapy] INFO: Enabled spider middlewares: ...
2014-01-23 18:13:07-0400 [scrapy] INFO: Enabled item pipelines: ...
2014-01-23 18:13:07-0400 [dmoz] INFO: Spider opened
2014-01-23 18:13:08-0400 [dmoz] DEBUG: Crawled (200) <GET http://www.dmoz.org/Computers/Programming/Languages/Python/Resources/> (referer: None)
2014-01-23 18:13:09-0400 [dmoz] DEBUG: Crawled (200) <GET http://www.dmoz.org/Computers/Programming/Languages/Python/Books/> (referer: None)
2014-01-23 18:13:09-0400 [dmoz] INFO: Closing spider (finished)
```





