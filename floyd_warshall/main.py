from sparce_matrix import SparceMatrix
from floyd_warshall import FloydWarshall

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
    print("successors:", graph.successors(origin))


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


def print_matrix(matrix, l, c):
    for j in range(c):
        if j == 0:
            print(" "*3, f'{j:^13}', end=' ')
        else:
            print(f'{j:^13}', end=' ')
    print("\n")

    for i in range(l):
        print(i, end='   ')
        for j in range(c):
            print(f'[{matrix[j][i]:^11}]', end=' ')
        print()


# menu
option = 0
while option != -1:
    print()
    print("-1 exit")
    print("0 ADD DATA FROM FILE")
    print("1 insert a vertex")
    print("2 remove a vertex")
    print("3 summary & print")
    print("4 vertex degree")
    print("5 edge successors")
    print("6 edge predecessors")
    print("7 generate DISTANCE matrix")
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
    elif option == 7:
        n = graph.num_vertexes()
        print_matrix(FloydWarshall().run(graph), n, n)
    else:
        print("pay attention dummy!!!")
