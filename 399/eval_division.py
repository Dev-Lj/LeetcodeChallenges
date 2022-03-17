class Solution(object):
    def build_graph(self, equations, values):
        graph = {}
        for idx, eq in enumerate(equations):
            val = values[idx]
            if eq[0] not in graph:
                graph[eq[0]] = {eq[0]: 1}
            if eq[1] not in graph:
                graph[eq[1]] = {eq[1]: 1}

            graph[eq[0]][eq[1]] = val
            graph[eq[1]][eq[0]] = 1/val            

        return graph

    def d_first_search(self, graph, current, target, weight, checkednodes):
        if current == target:
            return weight
        for node, edge_weight in graph[current].items():
            if node == current or node in checkednodes:
                continue
            val = weight * edge_weight
            checkednodes.append(current)
            tree_weight = self.d_first_search(graph, node, target, val, checkednodes)
            if tree_weight != -1.0:
                return tree_weight

        return -1.0
            

    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        graph = self.build_graph(equations, values)
        result = []
        for (dividend, divisor) in queries:
            if dividend in graph.keys() and divisor in graph.keys():
                result.append(self.d_first_search(graph, dividend, divisor, 1, [dividend]))
                continue
            result.append(float(-1))
        return result 

sol = Solution()
equations = [["a","b"],["b","c"],["bc","cd"]]
values = [1.5,2.5,5.0]
queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
print('expected: [3.75,0.4,5.0,0.2] \nactual: ', sol.calcEquation(equations, values, queries))
print('------------------------------------------------------------------')
# equations = [["a","b"]]
# values = [0.5]
# queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
# print('expected: [3.75,0.4,5.0,0.2] \nactual: ', sol.calcEquation(equations, values, queries))
# print('------------------------------------------------------------------')
equations = [["a","e"],["b","e"]]
values = [4.0,3.0]
queries = [["a","b"],["e","e"],["x","x"]]
print('expected: [1.33333,1.00000,-1.00000] \nactual: ', sol.calcEquation(equations, values, queries))
print('------------------------------------------------------------------')
equations = [["a","b"],["e","f"],["b","e"]]
values = [3.4,1.4,2.3]
queries = [["b","a"],["a","f"],["f","f"],["e","e"],["c","c"],["a","c"],["f","e"]]
print('expected: [0.29412,10.94800,1.00000,1.00000,-1.00000,-1.00000,0.71429] \nactual: ', sol.calcEquation(equations, values, queries))
print('------------------------------------------------------------------')
equations = [["a","b"],["c","b"],["d","b"],["w","x"],["y","x"],["z","x"],["w","d"]]
values = [2.0,3.0,4.0,5.0,6.0,7.0,8.0]
queries = [["a","c"],["b","c"],["a","e"],["a","a"],["x","x"],["a","z"]]
print('expected: [0.66667,0.33333,-1.00000,1.00000,1.00000,0.04464] \nactual: ', sol.calcEquation(equations, values, queries))
print('------------------------------------------------------------------')
equations = [["a","b"],["b","c"],["a","c"],["d","e"]]
values = [2.0,3.0,6.0,1.0]
queries = [["a","c"],["b","c"],["a","e"],["a","a"],["x","x"],["a","d"]]
print('expected: [0.66667,0.33333,-1.00000,1.00000,1.00000,0.04464] \nactual: ', sol.calcEquation(equations, values, queries))
print('------------------------------------------------------------------')