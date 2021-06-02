# an entry in the edge_map for each edge with a data_map for the vertexe's
# desntiny and weight
class SparceMatrix:

    def __init__(self):
        self.edge_map = {}

    def data_map(self, destiny, weight):
        return {
            "destiny": destiny,
            "weight": weight
        }

    def insert_vertex(self, origin: int, destiny: int, weight: float):
        if origin < 0:
            print("origin < 0")
            return

        data = self.data_map(destiny, weight)

        #create edges
        if not origin in self.edge_map:
            self.edge_map[origin] = {}
        
        if not destiny in self.edge_map:
            self.edge_map[destiny] = {}

        #create vertex
        self.edge_map[origin][destiny] = data

    def remove_vertex(self, origin: int, destiny: int):
        if not origin in self.edge_map:
            print("this origin is not there")
            return
        
        if not destiny in self.edge_map[origin]:
            print("this origin is not there")
            return
        
        self.edge_map[origin].pop(destiny)

        #remove edge case it's empty
        if not self.edge_map[origin]:
            self.edge_map.pop(origin)

    def num_vertexes(self):
        summ = 0
        for origin in self.edge_map:
            summ += len(self.edge_map[origin])
        return summ
    
    def num_edges(self):
        return len(self.edge_map)

    def density(self):
        edg = self.num_edges()
        return self.num_vertexes()/(edg*(edg-1))

    def vertex_degree(self, origin: int):
        if not origin in self.edge_map:
            print("this origin is not there")
            return
        return len(self.edge_map[origin])

    def successors(self, origin: int):
        if not origin in self.edge_map:
            print("this origin is not there")
            return

        return list(self.edge_map[origin].keys())

    def predecessors(self, origin: int):
        if not origin in self.edge_map:
            print("this origin is not there")
            return

        pred = []

        for key in self.edge_map.keys():
            if origin in self.edge_map[key]:
                pred.append(key)
        
        return pred
