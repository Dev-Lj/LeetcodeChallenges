class Solution(object):
    def build_graph(self, prerequisites):
        graph = {}
        for (key,val) in prerequisites:
            if key not in graph.keys():
                graph[key] = []
            graph[key].append(val)
        return graph

    def graph_has_circles(self, graph, unvisited, current, visited):
        if current in visited:
            return True

        if current in unvisited:
            next_keys = graph[current]
            unvisited.remove(current)
            visited.append(current)
            for next in next_keys:
                mylevel_visited = visited.copy()
                mylevel_unvisited = unvisited.copy()
                has_circle = self.graph_has_circles(graph, mylevel_unvisited, next, mylevel_visited)
                if has_circle:
                    return True
        return False

    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        if len(prerequisites) == 0:
            return True

        graph = self.build_graph(prerequisites)
        unvisited = list(graph.keys())
        while len(unvisited)>0:
            current = unvisited[0]
            has_circles = self.graph_has_circles(graph, unvisited, current, [])
            if has_circles:
                return False
        return True

sol = Solution()

# numCourses = 2
# prerequisites = [[1,0]]
# print(sol.canFinish(numCourses, prerequisites))

# numCourses = 2
# prerequisites = [[1,0],[0,1]]
# print(sol.canFinish(numCourses, prerequisites))

# numCourses = 2
# prerequisites = [[1,0],[2,1],[0,2]]
# print(sol.canFinish(numCourses, prerequisites))

# numCourses = 20
# prerequisites = [[0,10],[3,18],[5,5],[6,11],[11,14],[13,1],[15,1],[17,4]]
# print(sol.canFinish(numCourses, prerequisites))

# numCourses = 3
# prerequisites = [[1,0],[1,2],[0,1]]
# print(sol.canFinish(numCourses, prerequisites))

numCourses = 7
prerequisites = [[1,0],[0,3],[0,2],[3,2],[2,5],[4,5],[5,6],[2,4]]
print(sol.canFinish(numCourses, prerequisites))