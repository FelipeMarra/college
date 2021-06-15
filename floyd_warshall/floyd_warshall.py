class FloydWarshall:

    def __init__(self) -> None:
        pass

    def run(self, graph):
        n = graph.num_vertexes()

        # create distance matrix
        d_matrix = [[float('inf')] * n for i in range(n)]

        # run
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    dis_with_k = graph.edge_weight(
                        i, k) + graph.edge_weight(k, j)

                    if(dis_with_k < d_matrix[i][j]):
                        d_matrix[i][j] = dis_with_k
        return d_matrix
