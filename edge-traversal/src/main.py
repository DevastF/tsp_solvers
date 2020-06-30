#!/usr/bin/python

import numpy as np
import pdb
import collections
from graph_tool.all import *
from queue import PriorityQueue

V = np.load("vertices.txt")
nV = V.shape[0]
nP = nV-1

maxCost = 150

g = Graph(directed=False);

e_price = g.new_edge_property("int")
v_coords = g.new_vertex_property("vector<double>")
e_mandatory = [];

goal_v = None
goal_candidate_v = None


def initGraph():
    for c in V:
        v = g.add_vertex
        v_coords[v] = c

    for it in range(0,nP*2-2):
        e = g.add_edge(g.vertex(1+it*2),g.vertex(2+it*2))        
        e_price[e] = 20
        e = g.add_edge(g.vertex(1+it*2),g.vertex(1+(it+1)*2))        
        e_price[e] = 40
        e = g.add_edge(g.vertex(1+it*2),g.vertex(1+(it+1)*2))        
        e_price[e] = 80
        e_mandatory.append(e);
        e = g.add_edge(g.vertex(2+it*2),g.vertex(2+(it+1)*2))        
        e_price[e] = 40
        e = g.add_edge(g.vertex(2+it*2),g.vertex(2+(it+1)*2))        
        e_price[e] = 80
        e_mandatory.append(e);

def nearestMandatoryEdge(vertice):



class VisitorExample(gt.DijkstraVisitor):
    def examine_vertex(self, v):
        global goal_candidate_v
        goal_candidate_v = v
    def examine_edge(self, e):
        global goal_v
        if e_price[e] = 80
            goal_v = goal_candidate_v          
            

 main():
    print("BOHICA")

if __name__ == "__main__":
    main()
