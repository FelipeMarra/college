from sparce_matrix import SparceMatrix

graph = SparceMatrix()


def insert():
    origin = int(input("origin: "))
    destiny = int(input("destiny: "))
    weight = int(input("weight: "))

    graph.insert(origin, destiny, weight)


def summary_print():
    print(graph.edge_map)


# menu
option = 0
while option != -1:
    print()
    print("-1 exit")
    print("0 insert an edge")
    print("1 summary or print")
    print()

    option = int(input("select an option: "))

    if option == 0:
        insert()
    elif option == 1:
        summary_print()
    else:
        print("pay attention dummy!!!")
