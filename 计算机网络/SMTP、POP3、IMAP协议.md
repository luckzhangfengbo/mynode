# SMTP、POP3、IMAP协议

电子邮件协议

## SMTP简单邮件传输协议

SMTP的全称是“Simple Mail Transfer Protocol”，即简单邮件传输协议（25号端口）。它是一组用于从源地址到目的地址传输邮件的规范，通过它来控制邮件的中转方式。SMTP 协议属于 TCP/IP 协议簇，它帮助每台计算机在发送或中转信件时找到下一个目的地。

　　SMTP是一个“推”的协议，它不允许根据需要从远程服务器上“拉”来消息。SMTP服务器就是遵循SMTP协议的发送邮件服务器，SMTP认证就是要求必须在提供了账户名和密码之后才可以登录 SMTP 服务器，这就使得那些垃圾邮件的散播者无可乘之机。

SMTP已是事实上的E-Mail传输的标准。

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1gef8wjqpiaj30ry07wn0a.jpg)



##  IMAP

　　IMAP全称是Internet Mail Access Protocol，即交互式邮件访问协议，是一个应用层协议（端口是143）。用来从本地邮件客户端（Outlook Express、Foxmail、Mozilla Thunderbird等）访问远程服务器上的邮件。

## POP3

　　POP3是Post Office Protocol 3的简称，即邮局协议的第3个版本，是TCP/IP协议族中的一员（默认端口是110）。本协议主要用于支持使用客户端远程管理在服务器上的电子邮件。