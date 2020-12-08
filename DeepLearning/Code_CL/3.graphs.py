#!/usr/bin/env python
# coding=utf-8
import tensorflow as tf
print(tf.__version__)
import numpy as np

tf.reset_default_graph()
x = tf.placeholder(tf.float32, None)
y = tf.placeholder(tf.float32, None)
z = tf.add(x, y)

o = x * y
print(o)

with tf.Session() as sess:
    writer = tf.summary.FileWriter('./graphs/',sess.graph)
    print(sess.run([z, o], feed_dict={x : np.array([1.0, 2.0]), y : np.array([3.0, 4.0])}))
    writer.close()
