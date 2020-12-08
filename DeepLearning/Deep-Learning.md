[TOC]

# Deep-Learning

`Deep Learning and TensorFlow`

`TensorFlow`™是一个基于[数据流编程](https://baike.baidu.com/item/数据流编程/22735640)（`dataflow` programming）的符号数学系统，被广泛应用于各类[机器学习](https://baike.baidu.com/item/机器学习/217599)（machine learning）算法的编程实现，其前身是[谷歌](https://baike.baidu.com/item/谷歌/117920)的神经网络算法库`DistBelief`

![image-20200726140841818](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726140841818.png)`AUC`（Area Under Curve）被定义为[ROC曲线](https://baike.baidu.com/item/ROC曲线)下与坐标轴围成的面积，显然这个面积的数值不会大于1。又由于`ROC`曲线一般都处于y=x这条直线的上方，所以`AUC`的取值范围在0.5和1之间。`AUC`越接近1.0，检测方法真实性越高;等于0.5时，则真实性最低，无应用价值。



![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/13291551-cf985efcac032cc1.png)![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/13291551-4f0b788202ec8d1a.png)

![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/13291551-ed00385f21ddf3f6.png)

## 1. 从数据挖掘到人工智能

### 1.1 人工智能萌芽与生长

![image-20200726142209999](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726142209999.png)

#### 1.1.1 计算机翻译系统的进化

![image-20200726143241950](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726143241950.png)

#### 1.1.2 人工智能医学专家系统

![image-20200726143813995](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726143813995.png)

#### 1.1.3 人工智能医学机器学习系统

![image-20200726143910610](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726143910610.png)

### 1.2 数据驱动的人工智能

![image-20200726144229891](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726144229891.png)

#### 1.2.1 Volume

![image-20200726144406007](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726144406007.png)

#### 1.2.2 Variety

![image-20200726144547209](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726144547209.png)

#### 1.2.3 Value

![image-20200726144627399](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726144627399.png)

####  1.2.4 Velocity

![image-20200726144709748](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726144709748.png)

#### 1.2.5 计算硬件的告诉演进

![image-20200726144757543](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726144757543.png)

#### 1.2.6 计算系统的并行化

数据中心

![image-20200726145040514](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726145040514.png)

## 2.人工智能能做什么

### 2.1 典型的数据挖掘问题

* 拟合-Regression
* 分类-Classification
* 聚类-Clustering
* 异常检测-Anomaly Detection

#### 2.1.2 拟合

![image-20200726145513535](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726145513535.png)

![image-20200726150336307](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150336307.png)

#### 2.1.2 分类

![image-20200726145547054](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726145547054.png)

![image-20200726150320647](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150320647.png)

#### 2.1.3 聚类

![image-20200726145720206](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726145720206.png)

#### 2.1.4 异常检测

![image-20200726145818575](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726145818575.png)

![image-20200726150303847](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150303847.png)

### 2.2 复杂的人工智能问题

![image-20200726150236110](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150236110.png)

## 3. 深度学习的普遍应用

### 3.1 人工智能的茁壮成长

![image-20200726150509680](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150509680.png)

#### 3.1.1 从人工神经元到深度神经网络

![image-20200726150655987](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150655987.png)

#### 3.1.2为什么要学习深度学习?

![image-20200726150945184](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150945184.png)

### 3.2 深度学习正在驱动时代的发展

![image-20200726151120694](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726151120694.png)

### 3.3 深度学习正在改变我们的生活方式

![image-20200726151538590](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726151538590.png)

![image-20200726151550630](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726151550630.png)

### 3.4 深度学习是强大的医学人工智能

![image-20200726151637205](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726151637205.png)

### 3.5 病例人工智能的图灵测试

![image-20200726151727945](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726151727945.png)

左边是机器。右边是人画出来的





## tensorflow基本概念

### Tensor and Varibale

![image-20200728124412119](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728124412926.png)

```python
import tensorflow as tf
z = tf.add(3, 4)
print(z)
sess = tf.Session()
print(sess)
result = sess.run(z)
print(result)
```

![image-20200728124828195](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728124828195.png)

### Graph and Session

#### Graph

![image-20200728125043832](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728125043832.png)

#### Session

![image-20200728125249011](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728125249011.png)

```python
a = tf.constant(3)
b = tf.constant(4)
z = tf.add(a, b)
print(z)
import tensorflow as tf
with tf.Session() as sess:
    writer = tf.summary.FileWriter('./graphs', sess.graph)
    print(sess)
    result = sess.run(z)
    print(result)
    writer.close
```

>tensorboard --logdir=./graphs --port=8008

#### TensorBoard

![image-20200728131648074](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728131648074.png)

![image-20200728131630528](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728131630528.png)

![image-20200728131712094](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728131712094.png)

![image-20200802141537746](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802141537746.png)





两个向量a = [a1, a2,…, an]和b = [b1, b2,…, bn]的点积定义为：

a·b=a1b1+a2b2+……+anbn。

```c++
#!/usr/bin/env python
# coding=utf-8
import tensorflow as tf
print(tf.__version__)
import numpy as np

tf.reset_default_graph()
x = tf.placeholder(tf.float32, None)#[None, 1000]
y = tf.placeholder(tf.float32, None)#[None, 1000]
z = tf.add(x, y)

o = x * y
print(o)

with tf.Session() as sess:
    writer = tf.summary.FileWriter('./graphs/',sess.graph)
    print(sess.run([z, o], feed_dict={x : np.array([1.0, 2.0]), y : np.array([3.0, 4.0])}))
    writer.close()

```

![image-20200802143842287](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802143842287.png)

一个加法一个乘法

### 克罗内克积

数学上，**克罗内克积**是两个任意大小的矩阵间的运算。克罗内克积是[张量积](https://baike.baidu.com/item/张量积/7540845)的特殊形式，以德国数学家利奥波德·克罗内克命名。

![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/9a11ca04ce3305ddac60890565b4a87a.svg)

 如果*A*是一个*m*×*n*的矩阵，而*B*是一个*p*×*q*的矩阵，**克罗内克积**则是一个*mp*×*nq*的[分块矩阵](https://baike.baidu.com/item/分块矩阵)



![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/ee5fe7b01d153a176997ba71b612920a.svg)





![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/ea0ed842bbe8e34a6e80603b6434ece9.svg)



## 从拟合到深度神经网络

### 拟合与优化-寻找正解

![image-20200802144529147](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802144529147.png)

数学拟合，第二定律中`a = F / m`

#### **数学模型**

![image-20200802145057763](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802145057763.png)

当成本函数最小的时候为趋近０，所以yi = h(xi)![image-20200802145349480](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802145349480.png)

因此使用二次元方式来预测，

#### **梯度下降**

梯度下降是迭代法的一种,可以用于求解最小二乘问题(线性和非线性都可以)。在求解机器学习算法的模型参数，即无约束优化问题时，梯度下降（Gradient Descent）是最常采用的方法之一，另一种常用的方法是最小二乘法。在求解损失函数的最小值时，可以通过梯度下降法来一步步的迭代求解，得到最小化的损失函数和模型参数值。反过来，如果我们需要求解损失函数的最大值，这时就需要用梯度上升法来迭代了。在机器学习中，基于基本的梯度下降法发展了两种梯度下降方法，分别为随机梯度下降法和批量梯度下降法。

![image-20200802150528235](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802150528235.png)**梯度下降法(gradient descent)**是一个[最优化](https://baike.baidu.com/item/最优化)算法，常用于机器学习和[人工智能](https://baike.baidu.com/item/人工智能/9180)当中用来递归性地逼近最小偏差模型。

举一个非常简单的例子，如求函数

![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/d28f3598a7e36298452ecfe451a35ab5.svg)

 的最小值。

利用梯度下降的方法解题步骤如下：

1、求梯度，![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/8a81c05d8c450aadab9085e9ab71d281.svg)
2、向梯度相反的方向移动![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/4675185d7b4028ecceae6b1456352cd4.svg)，如下![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/771a2ba34fe23edd9669812df6c5d16e.svg)，其中，![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/74822649bb220e0bdde84e9532b80130.svg) 为步长。如果步长足够小，则可以保证每一次迭代都在减小，但可能导致收敛太慢，如果步长太大，则不能保证每一次迭代都减少，也不能保证收敛。

3、循环迭代步骤2，直到![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/4675185d7b4028ecceae6b1456352cd4.svg) 的值变化到使得![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/ff00f7b7211e5b5454eccf5df11db931.svg)
在两次迭代之间的差值足够小，比如0.00000001，也就是说，直到两次迭代计算出来的![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/ff00f7b7211e5b5454eccf5df11db931.svg)基本没有变化，则说明此时![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/ff00f7b7211e5b5454eccf5df11db931.svg) 已经达到局部最小值了。
4、此时，输出![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/4675185d7b4028ecceae6b1456352cd4.svg)，这个![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/4675185d7b4028ecceae6b1456352cd4.svg)就是使得函数![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/ff00f7b7211e5b5454eccf5df11db931.svg)最小时的![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/4675185d7b4028ecceae6b1456352cd4.svg)的取值 。

#### **牛顿法**

![image-20200802151330296](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802151330296.png)

#### 动量的作用

![image-20200802151806253](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802151806253.png)



#### 用多少数据优化参数?

![image-20200802152821772](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802152821772.png)

![image-20200802153217774](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802153217774.png)

#### 学习速率的重要性

![image-20200802153834028](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802153834028.png)

![image-20200802154116159](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802154116159.png)



### 神经网络

#### 特征提取

![image-20200802163525078](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802163525078.png)

#### 神经元

![image-20200802163722940](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802163722940.png)

#### sigmoid和激活函数

![image-20200802164108623](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164108623.png)

#### ReLU

![image-20200802164207983](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164207983.png)

#### ReLU变种

![image-20200802164410721](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164410721.png)



#### 神经网络

![image-20200802164516539](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164516539.png)

![image-20200802164643407](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164643407.png)

![image-20200802164735315](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164735315.png)

#### 两种重要得神经网络

![image-20200802164943119](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164943119.png)

#### 正则化的目的

![image-20200802165229494](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802165229494.png)

#### 模型的容量

![image-20200802165350998](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802165350998.png)

![image-20200802165625188](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802165625188.png)

#### 修改成本函数

![image-20200802165700290](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802165700290.png)

#### Early-Stopping

![image-20200802165819192](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802165819192.png)

#### 参数共享

![image-20200802165846916](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802165846916.png)

#### 实战经验

![image-20200802170021995](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802170021995.png)



### 第一个演示拟合代码

```python
import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt 
%pylab inline

def plot_points(x, y, title_name):
    plt.title(title_name)#头标题
    plt.xlabel('x')#横坐标x
    plt.ylabel('y')#纵坐标y
    plt.scatter(x, y)#苗出点
    plt.show()#展示出来
    
def plot_line(w, b, title_name):
    plt.title(title_name)
    plt.xlabel('x')
    plt.ylabel('y')
    x = np.linspace(0.0, 2.0, num=100)
    y = w * x + b
    plt.plot(x, y)
    plt.show()
    
train_X = np.array([30.0, 40.0, 60.0, 80.0, 10.0, 120.0, 140.0])
train_Y = np.array([320.0, 360.0, 400.0, 455.0, 490.0, 560.0, 580.0])
train_X /= 100.0#缩放
train_Y /= 100.0
plot_points(train_X, train_Y, title_name = 'Training Points')#描绘

x = tf.placeholder(tf.float32, None)#x
y = tf.placeholder(tf.float32, None)#y
w = tf.Variable(np.random.randn(), name='weight')#随机的w, name方便找到
b = tf.Variable(np.random.randn(), name='bias')#随机的b
y_pred = tf.add(tf.multiply(w, x), b)#y = wx + b;
#---计算图已经完成---
#---优化---
n_samples = train_X.shape[0]#参考的个数n
cost = tf.reduce_sum(tf.pow((y_pred - y), 2)) / n_samples #成本函数
learning_rate = 0.01#优化器
optimizer = tf.train.GradientDescentOptimizer(learning_rate).minimize(cost)#通过什么方法进行优化，通过minmize进行最小化cost成本

training_epoch = 1000#训练多少个epoch
display_step = 50#每隔多少算一次loss,ｂｕｃｈａｎｇ

with tf.Session() as sess:
    sess.run(tf.initialize_all_variables())#所有的参数初始化
    for epoch in range(training_epoch):
        for (x_train, y_train) in zip(train_X, train_Y):
            _, loss, current_w, current_b = sess.run([optimizer, cost, w, b], feed_dict={x: x_train, y: y_train})
        if epoch % display_step == 0:
            print('Iteration: %04d | Loss: %.6f | W:%.6f | b: %.6f'
                 %(epoch + 1, loss, current_w, current_b))
            plot_line(current_w, current_b, 'Model Paramenter')
    print('Training loss: %.6f | w: %.6f | b: %.6f' % (loss, sess.run(w), sess.run(b)))
```

## 实战深度神经网络

### 1.MNIST数据集的概念

![image-20200809141619050](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809141619050.png)

### 2.MNIST数据集功能

![image-20200809142227056](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809142227056.png)



### 3.MNIST数据集组成

![image-20200809142412333](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809142412333.png)

![image-20200809142519147](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809142519147.png)

![image-20200809142558268](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809142558268.png)

![image-20200809142707444](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809142707444.png)

![image-20200809142741891](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809142741891.png)

![image-20200809143121625](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809143121625.png)

### 手写体识别实战小例子

![image-20200809151210999](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809151210999.png)

![image-20200809151426448](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809151426448.png)

![image-20200809164540984](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809164540984.png)

![image-20200809164559312](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809164559312.png)

![image-20200809164704413](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809164704413.png)

![image-20200809164720735](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809164720735.png)

![image-20200809164827434](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809164827434.png)

![image-20200809165015421](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809165015421.png)

![image-20200809165045371](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809165045371.png)



`softmax归一化:`

![image-20200809152513190](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809152513190.png)

`cross_entropy:`

![cross_entropy](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809153513092.png)

<img src="http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809153748945.png" alt="image-20200809153748945" style="zoom:50%;" />

当Y = 1时，Y<sub>pred</sub>接近于0的时候loss很大



### 完整代码

```python
import sys
sys.path.append('.')
import tensorflow as tf
import numpy as np
import input_data
import matplotlib.pyplot as plt 
%pylab inline
mnist = input_data.read_data_sets('./MNIST_data/', one_hot=True)

def imshow(img):
    plt.imshow(np.reshape(img,[28, 28]))
    plt.show()
    
for index in range(10):
    print(mnist.train.images[index].shape)
    print(mnist.train.labels[index])
    print(np.nonzero(mnist.train.labels[index])[0])
    imshow(mnist.train.images[index])
    
    
def weight_variable(shape):
    initial = tf.truncated_normal(shape, stddev=0.1)
    return tf.Variable(initial)

def bias_variable(shape):
    initial = tf.constant(0.1, shape=shape)
    return tf.Variable(initial)

x = tf.placeholder(tf.float32, [None, 784])
W_fc1 = weight_variable([784, 200])
b_fc1 = bias_variable([200])
W_fc2 = weight_variable([200, 200])
b_fc2 = bias_variable([200])
W_out = weight_variable([200, 10])
b_out = bias_variable([10])
hidden_1 = tf.nn.relu(tf.matmul(x, W_fc1) + b_fc1)
hidden_2 = tf.nn.dropout(tf.nn.relu(tf.matmul(hidden_1, W_fc2) + b_fc2), 0.5)#tf.nn.dropout()防止过拟合
y = tf.nn.softmax(tf.matmul(hidden_2, W_out) + b_out)

y_ = tf.placeholder(tf.float32, [None, 10])
correct_prediction = tf.equal(tf.argmax(y, 1), tf.argmax(y_, 1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
cross_entropy = -tf.reduce_mean(tf.reduce_sum(y_ * tf.log(y), reduction_indices=[1]))
train_step = tf.train.GradientDescentOptimizer(0.05).minimize(cross_entropy)
#什么方法进行优化，通过minmize进行最小化cost成本

training_iteration = 10000
batch_size = 100
display_step = 50
tf.summary.scalar('loss', cross_entropy)
tf.summary.scalar('accuracy', accuracy)
merged = tf.summary.merge_all()
with tf.Session() as sess:
    writer = tf.summary.FileWriter('./neural_network/', sess.graph)
    sess.run(tf.initialize_all_variables())#所有的参数初始化
    for iteration in range(training_iteration):
        batch_xs, batch_ys = mnist.train.next_batch(batch_size)
        _, current_accuracy, summary = sess.run([train_step, accuracy, merged], feed_dict={x: batch_xs, y_:batch_ys})
        
        writer.add_summary(summary, iteration)
        if iteration % display_step == 0:
            print('Iteration: %5d | Accuracy: %.6f' % (iteration + 1, current_accuracy))
    
    print('Test accuracy: %.6f' % (sess.run(accuracy, feed_dict={x: mnist.test.images, y_ : mnist.test.labels})))
    writer.close()
```





## Dropout

<font color = red> Materials</font>

### Background

![image-20200809162555147](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809162555147.png)

![image-20200809162745822](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809162745822.png)

![image-20200809162903247](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809162903247.png)

![image-20200809163038746](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809163038746.png)

丢掉一些神经元后

![image-20200809163157607](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809163157607.png)

扔掉结点的概率

![image-20200809163300100](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809163300100.png)

0.5的时候能保留也能扔掉

![image-20200809163415445](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809163415445.png)

加过dropout后的错误率降低

![image-20200809163445355](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809163445355.png)

![image-20200809163546983](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809163546983.png)

加过dropout后右肉眼可见

![image-20200809163653458](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809163653458.png)

分布更集中了

![image-20200809163710082](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809163710082.png)

一般在最后一层加入dropout

![image-20200809163734384](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200809163734384.png)

## 卷积神经网络

### 2.1 CNN的主机特征提取

![image-20200816141314513](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816141314513.png)

对于提取的时候对于人非常容易,轮廓信息等,CNN提取的是低级的信息,高层去提取一些高级的细节,整个神经网络在精细化特征,更加接近预测的特征,神经网络就是完成特征的提取,CNN所完成的事情

#### 2.2.1 卷积是什么

![image-20200816141747410](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816141747410.png)

根据激励信号对原始信号的处理(滤波)的运算.

#### 2.2.2 图像的卷积

![image-20200816142306445](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816142306445.png)

![image-20200816142013863](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816142013863.png)

绿色原始,黄色参数,得出粉丝 

进行特征提取

使得原图少了两个维度

### 2.3 CNN的本质

![image-20200816142355712](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816142355712.png)

提取出轮廓

#### 2.3.1 卷积层

![image-20200816143043076](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816143043076.png)

四个卷积核

作用在原始图像山得到特征提取的道德一幅图像,大小几乎相同

feature map是与卷积核个数是相同的

#### 2.3.1 下采样层

![image-20200816144118592](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816144118592.png)

常用的是`Max Pooling`

### 2.4 CNN的据本单位--卷积层

![image-20200816144436232](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816144436232.png)

### 2.5 CNN结构的演化

![image-20200816144552410](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816144552410.png)

### 2.6 CNN的广泛应用

![image-20200816144728644](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816144728644.png)

### 实战

![image-20200816144436232](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816144436232.png)

28*28图像

![image-20200816150312861](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816150312861.png)

卷积核`5*5 16`个

`2*2`维度的`pool`

`7*7*32`拉成`10`维度的输出





```python
import sys
sys.path.append('.')
import tensorflow as tf
import numpy as np
import input_data
mnist = input_data.read_data_sets('./MNIST_data/', one_hot=True)
def weight_variable(shape):
    initial = tf.truncated_normal(shape, stddev=0.1)
    return tf.Variable(initial)

def bias_variable(shape):
    initial = tf.constant(0.1, shape=shape)
    return tf.Variable(initial)

def conv2d(layer, W):
    return tf.nn.conv2d(layer, W, strides=[1, 1, 1, 1], padding = 'SAME')

def max_pooling_2x2(layer):
    return tf.nn.max_pool(layer, ksize=[1, 2, 2, 1], strides=[1, 2, 2, 1], padding = 'SAME')

x = tf.placeholder(tf.float32, [None, 784])
y_ = tf.placeholder(tf.float32, [None, 10])
W_conv1 = weight_variable([5, 5, 1, 16])#RGB: Channel = 3
b_conv1 = bias_variable([16]);

W_conv2 = weight_variable([5, 5, 16, 32])
b_conv2 = bias_variable([32]);

x_image = tf.reshape(x, [-1, 28, 28, 1])#变成图像

h_conv1 = tf.nn.relu(conv2d(x_image, W_conv1) + b_conv1)#先输入卷积后激活
h_pool1 = max_pooling_2x2(h_conv1)#输入pooling卷基层

h_conv2 = tf.nn.relu(conv2d(h_pool1, W_conv2) + b_conv2)#先卷积后激活
h_pool2 = max_pooling_2x2(h_conv2)

h_pool2_flat = tf.reshape(h_pool2, [-1, 7*7*32])

W_fc1 = weight_variable([7 * 7 * 32, 256])
b_fc1 = bias_variable([256])

W_fc2 = weight_variable([256, 10])
b_fc2 = bias_variable([10])

h_fc1 = tf.nn.relu(tf.matmul(h_pool2_flat, W_fc1) + b_fc1)
h_fc2 = tf.nn.relu(tf.matmul(h_fc1, W_fc2) + b_fc2)
y = tf.nn.softmax(h_fc2)

correct_prediction = tf.equal(tf.argmax(y, 1), tf.argmax(y_, 1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
cross_entropy = -tf.reduce_mean(tf.reduce_sum(y_ * tf.log(y), reduction_indices=[1]))
train_step = tf.train.AdamOptimizer(1e-4).minimize(cross_entropy)

training_iteration = 10000
batch_size = 50
display_step = 100
tf.summary.scalar('loss', cross_entropy)
tf.summary.scalar('accuracy', accuracy)
merged = tf.summary.merge_all()
with tf.Session() as sess:
    writer = tf.summary.FileWriter('./cnn/', sess.graph)
    sess.run(tf.initialize_all_variables())#所有的参数初始化
    for iteration in range(training_iteration):
        batch_xs, batch_ys = mnist.train.next_batch(batch_size)
        _, current_accuracy, summary = sess.run([train_step, accuracy, merged], feed_dict={x: batch_xs, y_:batch_ys})
        
        writer.add_summary(summary, iteration)
        if iteration % display_step == 0:
            print('Iteration: %5d | Accuracy: %.6f' % (iteration + 1, current_accuracy))
    
    print('Test accuracy: %.6f' % (sess.run(accuracy, feed_dict={x: mnist.test.images, y_ : mnist.test.labels})))
    writer.close()
```



### 3. 识别肠腺瘤

#### 3.1 训练数据

![image-20200816155557888](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816155557888.png)

#### 3.2 训练数据预处理

3.2.1 生成训练图像对

![image-20200816155842953](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816155842953.png)

#### 3.2.2 训练样本分布

#### 3.4深度学习的流水线

![image-20200816160246060](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816160246060.png)

#### 4.2 测试结果 

![image-20200816160405050](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816160405050.png)

![image-20200816160809338](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816160809338.png)

#### 4.3 感受野对诊断的影响

![image-20200816161039250](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200816161039250.png)



## 循环神经网络

`语音识别`

### 参数共享

![image-20200823143803594](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200823143803594.png)

### RNN与CNN

![image-20200823144052559](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200823144052559.png)

### 循环神经网络(RNN)

![image-20200823144829195](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200823144829195.png)

### 时间维度的重要性

### RNN的结构

![image-20200823145118298](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200823145118298.png)

### 其他RNN结构

![image-20200823145807804](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200823145807804.png)

### 隐藏层的类型

![image-20200823145914584](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200823145914584.png)

### RNN的应用

![image-20200823150243249](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200823150243249.png)

### 机器翻译

![image-20200823150406705](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200823150406705.png)