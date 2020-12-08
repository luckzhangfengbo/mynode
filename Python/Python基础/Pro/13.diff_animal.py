#!/usr/bin/env python
# coding=utf-8
"""多态"""

#父类
class Animal(object):
    def __init__(self, name):
        self.name = name
    
    def say(self):
        print("{} is an Animal, I Can Say".format(self.name))

#子类
class Cat(Animal):
    def say(self):
        print("{} is a cat, say 'miao~ miao~ miao~!'".format(self.name))

class Dog(Animal):
    def say(self):
        print("{} is a Dog, say 'Wang~ Wang~ Wang~!'".format(self.name))

#动物叫的函数

def Animal_say(animal):
    animal.say()

#传入Animal的实例
Animal_say(Animal('a'))
#传入Dog的实例
Animal_say(Dog('b'))
#传入Cat的实例
Animal_say(Cat('c'))
