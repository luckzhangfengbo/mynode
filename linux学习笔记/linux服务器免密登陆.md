## 1.修改主机名

```
sudo vim /ect/hostname   修改主机名
```

## 2.免密登录服务器

```
$ ssh-keygen
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/20191128234502275.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTIxNjcw,size_16,color_FFFFFF,t_70)
```
$ ls -a
$ cd .ssh
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191128235256508.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTIxNjcw,size_16,color_FFFFFF,t_70)

```
~/.ssh$ cat id_rsa.pub
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191128235439619.png)

复制公钥

在另一个终端确保已经登录`pi`
输入`pwd`

由于此处初次使用，所以`cd .ssh`所以会报错`-bash: cd: .ssh: No such file or directory
`
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191128235704510.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTIxNjcw,size_16,color_FFFFFF,t_70)
此时再次输入`ssh-keygen`
再次`cd .ssh`即可
![在这里插入图片描述](https://img-blog.csdnimg.cn/20191129000041497.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTIxNjcw,size_16,color_FFFFFF,t_70)
```
~/.ssh $ ls         此处没有auauthorized_keys需要创建
~/.ssh $ vim authorized_keys 
```
之后讲之前复制的公钥放在里面

测试一下，重新连接服务器。![在这里插入图片描述](https://img-blog.csdnimg.cn/20191129000509692.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNTIxNjcw,size_16,color_FFFFFF,t_70)
ok 大功告成
