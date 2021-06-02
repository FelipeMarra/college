# an entry in the edge_map for each edge with a data_map for the desntiny
# and weight
class SparceMatrix:

    def __init__(self):
        self.edge_map = {}

    def data_map(self, destiny, weight):
        return {
            "destiny": destiny,
            "weight": weight
        }

    def insert(self, origin: int, destiny: int, weight: float):
        if origin < 0:
            print("origin < 0")
            return

        data = self.data_map(destiny, weight)

        if not origin in self.edge_map:
            self.edge_map[origin] = {}

        self.edge_map[origin][destiny] = data
