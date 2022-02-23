# https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution(object):
    def minCostConnectPoints(self, points):
        visited_idxs = [0]
        graph = {}
        cost = 0

        for idxA, pointA in enumerate(points):
            graph[idxA] = []
            for idxB, pointB in enumerate(points):
                if idxA == idxB:
                    continue
                graph[idxA].append(tuple([abs(pointA[0] - pointB[0]) + abs(pointA[1] - pointB[1]), idxB]))

        frontiers = {}

        while len(visited_idxs) < len(points):
            neighbours = graph[visited_idxs[-1]]
            for neighbour in neighbours:
                if neighbour[1] in visited_idxs:
                    continue

                if neighbour[1] in frontiers.keys():
                    if neighbour[0] < frontiers[neighbour[1]]:
                        frontiers[neighbour[1]] = neighbour[0]
                else:
                    frontiers[neighbour[1]] = neighbour[0]
            next_node_idx = min(frontiers, key = frontiers.get)
            cost += frontiers[next_node_idx]
            visited_idxs.append(next_node_idx)
        return cost
 

sol = Solution()
print(sol.minCostConnectPoints([[0,0],[2,2],[3,10],[5,2],[7,0]]))

points = [[0,0],[1,1],[1,0],[-1,1]]
print(sol.minCostConnectPoints(points))