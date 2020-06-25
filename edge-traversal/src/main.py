#!/usr/bin/python

import numpy as np
import pdb
import collections
from queue import PriorityQueue

V = np.load("vertices.txt")
nV = V.shape[0]
nP = nV-1

Mm = np.zeros((nV,nV))
Mf = np.zeros((nV,nV))

Mf[0][3] = 1;

for i in range(0, nP):
    Mf[1+i*(nP-1)][nP-1+i*(nP-1)]=20
    Mf[1+i][1+2*(i+1)]=40
    Mm[1+i][1+2*(i+1)]=80

graph = {};

graph.

def findNearestMandatoryEdge(vertex):
   q = PriorityQueue()

   


def main():
    print("BOHICA")

if __name__ == "__main__":
    main()
