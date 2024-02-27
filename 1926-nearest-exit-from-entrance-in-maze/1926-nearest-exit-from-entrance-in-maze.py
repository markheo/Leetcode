class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        from collections import deque
        m = len(maze)
        n = len(maze[0])
        
        q = deque([(entrance[0], entrance[1], 0)])  # (x, y, distance)
        maze[entrance[0]][entrance[1]] = "+"  # 시작점을 방문한 것으로 표시
        
        while q:
            x, y, dist = q.popleft()
            # 탈출 조건 (1) x,y 중 하나라도 끝에 도달하고 (2) 출발점으로 되돌아온게 아니라면
            if (x == 0 or y == 0 or x == m-1 or y == n-1) and (x, y) != (entrance[0], entrance[1]):
                return dist
            
            for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and maze[nx][ny] == ".":
                    maze[nx][ny] = "+"  # 방문한 위치 표시
                    q.append((nx, ny, dist + 1))
        
        return -1  # 탈출구에 도달할 수 없는 경우