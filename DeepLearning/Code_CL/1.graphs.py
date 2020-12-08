#!/usr/bin/env python
# coding=utf-8
import tensorflow as tf
a = tf.constant(3)
b = tf.constant(4)
#z = tf.add(a, b)
c = tf.constant(5)
d = tf.constant(6)
z = a + b + c + d
print(z)
with tf.Session() as sess:
    writer = tf.summary.FileWriter('./graphs', sess.graph)
    print(sess)
    result = sess.run(z)
    print(result)
    writer.close
