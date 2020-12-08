# TCP的拥塞控制

在某段时间，若**对网络中某一资源的需求超过了该资源所能提供的可用部分，网络性能就要变坏**，这种情况就叫做**网络拥塞**。

若**出现拥塞而不进行控制**，整个网络的**吞吐量将随输入负荷的增大而下降**。

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190731190238241.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxNDMxNDA2,size_16,color_FFFFFF,t_70)

TCP的四种拥塞控制算法
1.慢开始
2.拥塞控制
3.快重传
4.快恢复

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190731155254165.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxNDMxNDA2,size_16,color_FFFFFF,t_70)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190731184314574.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxNDMxNDA2,size_16,color_FFFFFF,t_70)

![image-20200506164546639](../../../.config/Typora/typora-user-images/image-20200506164546639.png)

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190731184935595.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQxNDMxNDA2,size_16,color_FFFFFF,t_70)