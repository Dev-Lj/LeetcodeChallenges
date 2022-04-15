from itertools import compress


class Solution(object):
    def dfs_is_safe(self, currentNode, graph, branch, result):
        if len(graph[currentNode]) == 0:
            result[currentNode] = True
            return True

        if result[currentNode]:
            return True

        if currentNode in branch:
            return False

        branch.append(currentNode)

        colpos = 0
        is_safenode = True

        while is_safenode and colpos < len(graph[currentNode]):
            is_safenode = self.dfs_is_safe(graph[currentNode][colpos], graph, branch, result)
            colpos += 1

        if is_safenode:
            result[currentNode] = True
        return is_safenode

    def eventualSafeNodes(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[int]
        """
        result = [False for _ in range(0,len(graph))]

        for i in range(0, len(graph)):
            branch = []
            self.dfs_is_safe(i, graph, branch, result)
        
        return list(compress(range(0,len(graph)), result))

        