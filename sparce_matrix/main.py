from sparce_matrix import SparceMatrix

graph = SparceMatrix()


def insert_vertex():
    origin = int(input("origin: "))
    destiny = int(input("destiny: "))
    weight = int(input("weight: "))

    graph.insert_vertex(origin, destiny, weight)


def remove_vertex():
    origin = int(input("origin: "))
    destiny = int(input("destiny: "))
    graph.remove_vertex(origin, destiny)


def summary_print():
    print("vextexes:",graph.num_vertexes())
    print("edges:",graph.num_edges())
    print("density:",graph.density())
    print(graph.edge_map)

def vertex_degree():
    origin = int(input("origin: "))
    print("vertex degree:",graph.vertex_degree(origin))

def successors():
    origin = int(input("origin: "))
    print("successors:",graph.successor(origin))

def predecessors():
    origin = int(input("origin: "))
    print("predecessors:",graph.predecessors(origin))

# menu
option = 0
while option != -1:
    print()
    print("-1 exit")
    print("0 insert an vertex")
    print("1 remove an vertex")
    print("2 summary & print")
    print("3 vertex degree")
    print("4 edge successor")
    print("5 edge predecessors")
    print()

    option = int(input("select an option: "))

    if option == 0:
        insert_vertex()
    elif option == 1:
        remove_vertex()
    elif option == 2:
        summary_print()
    elif option == 3:
        vertex_degree()
    elif option == 4:
        successors()
    elif option == 5:
        predecessors()
    else:
        print("pay attention dummy!!!")
