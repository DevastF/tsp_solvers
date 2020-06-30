#!/usr/bin/python

import numpy as np
import pdb
import collections
from graph_tool.all import *
from queue import PriorityQueue

vertice_file = np.load("vertices.txt")

# budget and prices
budget_max = 150 # flight time
cost_mandatory = 50 # cost of measusuring powerline
cost_travel = 20 # cost of traveling over powerline w/o measurement
cost_switch_component = 10 # cost of switching powerlines by travelling over pylon

g = Graph(directed=False);

e_price = g.new_edge_property("int")
v_coords = g.new_vertex_property("vector<double>")
e_mandatory = g.new_edge_poperty("bool");

goal_v = None
goal_candidate_v = None


def initGraph():
    for c in vertice_file:
        v = g.add_vertex
        v_coords[v] = c

    for it in range(1,(vertice_file.shape[0]-1)/2):
        e = g.add_edge(g.vertex(it*2),g.vertex(1+it*2)) # connect lines on pylon       
        e_price[e] = 20
        e_mandatory[e] = False
        e = g.add_edge(g.vertex(it*2),g.vertex((it+1)*2)) # first powerline       
        e_price[e] = 80
        e_mandatory[e] = True
        e_mandatory.append(e);
        e = g.add_edge(g.vertex(1+it*2),g.vertex(1+(it+1)*2)) # second powerline       
        e_price[e] = 80
        e_mandatory[e] = True
        e_mandatory.append(e);

def nearestMandatoryEdge(vertice):
    dist, pred = djiskra_search(g, e_price, g.vertex(0), VisitorExample())


class VisitorExample(BFSVisitor):
    def __init__(self)
    def examine_vertex(self, v):
        global goal_candidate_v
        goal_candidate_v = v
    def edge_relaxed(self, e):
        global goal_v
        if e_mandatory[e]
            goal_v = goal_candidate_v    
            raise StopSearch()

 main():
    print("BOHICA")

if __name__ == "__main__":
    main()
