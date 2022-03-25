class Solution(object):
    def dfs_remove_adjacent_land(self, grid, x, y, len_x, len_y):
        if x >= 0 and y >= 0 and x < len_x and y < len_y and grid[y][x] == "1":
            grid[y][x] = "#"
        else:
            return
        # right
        self.dfs_remove_adjacent_land(grid, x + 1, y, len_x, len_y)
        # left
        self.dfs_remove_adjacent_land(grid, x - 1, y, len_x, len_y)
        # down
        self.dfs_remove_adjacent_land(grid, x , y + 1, len_x, len_y)
        # up
        self.dfs_remove_adjacent_land(grid, x , y - 1, len_x, len_y)
        



    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        grid_y_len = len(grid)
        grid_x_len = len(grid[0])

        amount_islands = 0

        for y in range(grid_y_len):
            for x in range(grid_x_len):
                if grid[y][x] == "1":
                    amount_islands +=1
                    self.dfs_remove_adjacent_land(grid, x, y, grid_x_len, grid_y_len)
        
        return amount_islands

sol = Solution()
grid = [
    ["1","1","1"],
    ["0","1","0"],
    ["1","1","1"]
]
print(sol.numIslands(grid)) #1