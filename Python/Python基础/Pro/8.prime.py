#!/usr/bin/env python
# coding=utf-8
max_n = 200
prime = [0 for i in range(max_n + 1)]
for i in range(2, max_n) :
    if prime[i] == 0:
        prime[0] += 1
        prime[prime[0]] = i
    for j in range(1, prime[0] + 1):
        if i * prime[j] > max_n :
            break
        prime[i * prime[j]] = 1
        if i % prime[j] == 0:
            break
for i in range(1, prime[0] + 1):
    print(prime[i])
