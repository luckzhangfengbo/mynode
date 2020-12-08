#!/usr/bin/env python
# coding=utf-8
import tensorflow as tf

x1 = tf.placeholder(tf.float64)
x2 = tf.placeholder(tf.float64)

y1 = x1 + 1
y2 = x2 + 2

with tf.Session() as sess:
    writer = tf.summary.FileWriter('./graphs', sess.graph)
    print(sess)
    result1, result2 = sess.run([y1, y2], feed_dict={x1:0, x2:0}) 
    print(result1)
    print(result2)
    writer.close    
