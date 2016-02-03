#!/usr/bin/env python
# encoding: utf-8
#  import pdb


A = [[0,1,1,1,0,0,0],[0,0,0,1,1,0,0],[0,0,0,0,0,1,0],[0,0,1,0,0,1,1],[0,0,0,1,0,0,1],[0,0,0,0,0,0,0],[0,0,0,0,0,1,0]]

def getv(G, l):
    _l = len(G)
    for x in range(_l):
        count = 0
        for y in range(_l):
            if G[y][x] == 1:
                count = 1
                break
        if x not in l and count == 0:
            return x
    #存在环
    return 'a'


def topsort(G):
    _ls = []
    for x in range(len(G)):
        z = getv(G,_ls)
        _ls.append(z)
        G[z] = [0,0,0,0,0,0,0]
    print _ls

topsort(A)
