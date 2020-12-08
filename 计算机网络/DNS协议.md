# DNS协议

域名转IP

- 中文名

  域名解析协议

- 外文名

  DNS protocol

- 作  用

  完成域名地址与IP地址的转换

## 1、 什么是DNS协议？
<1>DNS协议就是用来将域名解析到IP地址的一种协议，当然，也可以将IP地址转换为域名的一种协议。
<2>DNS协议基于UDP和TCP协议的，端口号53，用户到服务器采用UDP，DNS服务器通信采用TCP
<3>大型运营商、互联网机构等会向公众提供免费的DNS服务，例如，谷歌的8.8.8.8 8.8.4.4 阿里巴巴223.5.5.5 223.6.6.6
<4>如果DNS服务器down掉了，那么你只能通过IP地址来访问服务了。
<5>我们从以下几部分来理解DNS协议：

* 域名结构
* 域名服务器

## 2、域名结构

像Linux目录结构一样，现代因特网采用层次树状结构的命名方法，任何一个连接在因特网上的主机或路由器，都有一个唯一的层次结构的名字，该名字称为域名。域名查询

![img](https://img-blog.csdn.net/20180105145627203?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvamluOTcwNTA1/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

> 国家顶级域名：中国:cn， 美国:us，英国uk...    
>
> 通用顶级域名：com 公司企业  edu教育机构 gov政府部门  int国际组织  mil军事部门  net网络 org非盈利组织...    
>
> 反向域名：只有一个arpa，用于PTR查询（IP地址转换为域名） 。



![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1gef9bj5hfsj30se0gvwjd.jpg)



## 3、DNS污染

**网域服务器缓存污染**（DNS cache pollution），又称**域名服务器缓存投毒**（DNS cache poisoning），是指一些刻意制造或无意中制造出来的域名服务器[数据包](https://baike.baidu.com/item/数据包)，把域名指往不正确的IP地址。一般来说，在[互联网](https://baike.baidu.com/item/互联网)上都有可信赖的网域服务器，但为减低网络上的流量压力，一般的域名服务器都会把从上游的域名服务器获得的解析记录暂存起来，待下次有其他机器要求解析域名时，可以立即提供服务。一旦有关网域的局域域名服务器的缓存受到污染，就会把网域内的计算机导引往错误的服务器或服务器的网址。

某些[网络运营商](https://baike.baidu.com/item/网络运营商)为了某些目的，对[DNS](https://baike.baidu.com/item/DNS/427444)进行了某些操作，导致使用[ISP](https://baike.baidu.com/item/ISP/10152)的正常上网设置无法通过域名取得正确的IP地址。

某些国家或地区出于某些目的为了防止某网站被访问，而且其又掌握部分国际DNS根目录服务器或镜像，也会利用此方法进行屏蔽。

常用的手段有：[DNS劫持](https://baike.baidu.com/item/DNS劫持)和DNS污染。