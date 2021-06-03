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
    print("vextexes:", graph.num_vertexes())
    print("edges:", graph.num_edges())
    print("density:", graph.density())
    print()
    graph.print()


def vertex_degree():
    origin = int(input("origin: "))
    print("vertex degree:", graph.vertex_degree(origin))


def successors():
    origin = int(input("origin: "))
    print("successors:", graph.successor(origin))


def predecessors():
    origin = int(input("origin: "))
    print("predecessors:", graph.predecessors(origin))


def add_from_file():
    # get path
    path = ""
    test = input("read from test.txt? y/n ")
    if(test == "y"):
        path = "test.txt"
    else:
        path = input("path = ")

    # get file
    with open(path, 'r') as f:
        for line in f:
            # get vertex
            words = line.split()
            origin, destiny, weight = words
            # insert it
            graph.insert_vertex(int(origin), int(destiny), float(weight))


# menu
option = 0
while option != -1:
    print()
    print("-1 exit")
    print("0 ADD DATA FROM FILE")
    print("1 insert an vertex")
    print("2 remove an vertex")
    print("3 summary & print")
    print("4 vertex degree")
    print("5 edge successor")
    print("6 edge predecessors")
    print()

    option = int(input("select an option: "))

    if option == 0:
        add_from_file()
    elif option == 1:
        insert_vertex()
    elif option == 2:
        remove_vertex()
    elif option == 3:
        summary_print()
    elif option == 4:
        vertex_degree()
    elif option == 5:
        successors()
    elif option == 6:
        predecessors()
    else:
        print("pay attention dummy!!!")
