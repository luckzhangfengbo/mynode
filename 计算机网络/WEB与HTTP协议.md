# WEB与HTTP协议

## WEB术语

* web页面(web page, 文档)
* 对象(爬虫中...)
* HTML基本文件
* URL(统一资源应用符)
* web浏览器
* web服务器(阿帕奇)

## HTTP的请求-响应行为

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1geec3wg24rj30k00b60xn.jpg)

不用关注tcp,不关注丢失

## 非持续链接和持续链接

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1geec7p115lj30ms08743v.jpg)

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1geec976uekj30mp0ezgoz.jpg)

## 请求方法

>GET
>
>POST//提交表单
>
>HEAD//测试的
>
>PUT//上传
>
>DELETE//删除

![img](https://images2018.cnblogs.com/blog/1418466/201808/1418466-20180810112625596-2103906128.png)

## HTTP常见的状态码

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1geecf1t6gaj30cx05c75h.jpg)

永久移动

错误的请求

|      | 类别                             | 原因短语                   |
| ---- | -------------------------------- | -------------------------- |
| 1XX  | Informational（信息性状态码）    | 接受的请求正在处理         |
| 2XX  | Success（成功状态码）            | 请求正常处理完毕           |
| 3XX  | Redirection（重定向状态码）      | 需要进行附加操作以完成请求 |
| 4XX  | Client Error（客户端错误状态码） | 服务器无法处理请求         |
| 5XX  | Server Error（服务器错误状态码） | 服务器处理请求出错         |

**200** OK 当您的操作将在响应正文中返回数据时，出现此结果。

**204** No Content 当您的操作成功，但不在响应正文中返回数据时，出现此结果。

**304** Not Modified（重定向） 当测试实体自上次检索以来是否被修改时，出现此结果。

**403** Forbidden  客户端错误

**401** Unauthorized 客户端错误

**413** Payload Too Large（客户端错误） 当请求长度过长时，出现此结果。

**400** BadRequest（客户端错误） 当参数无效时，出现此结果。

**404** Not Found（客户端错误） 当资源不存在时，出现此结果。

**405** Method Not Allowed（客户端错误）由于方法和资源组合不正确而出现此错误。 例如，您不能对一个实体集合使用 DELETE 或 PATCH。

**412** Precondition Failed 客户端错误

**501** Not Implemented（服务器错误） 当未实施某个请求的操作时，出现此结果。

**503** Service Unavailable（服务器错误） 当 Web API 服务不可用时，出现此结果。



## 用户与服务器交互--COOKIE

 HTTP是一个无状态协议，即HTTP服务器并不保存关于客户的任何信息，假如某个特定的客户在短短的几秒钟内两次请求同一个对象，服务器并不会因为刚刚为该客户提供了该对象就不再做出反应，而是重新发送该对象。 HTTP的无状态性简化了服务器的设计，并且允许工程师们去开发可以同时处理数以千计的TCP连接的高性能Web服务器。  然而一个Web站点通常希望能够识别用户，可能是因为服务器希望限制用户的访问，或者它希望把内容与用户身份联系起来。为此，HTTP使用了cookie

![image-20200502194925335](/home/fangsong/.config/Typora/typora-user-images/image-20200502194925335.png)

加入登录后访问后信息类似泄露，推荐相似商品，自动登录等，精确营销cookie



## WEB缓存器(代理服务器)

缓存指的是将需要频繁访问的网络内容存放在离用户较近、访问速度更快的系统中，以提高内容访问速度的一种技术。缓存服务器就是存放频繁访问内容的服务器。

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1geecsf3t5rj30ia08pmzn.jpg)

Web缓存可以根据不同等级进行配置：

本地缓存：将Web对象缓存的拷贝保存在本地计算机中。大多数流行的Web浏览器默认情况下保留一个先前访问对象的缓存。例如，Internet Explorer称之为“临时Internet文件”。本地缓存拷贝只是在用户频繁地从同一台机器访问页面时有用。

代理缓存：代理服务器是为公司内的多个用户/客户计算机缓存Web对象的单独机器。它们是位于客户端和托管的Web服务器之间的计算机，而且它们比本地缓存效率更高，因为在企业本地网络中的任何用户或计算机访问某个Web对象时，缓存拷贝对想访问该对象的任何其他用户/计算机是可用的，无需到Internet服务器上再次下载它。代理缓存可以在网络边缘与防火墙结合使用。

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1geed0iw25jj30hs03zjt3.jpg)