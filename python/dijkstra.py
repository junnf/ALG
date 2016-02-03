#!/usr/bin/env python
# encoding: utf-8

_pragh = [[],
        [{2:2},{4:1}],
        [{4:3},{5:10}],
        [{1:4},{6:5}],
        [{3:2},{5:2},{6:8},{7:4}],
        [{7:6}],
        [],
        [{6:1}]
        ]
def get_vertex(G, v):
    return [ x.keys()[0] for x in G[v] ]

def dijkstra(G):
    _G = []
    _len = len(G) - 1
    for i in range(_len):
        _G.append([{'k':0},{'d':100000},{'p':0}])
    #0=vertex[i]-1
    i=1
    _G[i-1][0]['k'] = 1
    for j in get_vertex(G,i):
        _G[j-1][1]['d'] = G[i][]

