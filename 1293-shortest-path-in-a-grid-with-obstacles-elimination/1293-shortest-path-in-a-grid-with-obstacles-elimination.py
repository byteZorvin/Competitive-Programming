class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        q = collections.deque([[0, 0, k]]) # row, col, no of obstacle rem
        vis = {(0, 0): 0}
        steps = 0
        
        while q:
            size = len(q)
            for _ in range(size): 
                r, c, obsLeft = q.popleft()
                if (r < 0 or c<0 or r>=m or c >= n or obsLeft < 0): 
                    continue
                if (r == m-1 and c == n-1):
                    return steps
                if (grid[r][c] == 1):
                    obsLeft -= 1
                for r2, c2 in [[r, c-1], [r-1, c], [r+1, c], [r, c+1]]: 
                    if(vis.get((r2, c2), -1) >= obsLeft):
                        continue
                    vis[(r2, c2)] = obsLeft
                    q.append([r2, c2, obsLeft])
            steps += 1
            
        return -1
        
        