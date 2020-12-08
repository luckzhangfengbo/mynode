#!/usr/bin/env python
# coding=utf-8
import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
%pylab inline
def plot_points(x, y, title_name)
    plt.title(title_name)
    plt.xlabel('x')
    plt.ylabel('y')
    plt.scatter(x, y)
    plt.show()
train_x = np.array([30.0, 40.0, 60.0, 80.0, 10.0, 120.0, 140.0])
train_y = np.array([320.0, 360.0, 400.0, 455.0, 490.0, 560.0, 580.0])
train_x /= 100.0
train_y /= 100.0

