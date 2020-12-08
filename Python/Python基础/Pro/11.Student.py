#!/usr/bin/env python
# coding=utf-8

class Student(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def show(self):
        print("%s : %d" % (self.name, self.age))

stu1 = Student('jack', 22)
stu2 = Student('bob', 21)
stu1.show()
stu2.show()

