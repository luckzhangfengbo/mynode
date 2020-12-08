#!/usr/bin/env python
# coding=utf-8

import requests
src = "https://imgsa.baidu.com/forum/wh%3D144%2C90/sign=c1e4b2dbe2cd7b89e93932823b106e9e/f66fc65c10385343ee1135309713b07ecb80888e.jpg"
response = requests.get(src)
with open('./data/tieba/images/1.jpg', "wb") as file:
    file.write(response.content)
